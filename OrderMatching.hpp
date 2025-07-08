#ifndef ORDERMATCHING_HPP
#define ORDERMATCHING_HPP

#include "OrderBook.hpp"
#include <chrono>
#include <fstream>

extern int filledOrders;
extern std::ofstream outputFile;

class OrderMatching {
public:
    OrderBook& orderbook;

    OrderMatching(OrderBook& ob);
    void orderMatching();
};

#endif 