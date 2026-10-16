#pragma once

enum class Side {
    BUY,
    SELL
};

struct Order {
    int orderId;
    Side side;
    double price;
    int quantity;
};
