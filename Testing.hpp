
#ifndef TESTING_HPP
#define TESTING_HPP

#include <random>

#include "OrderBook.hpp"

uint32_t randomBidPrice(const uint32_t minBidPrice, const uint32_t maxBidPrice);
uint32_t randomBidQuantity(const uint32_t minBidQuantity, const uint32_t maxBidQuantity);
uint32_t randomAskPrice(const uint32_t minAskPrice, const uint32_t maxAskPrice);
uint32_t randomAskQuantity(const uint32_t minAskQuantity, const uint32_t maxAskQuantity);

void randomBidOrders(OrderBook& orderbook, const uint64_t traderID, const uint32_t minBidPrice, const uint32_t maxBidPrice, const uint32_t minBidQuantity, const uint32_t maxBidQuantity);
void randomAskOrders(OrderBook& orderbook, const uint64_t traderID, const uint32_t minAskPrice, const uint32_t maxAskPrice, const uint32_t minAskQuantity, const uint32_t maxAskQuantity);

void trader1(OrderBook& orderbook);
void trader2(OrderBook& orderbook);

extern OrderType orderType;

extern uint32_t currentPrice;

#endif 
