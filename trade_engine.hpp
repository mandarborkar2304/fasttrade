#ifndef TRADE_ENGINE_HPP
#define TRADE_ENGINE_HPP
#include "order_book.hpp"
#include <iostream>
#include <thread>
#include <chrono>

class TradeEngine {
private:
    OrderBook& orderBook;

public:
    TradeEngine(OrderBook& ob) : orderBook(ob) {}

    void processOrders() {
        while (true) {
            if (!orderBook.matchOrders()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
        }
    }
};
#endif
