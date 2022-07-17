#include <string>

using namespace std;
/*
1. VCARD type below has to represent the original VCard 3.0. However, you may find
few attributes whose types are generalized to the type. And for those attributes, the 
value that follows PREF is considered.

2. Original VCard 3.0 has 32 attributes. For some reasons, not all are 
incorporated while contructing the below VCARD type.
AGENT
CLASS
KEY
LOGO
PHOTO
SOUND
SOURCE
X-

3. For ease, attribute names are same as the ones 
found in original specification.
*/

struct VCARD
{
	string	FN;			//This type MUST be included in a vCard object.
	string	N[5];		//This type MUST be included in a vCard object. ; Family; Given; Middle; Prefix; Suffix
	string	TEL[3];		//"HOME" , "WORK" , "CELL"
	string	EMAIL;		//Only email parameters allowed
};

struct DEPR_VCARD	//NOT USED
{
string	NAME;		 //No parameters allowed
string	PROFILE;	 //No parameters allowed. Value MUST be the case insensitive value "VCARD
string	FN;			 //This type MUST be included in a vCard object.
string	N;			 //This type MUST be included in a vCard object. ; Family; Given; Middle; Prefix; Suffix
string	NICKNAME;	 //Text parameters allowed
string	BDAY;		 //Only value (date-time) parameter allowed
string	ADR;		 //Only adr and text parameters allowed
string	LABEL;		 //Only adr and text parameters allowed
string	TEL[6];		 //"HOME" , "WORK" , "PREF" , "VOICE" , "FAX" , "MSG"  , "CELL" , "PAGER" , "BBS" , "MODEM" , "CAR" , "ISDN"  , "VIDEO" , "PCS" , iana-token , x-name  ; Values are case insensitive
string	EMAIL;		 //Only email parameters allowed
string	MAILER;		 //Only text parameters allowed
string	TZ;			 //No parameters allowed
double	GEO;         //No parameters allowed
string	TITLE;       //Only text parameters allowed
string	ROLE;        //Only text parameters allowed
string	ORG;         //First is Organization Name, remainder (delimited with ;) are Organization Units.
string	CATEGORIES;  //Only text parameters allowed
string	NOTE;        //Only text parameters allowed
string	PRODID;      //No parameters allowed
string	REV;         //Values are case insensitive.
string	SORT_STRING; //Only text parameters allowed
string	UID;         //No parameters allowed
string	URL;         //No parameters allowed
string	VERSION;     //This type MUST be included in a vCard object.  No parameters allowed. Value MUST be "3.0"
};




