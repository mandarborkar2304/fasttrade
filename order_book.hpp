#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP
#include <map>
#include <vector>
#include <mutex>
#include <iostream>
#include <queue>

class OrderBook {
private:
    std::map<int, int> buyOrders;
    std::map<int, int> sellOrders;
    std::mutex bookMutex;

public:
    void addOrder(const std::string& type, int price, int quantity) {
        std::lock_guard<std::mutex> lock(bookMutex);
        if (type == "BUY") {
            buyOrders[price] += quantity;
        } else if (type == "SELL") {
            sellOrders[price] += quantity;
        }
        std::cout << "Added " << type << " order: " << quantity << " @ " << price << "\n";
    }

    bool matchOrders() {
        std::lock_guard<std::mutex> lock(bookMutex);
        while (!buyOrders.empty() && !sellOrders.empty()) {
            auto buy = --buyOrders.end();
            auto sell = sellOrders.begin();

            if (buy->first >= sell->first) {
                int tradedQty = std::min(buy->second, sell->second);
                buy->second -= tradedQty;
                sell->second -= tradedQty;
                std::cout << "Trade executed: " << tradedQty << " @ " << sell->first << "\n";
                if (buy->second == 0) buyOrders.erase(buy);
                if (sell->second == 0) sellOrders.erase(sell);
                return true;
            } else {
                break;
            }
        }
        return false;
    }
};
#endif
