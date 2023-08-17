#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>  // For generating random numbers
#include <ctime>    // For seeding random number generator
#include <string>
#include <cstdlib>
using namespace std;
// currently we will be just trying on one single stock - APPL
// in the future we will want to be able to trading multiple 

class TradingBot {
    public:
        string username;
        int id;
        float deposit;
        float balance;
        float previous_price;
        float current_price;
        float threshold = 0.5;
        int quantity = 0;
        float average_price = 0;

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


        void run() {
            while (true) {
                previous_price = current_price;
                current_price = fetchCurrentPrice();
                float price_change = current_price - previous_price;

                if (abs(price_change)>threshold){
                    if (price_change>0){
                        execute_buy_order(current_price) // buy
                    }else{
                        execute_sell_order(current_price) //sell
                    }
                }
                // std::this_thread::sleep_for(std::chrono::minutes(1));
            }
        }

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

        float fetchCurrentPrice() {
            return 90.0;
            //should be actually calling Alpha API
        }

        void executeBuyOrder() {
            std::cout << "Executing buy order" << std::endl;
        }

        void executeSellOrder() {
            // will not be able to execute sell if we don't have stock
            if quantity==0{
                cout << "Not executing sell order: CURRENTLY HOLD 0 STOCK" << std::endl;
                return
            }
            
        }

};

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    TradingBot bot;
    bot.check();

    return 0;
}
