
#include <iostream>

#include "OrderBook.hpp"

uint64_t OrderBook::createUniqueOrderID() {
    static uint64_t uniqueOrderID{};
    return ++uniqueOrderID;
}

uint64_t OrderBook::placeBidOrder(const Order& order) {
    uint64_t orderID = createUniqueOrderID();
    bidOrders[{order.price, orderID}] = order;
    return orderID;
}

void OrderBook::eraseBidOrder(const uint32_t price, const uint64_t orderID) {
    auto it = bidOrders.find({ price, orderID });
    if (it == bidOrders.end()) {
        std::cout << "Bid order not found\n";
        return;
    }
    bidOrders.erase(it);
}

uint64_t OrderBook::placeAskOrder(const Order& order) {
    uint64_t orderID = createUniqueOrderID();
    askOrders[{order.price, orderID}] = order;
    return orderID;
}

void OrderBook::eraseAskOrder(const uint32_t price, const uint64_t orderID) {
    auto it = askOrders.find({ price, orderID });
    if (it == askOrders.end()) {
        std::cout << "Ask order not found\n";
        return;
    }
    askOrders.erase(it);
}
