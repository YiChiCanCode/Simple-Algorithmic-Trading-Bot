#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>  // For generating random numbers
#include <ctime>    // For seeding random number generator

class TradingBot {
public:
    void run() {
        while (true) {
            double currentPrice = fetchCurrentPrice();
            double targetPrice = calculateTargetPrice(currentPrice);

            if (currentPrice > targetPrice) {
                executeBuyOrder();
            } else if (currentPrice < targetPrice) {
                executeSellOrder();
            }

            std::this_thread::sleep_for(std::chrono::minutes(1));
        }
    }

private:
    double fetchCurrentPrice() {
        // Simulate fetching the current price from an API or data source
        // Here, we'll generate a random price between 90 and 110
        return 90.0 + static_cast<double>(rand()) / RAND_MAX * 20.0;
    }

    double calculateTargetPrice(double currentPrice) {
        // Simulate a simple strategy for calculating the target price
        // Here, we'll add a fixed percentage to the current price
        return currentPrice * 1.05;  // Increase the price by 5%
    }

    void executeBuyOrder() {
        // need to fetch API for doing orders
        std::cout << "Executing buy order" << std::endl;
    }

    void executeSellOrder() {
        std::cout << "Executing sell order" << std::endl;
    }
};

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    TradingBot bot;
    bot.run();

    return 0;
}
