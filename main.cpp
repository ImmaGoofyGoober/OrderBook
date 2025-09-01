#include <iostream>
#include <fstream>
#include <chrono>

#include "OrderBook.hpp"
#include "OrderMatching.hpp"
#include "Testing.hpp"

std::ofstream outputFile("OrderBookOutput.txt");

uint32_t currentPrice = 100;

int filledOrders = 0;

OrderType orderType{};

int main() {
    OrderBook orderbook;
    OrderMatching matcher(orderbook);

    int inputOrders = 5000;
    int orderCount = 0;

    auto start = std::chrono::high_resolution_clock::now();

    while (orderCount < inputOrders) {
        orderCount++;
        trader1(orderbook);
        matcher.orderMatching(orderType);
        trader2(orderbook);
        matcher.orderMatching(orderType);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    size_t unfilledOrders = orderbook.bidOrders.size() + orderbook.askOrders.size();

    if (!orderbook.bidOrders.empty() && !orderbook.askOrders.empty()) {
        uint32_t bestBid = orderbook.bidOrders.begin()->first.first;
        uint32_t bestAsk = orderbook.askOrders.begin()->first.first;
        std::cout << "Spread: " << (bestAsk - bestBid) << "\n\n";
        outputFile << "Spread: " << (bestAsk - bestBid) << "\n\n";
    }
    else {
        std::cout << "Spread: N/A\n\n";
        outputFile << "Spread: N/A\n\n";
    }

    std::cout << "Unfilled Orders: " << unfilledOrders << "\n";
    outputFile << "Unfilled Orders: " << unfilledOrders << "\n";
    std::cout << "Filled Orders: " << filledOrders << "\n\n";
    outputFile << "Filled Orders: " << filledOrders << "\n\n";
    std::cout << "Total Duration: " << duration.count() << " seconds\n";
    outputFile << "Total Duration: " << duration.count() << " seconds\n";

    return 0;
}
