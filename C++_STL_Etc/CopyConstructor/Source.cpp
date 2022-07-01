#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>

using namespace std;

typedef struct LINE {
    long timestamp{}, id{};
    double price{};
    char op;
}line;

//
// Implement the OrderBook class
//
class OrderBook
{
    vector<line> filltable(string filename);
public:
    void insert();
    void erase();
    int getHighestPrice(string filename);
};

vector<line> OrderBook::filltable(string filename)
{
    cout << "in filltable\n";
    vector<line> tab;
    ifstream is{ filename };
    long timestamp{}, id{};
    double price{};
    char op;

    int i{};
    string line;
    while (getline(is, line))
    {
        cout << line << endl;
        istringstream iss(line);
        iss >> timestamp >> op >> id >> price;
        tab[i].timestamp = timestamp;
        tab[i].op = op;
        tab[i].id = id;
        tab[i].price = price;
        cout << timestamp << op << id << price;
        ++i;
    }

    //copy(tab.begin(),tab.end(), ostream_iterator<string>(cout, ","));
    for (auto it : tab)
    {
        cout << it.timestamp << "," << it.op << "," << it.id << "," << it.price << endl;
    }
    return tab;

}

int OrderBook::getHighestPrice(string filename)
{
    cout << "in getHP\n";
    vector<line> table = filltable(filename);

    /*istream_iterator<string> iis{is};

    copy(iis.begin(), iss.end(),ostream_iterator<string>(tab.push_back(*iis)));

    int n = tab.size();
    double tot_price = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        double max_price = atof(tab[i][9].c_str());
        double min_price = atof(tab[i][10].c_str());
        double price = (max_price + min_price) / 2;

        tot_price += price;
    }

    return tot_price / n;*/
    return 1;

}


// Complete this function to parse the file and use the OrderBook class to
// compute the time weighted average high price.
//
double time_weighted_average_from_file(const char* filename)
{
    OrderBook ob;
    cout << "in twap\n";
    return ob.getHighestPrice(filename);
}


int main()
{
    // The contents of the file is visible via the top right-hand 'files' menu
    std::cout << time_weighted_average_from_file("D:\\temp\\input.txt") << std::endl;

}
