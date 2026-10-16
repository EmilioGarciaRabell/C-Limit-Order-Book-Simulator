#pragma once

#include <vector>

#include "OrderBook.hpp"
#include "Trade.hpp"

class Exchange {
public:
    std::vector<Trade> submitOrder(const Order& order);
private:
    OrderBook orderBook;
    std::vector<Trade> tradeHistory;
};