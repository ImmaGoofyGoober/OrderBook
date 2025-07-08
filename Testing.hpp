#ifndef TESTING_HPP
#define TESTING_HPP

#include "OrderBook.hpp"
#include <random>

uint32_t randomBidPrice(uint32_t minBidPrice, uint32_t maxBidPrice);
uint32_t randomBidQuantity(uint32_t minBidQuantity, uint32_t maxBidQuantity);
uint32_t randomAskPrice(uint32_t minAskPrice, uint32_t maxAskPrice);
uint32_t randomAskQuantity(uint32_t minAskQuantity, uint32_t maxAskQuantity);
void randomBidOrders(OrderBook& orderbook, uint64_t traderID, uint32_t minBidPrice, uint32_t maxBidPrice, uint32_t minBidQuantity, uint32_t maxBidQuantity);
void randomAskOrders(OrderBook& orderbook, uint64_t traderID, uint32_t minAskPrice, uint32_t maxAskPrice, uint32_t minAskQuantity, uint32_t maxAskQuantity);

void trader1(OrderBook& orderbook);
void trader2(OrderBook& orderbook);

#endif 