/*
;*******************************************
 ; vCard Type Definition
 ;
 ; Provides type-specific definitions for how the
 ; "value" and "param" are defined.
 ;*******************************************
Dawson & Howes Standards Track [Page 29]
RFC 2426 vCard MIME Directory Profile September 1998
 ;For name="NAME"
 param = ""
 ; No parameters allowed
 value = text-value
 ;For name="PROFILE"
 param = ""
 ; No parameters allowed
 value = text-value
 ; Value MUST be the case insensitive value "VCARD
 ;For name="SOURCE"
 param = source-param
 ; No parameters allowed
 value = uri
 source-param = ("VALUE" "=" "uri")
 / ("CONTEXT" "=" "word")
 ; Parameter value specifies the protocol context
 ; for the uri value.
 / (x-name "=" *SAFE-CHAR)
 ;For name="FN"
 ;This type MUST be included in a vCard object.
 param = text-param
 ; Text parameters allowed
 value = text-value
 ;For name="N"
 ;This type MUST be included in a vCard object.
 param = text-param
 ; Text parameters allowed
 value = n-value
 n-value = 0*4(text-value *("," text-value) ";")
 text-value *("," text-value)
 ; Family; Given; Middle; Prefix; Suffix.
 ; Example: Public;John;Quincy,Adams;Reverend Dr. III
 ;For name="NICKNAME"
 param = text-param
 ; Text parameters allowed
Dawson & Howes Standards Track [Page 30]
RFC 2426 vCard MIME Directory Profile September 1998
 value = text-list
 ;For name="PHOTO"
 param = img-inline-param
 ; Only image parameters allowed
 param =/ img-refer-param
 ; Only image parameters allowed
 value = img-inline-value
 ; Value and parameter MUST match
 value =/ img-refer-value
 ; Value and parameter MUST match
 ;For name="BDAY"
 param = ("VALUE" "=" "date")
 ; Only value parameter allowed
 param =/ ("VALUE" "=" "date-time")
 ; Only value parameter allowed
 value = date-value
 ; Value MUST match value type
 value =/ date-time-value
 ; Value MUST match value type
 ;For name="ADR"
 param = adr-param / text-param
 ; Only adr and text parameters allowed
 value = adr-value
 ;For name="LABEL"
 param = adr-param / text-param
 ; Only adr and text parameters allowed
 value = text-value
 ;For name="TEL"
 param = tel-param
 ; Only tel parameters allowed
 value = phone-number-value
 tel-param = "TYPE" "=" tel-type *("," tel-type)
Dawson & Howes Standards Track [Page 31]
RFC 2426 vCard MIME Directory Profile September 1998
 tel-type = "HOME" / "WORK" / "PREF" / "VOICE" / "FAX" / "MSG"
 / "CELL" / "PAGER" / "BBS" / "MODEM" / "CAR" / "ISDN"
 / "VIDEO" / "PCS" / iana-token / x-name
 ; Values are case insensitive
 ;For name="EMAIL"
 param = email-param
 ; Only email parameters allowed
 value = text-value
 email-param = "TYPE" "=" email-type ["," "PREF"]
 ; Value is case insensitive
 email-type = "INTERNET" / "X400" / iana-token / "X-" word
 ; Values are case insensitive
 ;For name="MAILER"
 param = text-param
 ; Only text parameters allowed
 value = text-value
 ;For name="TZ"
 param = ""
 ; No parameters allowed
 value = utc-offset-value
 ;For name="GEO"
 param = ""
 ; No parameters allowed
 value = float-value ";" float-value
 ;For name="TITLE"
 param = text-param
 ; Only text parameters allowed
 value = text-value
 ;For name="ROLE"
 param = text-param
 ; Only text parameters allowed
 value = text-value
 ;For name="LOGO"
Dawson & Howes Standards Track [Page 32]
RFC 2426 vCard MIME Directory Profile September 1998
 param = img-inline-param / img-refer-param
 ; Only image parameters allowed
 value = img-inline-value / img-refer-value
 ; Value and parameter MUST match
 ;For name="AGENT"
 param = agent-inline-param
 param =/ agent-refer-param
 value = agent-inline-value
 ; Value and parameter MUST match
 value =/ agent-refer-value
 ; Value and parameter MUST match
 agent-inline-param = ""
 ; No parameters allowed
 agent-refer-param = "VALUE" "=" "uri"
 ; Only value parameter allowed
 agent-inline-value = text-value
 ; Value MUST be a valid vCard object
 agent-refer-value = uri
 ; URI MUST refer to image content of given type
 ;For name="ORG"
 param = text-param
 ; Only text parameters allowed
 value = org-value
 org-value = *(text-value ";") text-value
 ; First is Organization Name, remainder are Organization Units.
 ;For name="CATEGORIES"
 param = text-param
 ; Only text parameters allowed
 value = text-list
 ;For name="NOTE"
 param = text-param
 ; Only text parameters allowed
Dawson & Howes Standards Track [Page 33]
RFC 2426 vCard MIME Directory Profile September 1998
 value = text-value
 ;For name="PRODID"
 param = ""
 ; No parameters allowed
 value = text-value
 ;For name="REV"
 param = ["VALUE" =" "date-time"]
 ; Only value parameters allowed. Values are case insensitive.
 param =/ "VALUE" =" "date"
 ; Only value parameters allowed. Values are case insensitive.
 value = date-time-value
 value =/ date-value
 ;For name="SORT-STRING"
 param = text-param
 ; Only text parameters allowed
 value = text-value
 ;For name="SOUND"
 param = snd-inline-param
 ; Only sound parameters allowed
 param =/ snd-refer-param
 ; Only sound parameters allowed
 value = snd-line-value
 ; Value MUST match value type
 value =/ snd-refer-value
 ; Value MUST match value type
 snd-inline-value = binary-value CRLF
 ; Value MUST be "b" encoded audio content
 snd-inline-param = ("VALUE" "=" "binary"])
 / ("ENCODING" "=" "b")
 / ("TYPE" "=" *SAFE-CHAR)
 ; Value MUST be an IANA registered audio type
 snd-refer-value = uri
 ; URI MUST refer to audio content of given type
Dawson & Howes Standards Track [Page 34]
RFC 2426 vCard MIME Directory Profile September 1998
 snd-refer-param = ("VALUE" "=" "uri")
 / ("TYPE" "=" word)
 ; Value MUST be an IANA registered audio type
 ;For name="UID"
 param = ""
 ; No parameters allowed
 value = text-value
 ;For name="URL"
 param = ""
 ; No parameters allowed
 value = uri
 ;For name="VERSION"
 ;This type MUST be included in a vCard object.
 param = ""
 ; No parameters allowed
 value = text-value
 ; Value MUST be "3.0"
 ;For name="CLASS"
 param = ""
 ; No parameters allowed
 value = "PUBLIC" / "PRIVATE" / "CONFIDENTIAL"
 / iana-token / x-name
 ; Value are case insensitive
 ;For name="KEY"
 param = key-txt-param
 ; Only value and type parameters allowed
 param =/ key-bin-param
 ; Only value and type parameters allowed
 value = text-value
 value =/ binary-value
 key-txt-param = "TYPE" "=" keytype
 key-bin-param = ("TYPE" "=" keytype)
 / ("ENCODING" "=" "b")
 ; Value MUST be a "b" encoded key or certificate
Dawson & Howes Standards Track [Page 35]
RFC 2426 vCard MIME Directory Profile September 1998
 keytype = "X509" / "PGP" / iana-token / x-name
 ; Values are case insensitive
 ;For name="X-" non-standard type
 param = text-param / (x-name "=" param-value)
 ; Only text or non-standard parameters allowed
 value = text-value
*/