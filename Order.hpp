#ifndef ORDER_HPP
#define ORDER_HPP

#include <cstdint>

enum class OrderType {
    BID, ASK
};

struct Order {
    uint64_t price{};
    uint32_t quantity{};
    uint64_t traderID{};
    OrderType orderType{};

    void clear() {
        price = 0;
        quantity = 0;
        traderID = 0;
    }
};

#endif