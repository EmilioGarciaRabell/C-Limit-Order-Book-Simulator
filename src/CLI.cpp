#include "../include/CLI.hpp"
#include <iostream>
#include <string>

void CLI::run(){
    while (true){
        std::string command;
        double price;
        int quantity;
        Side side;
        
        // get user input
        std::cout << "Please enter an order: " << std::endl;
        std::cin >> command;
        
        // Check command side
        if (command == "exit"){
            std::cout << "Exiting program....";
            break;
        }

        std::cin >> price >> quantity;

        if (command == "sell"){
            side = Side::SELL;
        }else if (command == "buy"){
            side = Side::BUY;
        }else{
            std::cout<<"Invalid command please try again" << std::endl;
            continue;
        }
        
        std::cout << "Submitting Order: " << command << " " << price << " " << quantity << std::endl;
        
        
        std::vector<Trade> newTrades = exchange.submitOrder(Order{orderId, side, price, quantity});
        orderId ++;
        
        if (newTrades.empty()){
            std::cout << "No trades were executed." << std::endl;
        }else{
            for (size_t i = 0; i < newTrades.size(); i++){
                Trade currentTrade = newTrades[i];
                std::cout<< "Trade executed: " << currentTrade.tradeId << " " << currentTrade.quantity << " " << currentTrade.price << std::endl;
            }
        }
        
    }

}