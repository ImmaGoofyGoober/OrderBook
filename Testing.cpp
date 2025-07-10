
#include "Testing.hpp"

std::mt19937 rd(std::random_device{}());

uint32_t randomBidPrice(const uint32_t minBidPrice, const uint32_t maxBidPrice) {
    std::uniform_int_distribution<uint32_t> dist(minBidPrice, maxBidPrice);
    return dist(rd);
}

uint32_t randomBidQuantity(const uint32_t minBidQuantity, const uint32_t maxBidQuantity) {
    std::uniform_int_distribution<uint32_t> dist(minBidQuantity, maxBidQuantity);
    return dist(rd);
}

uint32_t randomAskPrice(const uint32_t minAskPrice, const uint32_t maxAskPrice) {
    std::uniform_int_distribution<uint32_t> dist(minAskPrice, maxAskPrice);
    return dist(rd);
}

uint32_t randomAskQuantity(const uint32_t minAskQuantity, const uint32_t maxAskQuantity) {
    std::uniform_int_distribution<uint32_t> dist(minAskQuantity, maxAskQuantity);
    return dist(rd);
}

void randomBidOrders(OrderBook& orderbook, const uint64_t traderID, const uint32_t minBidPrice, const uint32_t maxBidPrice, const uint32_t minBidQuantity, const uint32_t maxBidQuantity) {
    Order bidOrder{ randomBidPrice(minBidPrice, maxBidPrice), randomBidQuantity(minBidQuantity, maxBidQuantity), traderID, OrderType::BID };
    orderbook.placeBidOrder(bidOrder);
}

void randomAskOrders(OrderBook& orderbook, const uint64_t traderID, const uint32_t minAskPrice, const uint32_t maxAskPrice, const uint32_t minAskQuantity, const uint32_t maxAskQuantity) {
    Order askOrder{ randomAskPrice(minAskPrice, maxAskPrice), randomAskQuantity(minAskQuantity, maxAskQuantity), traderID, OrderType::ASK };
    orderbook.placeAskOrder(askOrder);
}

// Add check for active order types

void trader1(OrderBook& orderbook) {
    const uint64_t traderID = 1;

    uint32_t minBidPrice = 80;
    uint32_t maxBidPrice = 110;
    uint32_t minBidQuantity = 5;
    uint32_t maxBidQuantity = 15;

    uint32_t minAskPrice = 0;
    uint32_t maxAskPrice = 0;
    uint32_t minAskQuantity = 0;
    uint32_t maxAskQuantity = 0;

    if (currentPrice <= 110) {
        randomBidOrders(orderbook, traderID, minBidPrice, maxBidPrice, minBidQuantity, maxBidQuantity);
        orderType = OrderType::BID;
    }
    /*if (currentPrice >= 80) {
        randomAskOrders(orderbook, traderID, minAskPrice, maxAskPrice, minAskQuantity, maxAskQuantity);
        orderType = OrderType::ASK;
    }*/
}

void trader2(OrderBook& orderbook) {
    const uint64_t traderID = 2;

    uint32_t minBidPrice = 0;
    uint32_t maxBidPrice = 0;
    uint32_t minBidQuantity = 0;
    uint32_t maxBidQuantity = 0;

    uint32_t minAskPrice = 90;
    uint32_t maxAskPrice = 120;
    uint32_t minAskQuantity = 5;
    uint32_t maxAskQuantity = 15;

    /*if (currentPrice <= 160) {
        randomBidOrders(orderbook, traderID, minBidPrice, maxBidPrice, minBidQuantity, maxBidQuantity);
        orderType = OrderType::BID;
    }*/
    if (currentPrice >= 90) {
        randomAskOrders(orderbook, traderID, minAskPrice, maxAskPrice, minAskQuantity, maxAskQuantity);
        orderType = OrderType::ASK;
    }
}

