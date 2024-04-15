#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../tradingSystem/tradingSystem.cpp"

using namespace testing;

class MockTradingBrocker : public TradingBrocker {
public:
	MOCK_METHOD(void, login, (string ID, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, getPrice, (string stockCode), (override));
	MOCK_METHOD(void, buyNiceTiming, (), (override));
	MOCK_METHOD(void, sellNiceTiming, (), (override));
};

class testTradingSystem : public Test {
public:
	void SetUp() override {
	}
	void TearDown() override {
	}
protected:
	App app;
};

TEST_F(testTradingSystem, loginTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, login("id", "1234"));
	app.login("id", "1234");
}

TEST_F(testTradingSystem, buyTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, buy(_, _, _)).Times(3);
	app.buy("samsung", 100000, 1);
	app.buy("sam", 1234, 2);
	app.buy("sung", 5678, 3);
}

TEST_F(testTradingSystem, sellTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, sell("samsung", 1, 80000));
	app.buy("samsung", 1, 80000);
}

TEST_F(testTradingSystem, getPriceTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, getPrice("samsung"));
	app.getPrice("samsung");
}