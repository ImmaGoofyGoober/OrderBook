#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include "Order.hpp"
#include <map>
#include <utility>

class OrderBook {
private:
    uint64_t createUniqueOrderID();
public:
    std::map<std::pair<uint64_t, uint64_t>, Order, std::greater<>> bidOrders;
    std::map<std::pair<uint64_t, uint64_t>, Order, std::less<>> askOrders;

    void placeBidOrder(const Order& order);
    void eraseBidOrder(uint64_t price, uint64_t orderID);
    void placeAskOrder(const Order& order);
    void eraseAskOrder(uint64_t price, uint64_t orderID);
};

#endif