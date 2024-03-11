#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
const int bufferCapacity = 5;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        {
            std::unique_lock<std::mutex> lock(mtx);

            // Wait until the buffer has space
            cv.wait(lock, [] { return buffer.size() < bufferCapacity; });

            // Produce an item and add it to the buffer
            buffer.push(i);
            std::cout << "Produced: " << i << std::endl;
        }

        // Notify the consumer that there's a new item in the buffer
        cv.notify_one();

        // Simulate some work being done by the producer
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void consumer() {
    for (int i = 1; i <= 10; ++i) {
        {
            std::unique_lock<std::mutex> lock(mtx);

            // Wait until the buffer has an item
            cv.wait(lock, [] { return !buffer.empty(); });

            // Consume the item from the buffer
            int item = buffer.front();
            buffer.pop();
            std::cout << "Consumed: " << item << std::endl;
        }

        // Notify the producer that there's space in the buffer
        cv.notify_one();

        // Simulate some work being done by the consumer
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}