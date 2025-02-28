#include "market_data.hpp"
#include "order_book.hpp"
#include "trade_engine.hpp"
#include <iostream>
#include <thread>

int main() {
    std::cout << "Starting FastTrade System...\n";
    
    OrderBook orderBook;
    TradeEngine tradeEngine(orderBook);
    MarketData marketData;
    
    // Simulate market data feed
    std::thread marketThread([&]() {
        marketData.simulateMarketFeed(orderBook);
    });
    
    // Simulate trade execution
    std::thread tradeThread([&]() {
        tradeEngine.processOrders();
    });
    
    marketThread.join();
    tradeThread.join();
    
    return 0;
}
