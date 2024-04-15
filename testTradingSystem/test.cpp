#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../tradingSystem/tradingSystem.cpp"

using namespace testing;

class MockTradingBrocker : public TradingBrocker {
public:
	MOCK_METHOD(void, login, (string ID, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (string stockCode), (override));
	MOCK_METHOD(void, buyNiceTiming, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sellNiceTiming, (string stockCode, int price, int count), (override));
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
	EXPECT_CALL(mockTradingBrocker, buy("samsung", 1, 100000));
	app.buy("samsung", 1, 100000);
}

TEST_F(testTradingSystem, sellTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);

	EXPECT_CALL(mockTradingBrocker, sell("samsung", 1, 80000))
		.WillRepeatedly(Return());

	app.buy("samsung", 1, 80000);
}

TEST_F(testTradingSystem, getPriceTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, getPrice("samsung"));
	app.getPrice("samsung");
}

TEST_F(testTradingSystem, buyNiceTimingTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, getPrice("samsung"))
		.WillOnce(Return(80000))
		.WillOnce(Return(90000))
		.WillOnce(Return(100000));
	EXPECT_CALL(mockTradingBrocker, buy("samsung", 100000, 1));

	app.buyNiceTiming("samsung", 100000, 1);
}

TEST_F(testTradingSystem, sellNiceTimingTest) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, getPrice("samsung"))
		.WillOnce(Return(100000))
		.WillOnce(Return(90000))
		.WillOnce(Return(80000));
	EXPECT_CALL(mockTradingBrocker, sell("samsung", 80000, 1));

	app.sellNiceTiming("samsung", 80000, 1);
}

TEST_F(testTradingSystem, sellNiceTimingTest2) {
	MockTradingBrocker mockTradingBrocker;
	app.selectStockBlocker(&mockTradingBrocker);
	EXPECT_CALL(mockTradingBrocker, getPrice("samsung"))
		.WillOnce(Return(100000))
		.WillOnce(Return(90000))
		.WillOnce(Return(90000));
	EXPECT_CALL(mockTradingBrocker, sell("samsung", 80000, 1)).Times(0);

	app.sellNiceTiming("samsung", 80000, 1);
}