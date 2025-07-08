#include "Testing.hpp"

std::mt19937 rd(std::random_device{}());

uint32_t randomBidPrice(uint32_t minBidPrice, uint32_t maxBidPrice) {
    std::uniform_int_distribution<uint32_t> dist(minBidPrice, maxBidPrice);
    return dist(rd);
}

uint32_t randomBidQuantity(uint32_t minBidQuantity, uint32_t maxBidQuantity) {
    std::uniform_int_distribution<uint32_t> dist(minBidQuantity, maxBidQuantity);
    return dist(rd);
}

uint32_t randomAskPrice(uint32_t minAskPrice, uint32_t maxAskPrice) {
    std::uniform_int_distribution<uint32_t> dist(minAskPrice, maxAskPrice);
    return dist(rd);
}

uint32_t randomAskQuantity(uint32_t minAskQuantity, uint32_t maxAskQuantity) {
    std::uniform_int_distribution<uint32_t> dist(minAskQuantity, maxAskQuantity);
    return dist(rd);
}

void randomBidOrders(OrderBook& orderbook, uint64_t traderID, uint32_t minBidPrice, uint32_t maxBidPrice, uint32_t minBidQuantity, uint32_t maxBidQuantity) {
    Order bidOrder{ randomBidPrice(minBidPrice, maxBidPrice), randomBidQuantity(minBidQuantity, maxBidQuantity), traderID, OrderType::BID };
    orderbook.placeBidOrder(bidOrder);
}

void randomAskOrders(OrderBook& orderbook, uint64_t traderID, uint32_t minAskPrice, uint32_t maxAskPrice, uint32_t minAskQuantity, uint32_t maxAskQuantity) {
    Order askOrder{ randomAskPrice(minAskPrice, maxAskPrice), randomAskQuantity(minAskQuantity, maxAskQuantity), traderID, OrderType::ASK };
    orderbook.placeAskOrder(askOrder);
}

void trader1(OrderBook& orderbook) {
    uint64_t traderID = 1;

    uint32_t minBidPrice = 10;
    uint32_t maxBidPrice = 200;
    uint32_t minBidQuantity = 30;
    uint32_t maxBidQuantity = 300;

    uint32_t minAskPrice = 10;
    uint32_t maxAskPrice = 500;
    uint32_t minAskQuantity = 5;
    uint32_t maxAskQuantity = 300;

    randomBidOrders(orderbook, traderID, minBidPrice, maxBidPrice, minBidQuantity, maxBidQuantity);
    //randomAskOrders(orderbook, traderID, minAskPrice, maxAskPrice, minAskQuantity, maxAskQuantity);

}

void trader2(OrderBook& orderbook) {
    uint64_t traderID = 2;

    uint32_t minBidPrice = 10;
    uint32_t maxBidPrice = 200;
    uint32_t minBidQuantity = 5;
    uint32_t maxBidQuantity = 300;

    uint32_t minAskPrice = 10;
    uint32_t maxAskPrice = 500;
    uint32_t minAskQuantity = 30;
    uint32_t maxAskQuantity = 300;

    //randomBidOrders(orderbook, traderID, minBidPrice, maxBidPrice, minBidQuantity, maxBidQuantity);
    randomAskOrders(orderbook, traderID, minAskPrice, maxAskPrice, minAskQuantity, maxAskQuantity);
}
