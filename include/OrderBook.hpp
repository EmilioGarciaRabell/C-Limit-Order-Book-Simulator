#pragma once


#include <map>
#include <queue>
#include <vector>
#include "Trade.hpp"
#include "Order.hpp"

class OrderBook {
public:
    void addOrder(const Order& order);
    std::vector<Trade> matchOrders();

private:
    std::vector<Trade> buyOrder(const Order& order);
    std::vector<Trade> sellOrder(const Order& order);
    std::map<double, std::queue<Order>> buyOrders;
    std::map<double, std::queue<Order>> sellOrders;
    int nextTradeId = 1;

};