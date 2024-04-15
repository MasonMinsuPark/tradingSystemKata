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
		tradingBrocker->buy(stockCode, price, count);
	}
	void sell(string stockCode, int price, int count) {
		tradingBrocker->sell(stockCode, price, count);
	}
	int getPrice(string stockCode) {
		return tradingBrocker->getPrice(stockCode);
	}
	void buyNiceTiming(string stockCode, int price, int count) {
		int prev_price = 0;
		int cur_price = 0;
		int up_count = 0;

		cur_price = getPrice(stockCode);
		prev_price = cur_price;  up_count++;

		cur_price = getPrice(stockCode);
		if (prev_price < cur_price) up_count++;

		cur_price = getPrice(stockCode);
		if (prev_price < cur_price) up_count++;

		if (up_count >= 3) tradingBrocker->buy(stockCode, price, count);
	}
	void sellNiceTiming(string stockCode, int price, int count) {

	}
private:
	TradingBrocker* tradingBrocker;
};