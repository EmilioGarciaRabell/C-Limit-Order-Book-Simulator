#include "../include/OrderBook.hpp"
#include <vector>
#include <map>
#include <queue>
#include <iterator>

/*
 - Place a new order into buy/sell side
*/
void OrderBook::addOrder(const Order& order){
    if (order.side == Side::SELL){
        sellOrders[order.price].push(order);
    }else{
        buyOrders[order.price].push(order);
    }
}

/*
 - Check if existing orders can execute
*/
std::vector<Trade> OrderBook::matchOrders(){
    std::vector<Trade> trades;

    while (!buyOrders.empty() && !sellOrders.empty()){
        // Get cheapest sell order
        
        auto bestSell = sellOrders.begin();
        auto bestBuy = std::prev(buyOrders.end());
        int buyOrderId = bestBuy-> second.front().orderId;
        int sellOrderId = bestSell-> second.front().orderId;
        double price;
        int quantity;
        int tradeId = nextTradeId;

        if (bestBuy -> first < bestSell -> first){
            break;
        }

    
        price = bestSell -> first;
        // if the quantity of the buy is greater than the sell, remove that quantity from buy and pop the sell
        if (bestBuy -> second.front().quantity > bestSell -> second.front().quantity){
            bestBuy-> second.front().quantity -= bestSell -> second.front().quantity;
            
            quantity = bestSell -> second.front().quantity;
            

            
            bestSell -> second.pop();
        // if quantity of buy is smaller than the sell, then remove quantity from sell and pop the buy
        }else if (bestBuy -> second.front().quantity < bestSell -> second.front().quantity){
            bestSell-> second.front().quantity -= bestBuy -> second.front().quantity;
            
            quantity = bestBuy -> second.front().quantity;
            bestBuy -> second.pop();
        // If they are the same, pop both
        }else{
            quantity = bestSell -> second.front().quantity;
            bestBuy -> second.pop();
            bestSell -> second.pop();
        }
        
        // Check if the queues at the current price are empty if so remove the price from the map
        if (bestSell -> second.empty()){
            sellOrders.erase(bestSell -> first);
        }

        if (bestBuy -> second.empty()){
            buyOrders.erase(bestBuy -> first);
        }

        trades.push_back(Trade{tradeId, 
            buyOrderId,  
            sellOrderId, 
            price, 
            quantity});
        
        nextTradeId ++;
        
    
         
    }
    return trades;
}
