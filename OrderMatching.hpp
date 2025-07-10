
#ifndef ORDERMATCHING_HPP
#define ORDERMATCHING_HPP

#include <chrono>
#include <fstream>

#include "OrderBook.hpp"

extern int filledOrders;

extern uint32_t currentPrice;

extern std::ofstream outputFile;

class OrderMatching {
public:
    OrderBook& orderbook;

    OrderMatching(OrderBook& ob);
    void orderMatching(OrderType& ordertype);
};

#endif 
