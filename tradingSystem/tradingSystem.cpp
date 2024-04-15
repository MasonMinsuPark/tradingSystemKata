#include <string>

using namespace std; 

class TradingBrocker {
public: 
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode) = 0;
	virtual void buyNiceTiming(string stockCode, int price, int count) = 0;
	virtual void sellNiceTiming(string stockCode, int price, int count) = 0;
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

	}
	void sell(string stockCode, int price, int count) {
		tradingBrocker->sell(stockCode, price, count);
	}
	int getPrice(string stockCode) {
		return tradingBrocker->getPrice(stockCode);
	}
	void buyNiceTiming(string stockCode, int price, int count) {

	}
	void sellNiceTiming(string stockCode, int price, int count) {

	}
private:
	TradingBrocker* tradingBrocker;
};