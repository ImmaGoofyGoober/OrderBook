#include "OrderBook.hpp"
#include <iostream>

uint64_t OrderBook::createUniqueOrderID() {
    static uint64_t uniqueOrderID{};
    return ++uniqueOrderID;
}

void OrderBook::placeBidOrder(const Order& order) {
    uint64_t orderID = createUniqueOrderID();
    bidOrders[{order.price, orderID}] = order;
}

void OrderBook::eraseBidOrder(uint64_t price, uint64_t orderID) {
    auto it = bidOrders.find({ price, orderID });
    if (it == bidOrders.end()) {
        std::cout << "Bid order not found\n";
        return;
    }
    bidOrders.erase(it);
}

void OrderBook::placeAskOrder(const Order& order) {
    uint64_t orderID = createUniqueOrderID();
    askOrders[{order.price, orderID}] = order;
}

void OrderBook::eraseAskOrder(uint64_t price, uint64_t orderID) {
    auto it = askOrders.find({ price, orderID });
    if (it == askOrders.end()) {
        std::cout << "Ask order not found\n";
        return;
    }
    askOrders.erase(it);
}
