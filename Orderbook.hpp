#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <map>
#include <unordered_map>
#include <utility>

#include "Order.hpp"

class OrderBook {
private:
    uint64_t createUniqueOrderID();
public:
    std::map<std::pair<uint32_t, uint64_t>, Order, std::greater<>> bidOrders;
    std::map<std::pair<uint32_t, uint64_t>, Order, std::less<>> askOrders;

    uint64_t placeBidOrder(const Order& order);
    void eraseBidOrder(uint32_t price, uint64_t orderID);
    uint64_t placeAskOrder(const Order& order);
    void eraseAskOrder(uint32_t price, uint64_t orderID);
};

#endif