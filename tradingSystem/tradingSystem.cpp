#include <string>

using namespace std; 

class TradingBrocker {
public: 
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual void getPrice(string stockCode) = 0;
	virtual void buyNiceTiming() = 0;
	virtual void sellNiceTiming() = 0;
};

class App {
public:
	void selectStockBlocker(TradingBrocker* tradingBrockerPtr) {
		tradingBrocker = tradingBrockerPtr;
	}
	void login(string ID, string password) {
		tradingBrocker->login(ID, password);
	}
	void buy(string stockCode, int price, int count) {
		tradingBrocker->buy(stockCode, price, count);
	}
	void sell(string stockCode, int price, int count) {
		tradingBrocker->sell(stockCode, price, count);
	}
	void getPrice(string stockCode) {
		tradingBrocker->getPrice(stockCode);
	}
	void buyNiceTiming() {

	}
	void sellNiceTiming() {

	}
private:
	TradingBrocker* tradingBrocker;
};