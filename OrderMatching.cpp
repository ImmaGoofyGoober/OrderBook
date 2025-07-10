
#include <iostream>

#include "OrderMatching.hpp"

OrderMatching::OrderMatching(OrderBook& ob) : orderbook(ob) {}

void OrderMatching::orderMatching(OrderType& ordertype) {
    while (!orderbook.bidOrders.empty() && !orderbook.askOrders.empty()) {
        auto bidIterator = orderbook.bidOrders.begin();
        auto askIterator = orderbook.askOrders.begin();

        uint32_t bidPrice = bidIterator->first.first;
        uint32_t askPrice = askIterator->first.first;

        uint64_t bidOrderID = bidIterator->first.second;
        uint64_t askOrderID = askIterator->first.second;

        uint32_t bidQuantity = bidIterator->second.quantity;
        uint32_t askQuantity = askIterator->second.quantity;

        uint64_t bidTraderID = bidIterator->second.traderID;
        uint64_t askTraderID = askIterator->second.traderID;

        if (bidPrice == 0 || bidQuantity == 0) {
            orderbook.eraseBidOrder(bidPrice, bidOrderID);
            continue;
        }
        if (askPrice == 0 || askQuantity == 0) {
            orderbook.eraseAskOrder(askPrice, askOrderID);
            continue;
        }
        if (bidPrice < askPrice) {
            break;
        }
        else {
            auto start = std::chrono::high_resolution_clock::now();

            if (bidTraderID == askTraderID) {
                break;
            }
            else {
                if (bidQuantity > askQuantity) {
                    filledOrders++;
                    bidQuantity -= askQuantity;
                    orderbook.bidOrders[{bidPrice, bidOrderID}].quantity = bidQuantity;
                    orderbook.eraseAskOrder(askPrice, askOrderID);
                    std::cout << "\033[32mBid order updated and Ask order deleted\033[0m\n";
                    outputFile << "Bid order updated and Ask order deleted\n";
                    std::cout << "\033[32mRemaining Bid Quantity: \033[0m" << "\033[32m" << bidQuantity << "\033[0m" << "\n";
                    outputFile << "Remaining Bid Quantity: " << bidQuantity << "\n";
                    std::cout << "\033[32mBid Price: \033[0m" << "\033[32m" << bidPrice << "\033[0m" << "\n";
                    outputFile << "Bid Price: " << bidPrice << "\n";
                    std::cout << "\033[32mAsk Price: \033[0m" << "\033[32m" << askPrice << "\033[0m" << "\n";
                    outputFile << "Ask Price: " << askPrice << "\n";
                    std::cout << "\033[32mBid TraderID: \033[0m" << "\033[32m" << bidTraderID << "\033[0m" << "\n";
                    outputFile << "Bid TraderID: " << bidTraderID << "\n";
                    std::cout << "\033[32mAsk TraderID: \033[0m" << "\033[32m" << askTraderID << "\033[0m" << "\n";
                    outputFile << "Ask TraderID: " << askTraderID << "\n";
                    std::cout << "\033[32mOrderID: \033[0m" << "\033[32m" << bidOrderID << "\033[0m" << "\n\n";
                    outputFile << "OrderID: " << bidOrderID << "\n\n";
                }
                else if (askQuantity > bidQuantity) {
                    filledOrders++;
                    askQuantity -= bidQuantity;
                    orderbook.askOrders[{askPrice, askOrderID}].quantity = askQuantity;
                    orderbook.eraseBidOrder(bidPrice, bidOrderID);
                    std::cout << "\033[32mAsk order updated and Bid order deleted\033[0m\n";
                    outputFile << "Ask order updated and Bid order deleted\n";
                    std::cout << "\033[32mRemaining Ask Quantity: \033[0m" << "\033[32m" << askQuantity << "\033[0m" << "\n";
                    outputFile << "Remaining Ask Quantity: " << askQuantity << "\n";
                    std::cout << "\033[32mBid Price: \033[0m" << "\033[32m" << bidPrice << "\033[0m" << "\n";
                    outputFile << "Bid Price: " << bidPrice << "\n";
                    std::cout << "\033[32mAsk Price: \033[0m" << "\033[32m" << askPrice << "\033[0m" << "\n";
                    outputFile << "Ask Price: " << askPrice << "\n";
                    std::cout << "\033[32mBid TraderID: \033[0m" << "\033[32m" << bidTraderID << "\033[0m" << "\n";
                    outputFile << "Bid TraderID: " << bidTraderID << "\n";
                    std::cout << "\033[32mAsk TraderID: \033[0m" << "\033[32m" << askTraderID << "\033[0m" << "\n";
                    outputFile << "Ask TraderID: " << askTraderID << "\n";
                    std::cout << "\033[32mOrderID: \033[0m" << "\033[32m" << askOrderID << "\033[0m" << "\n\n";
                    outputFile << "OrderID: " << askOrderID << "\n\n";
                }
                else {
                    filledOrders += 2;
                    orderbook.eraseBidOrder(bidPrice, bidOrderID);
                    orderbook.eraseAskOrder(askPrice, askOrderID);
                    std::cout << "\033[31mBoth Orders deleted\033[0m\n";
                    outputFile << "Both Orders deleted\n";
                    std::cout << "\033[31mBid Price: \033[0m" << "\033[31m" << bidPrice << "\033[0m" << "\n";
                    outputFile << "Bid Price: " << bidPrice << "\n";
                    std::cout << "\033[31mAsk Price: \033[0m" << "\033[31m" << askPrice << "\033[0m" << "\n";
                    outputFile << "Ask Price: " << askPrice << "\n";
                    std::cout << "\033[31mBid TraderID: \033[0m" << "\033[31m" << bidTraderID << "\033[0m" << "\n";
                    outputFile << "Bid TraderID: " << bidTraderID << "\n";
                    std::cout << "\033[31mAsk TraderID: \033[0m" << "\033[31m" << askTraderID << "\033[0m" << "\n";
                    outputFile << "Ask TraderID: " << askTraderID << "\n";
                    std::cout << "\033[31mBid OrderID: \033[0m" << "\033[31m" << bidOrderID << "\033[0m" << "\n";
                    outputFile << "Bid OrderID: " << bidOrderID << "\n";
                    std::cout << "\033[31mAsk OrderID: \033[0m" << "\033[31m" << askOrderID << "\033[0m" << "\n\n";
                    outputFile << "Ask OrderID: " << askOrderID << "\n\n";
                }
                if (ordertype == OrderType::BID) {
                    currentPrice = askPrice;
                    std::cout << "\033[33mCurrent Price: \033[0m" << "\033[33m" << currentPrice << "\033[0m" << "\n\n";
                    outputFile << "Current Price: " << currentPrice << "\n\n";
                }
                else {
                    currentPrice = bidPrice;
                    std::cout << "\033[33mCurrent Price: \033[0m" << "\033[33m" << currentPrice << "\033[0m" << "\n\n";
                    outputFile << "Current Price: " << currentPrice << "\n\n";
                }
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duration = end - start;

                std::cout << "Matched in " << duration.count() << " seconds\n\n";
                outputFile << "Matched in " << duration.count() << " seconds\n\n";
            }
        }
    }
}
