#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>  // For generating random numbers
#include <ctime>    // For seeding random number generator
#include <string>
#include <cstdlib>
using namespace std;
// currently we will be just trying on one single coin

// class Stock {
//     public:
//         string name;
//         float price;
// };

class TradingBot {
    public:
        string username;
        int id;
        float deposit;
        float balance;
        // stock list
        // history
        
        TradingBot(){
            cout << " *** We just construct our trading bot ***" << endl;
            
            cout << "Enter the Username:";
            cin >> username;

            id = rand();
 
            cout << "Enter your deposit amount:";
            cin >> deposit;
            balance = deposit;

            cout << " *** We just finish constructing our trading bot ***" << endl;    
        }

        void check(){
            while(true){
                cout << "*************************************" << endl;
                cout << "Press 1 to check your base deposit" << endl;
                cout << "Press 2 to check your balance" << endl;
                cout << "Press 3 to withdraw from your balance" << endl;
                cout << "Press 4 to manually buy stock" << endl;
                cout << "Press 5 to manually sell stock" << endl;
                cout << "Press 6 to get account information" << endl;
                cout << "Press 7 to get account history" << endl;
                cout << "*************************************" << endl;
                cout << "Your command: ";
                int command;
                cin >> command;
                switch (command)
                {  
                case 1:
                    printDeposit();
                    break;
                case 2:
                    printBalance();
                    break;
                case 3:
                    withdrawFromBalance();
                    break;                                    
                case 4:
                    cout << "Case 4"; // to be implemented
                    break;
                case 5:
                    cout << "Case 5"; // to be implemented
                    break;                                    
                case 6:
                    cout << "ID:" + to_string(id) << endl;
                    cout << "Username:" + username << endl;
                    cout << "Base deposit:" + to_string(deposit) << endl;
                    cout << "Current balance:" + to_string(balance) << endl;
                    break;
                case 7:
                    cout << "Case 7"; // to be implemented
                    break;
                default:
                    break;
                }

            }
        }


        // void run() {
        //     while (true) {
        //         double currentPrice = fetchCurrentPrice();
        //         double targetPrice = calculateTargetPrice(currentPrice);

        //         if (currentPrice > targetPrice) {
        //             executeBuyOrder();
        //         } else if (currentPrice < targetPrice) {
        //             executeSellOrder();
        //         }

        //         std::this_thread::sleep_for(std::chrono::minutes(1));
        //     }
        // }

    private:
        void printDeposit(){
            cout << "Your base deposit: ";
            cout << deposit << endl;
        }

        void printBalance(){
            cout << "Your current balance: ";
            cout << balance << endl;
        }

        void withdrawFromBalance(){
            cout << "How much would you like to withdraw: ";
            float withdrawAmount;
            cin >> withdrawAmount;
            // checking error
            if (withdrawAmount>balance){
                cout << "You don't have enough current balance to withdraw from" << endl;
                cout << "Your current balance: ";
                cout << balance << endl;    
                return;          
            }
            deposit -= withdrawAmount;
            balance -= withdrawAmount;
            cout << "You just withdraw " + to_string(balance) + " from your account!" << endl;
        }

    //     double fetchCurrentPrice() {
    //         // Simulate fetching the current price from an API or data source
    //         // Here, we'll generate a random price between 90 and 110
    //         return 90.0 + static_cast<double>(rand()) / RAND_MAX * 20.0;
    //     }

    //     double calculateTargetPrice(double currentPrice) {
    //         // Simulate a simple strategy for calculating the target price
    //         // Here, we'll add a fixed percentage to the current price
    //         return currentPrice * 1.05;  // Increase the price by 5%
    //     }

    //     void executeBuyOrder() {
    //         // need to fetch API for doing orders
    //         std::cout << "Executing buy order" << std::endl;
    //     }

    //     void executeSellOrder() {
    //         std::cout << "Executing sell order" << std::endl;
    //     }

};

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    TradingBot bot;
    bot.check();

    return 0;
}
