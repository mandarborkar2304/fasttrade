# fasttrade – Low-Latency Trading System

## Overview
FastTrade is a high-performance, low-latency trading system built using C++. It features an efficient in-memory order book, real-time trade execution, and a simulated market data feed. The system leverages multithreading for concurrent order processing.

## Features
- **Low-Latency Order Matching** – Efficient order execution using an in-memory order book.
- **Multithreading Support** – Parallel processing for market data and order execution.
- **Simulated Market Data Feed** – Generates realistic price movements for testing.

## Technologies Used
- **C++** – Core language for high-speed execution.
- **Multithreading (std::thread, mutex)** – For concurrent processing.
- **STL Containers (map, vector, mutex)** – Used for order book management.

## Project Structure
```
FastTrade/
│── main.cpp         # Entry point of the application
│── market_data.hpp  # Simulated market data feed
│── order_book.hpp   # Order book implementation
│── trade_engine.hpp # Trade matching engine
│── README.md
```

## Getting Started
### Prerequisites
Ensure you have the following installed:
- **C++17 or later**
- **GCC/Clang/MSVC Compiler**

### Compilation
1. **Clone the repository**
   ```sh
   git clone https://github.com/yourusername/FastTrade.git
   cd FastTrade
   ```
2. **Compile the project**
   ```sh
   g++ -std=c++17 -pthread main.cpp -o fasttrade
   ```
3. **Run the application**
   ```sh
   ./fasttrade
   ```

## 🛠️ Usage
- The system automatically generates market data and executes trades.
- Modify `market_data.hpp` to adjust price and quantity randomness.
- Enhance `trade_engine.hpp` to implement additional trading logic.

## 📜 License
This project is licensed under the MIT License.

