#include "../include/Exchange.hpp"
#include "../include/OrderBook.hpp"

// Submit an order to the orderbook
std::vector<Trade> Exchange::submitOrder(const Order& order){
    orderBook.addOrder(order);
    std::vector<Trade> newTrades = orderBook.matchOrders();

    tradeHistory.insert(
    tradeHistory.end(),
    newTrades.begin(),
    newTrades.end()
    );

    return newTrades;
}