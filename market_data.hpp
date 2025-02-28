#ifndef MARKET_DATA_HPP
#define MARKET_DATA_HPP
#include "order_book.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

class MarketData {
public:
    void simulateMarketFeed(OrderBook& orderBook) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> priceDist(95, 110);
        std::uniform_int_distribution<int> qtyDist(5, 20);

        for (int i = 0; i < 10; ++i) {
            int buyPrice = priceDist(gen);
            int sellPrice = buyPrice + (priceDist(gen) % 5 + 1);
            int quantity = qtyDist(gen);

            orderBook.addOrder("BUY", buyPrice, quantity);
            orderBook.addOrder("SELL", sellPrice, quantity);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
};
#endif
