#include <iostream>
#include <fstream>
#include <chrono>

#include "OrderBook.hpp"
#include "OrderMatching.hpp"
#include "Testing.hpp"

int filledOrders = 0;
std::ofstream outputFile("OrderBookOutput.txt");

int main() {
    OrderBook orderbook;
    OrderMatching matcher(orderbook);

    int inputOrders = 500000;
    int orderCount = 0;

    auto start = std::chrono::high_resolution_clock::now();

    while (orderCount < inputOrders) {
        orderCount++;
        trader1(orderbook);
        matcher.orderMatching();
        trader2(orderbook);
        matcher.orderMatching();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    int unfilledOrders = orderbook.bidOrders.size() + orderbook.askOrders.size();


    if (!orderbook.bidOrders.empty() && !orderbook.askOrders.empty()) {
        auto bestBid = orderbook.bidOrders.begin()->first.first;
        auto bestAsk = orderbook.askOrders.begin()->first.first;
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