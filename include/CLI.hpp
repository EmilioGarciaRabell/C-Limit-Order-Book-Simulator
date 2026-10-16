#pragma once

#include "Exchange.hpp"

class CLI {
public:
    void run();

private:
    Exchange exchange;
    int orderId = 1;
};