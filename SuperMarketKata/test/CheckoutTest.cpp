#include <gtest/gtest.h>
#include "Checkout.h"

using namespace std;

class CheckoutTests : public ::testing::Test {
public:
protected:
	Checkout checkOut;
};
 
TEST_F(CheckoutTests, CanCalculateTotal) {
	checkOut.addItemPrice("item", 1);
	checkOut.addItem("item");
	ASSERT_EQ(1, checkOut.calculateTotal());
}

TEST_F(CheckoutTests, CanAddMultipleItemsAndCalculateTotal) {
	checkOut.addItemPrice("item1", 1);
	checkOut.addItemPrice("item2", 2);
	checkOut.addItem("item1");
	checkOut.addItem("item2");
	ASSERT_EQ(3, checkOut.calculateTotal());
}

TEST_F(CheckoutTests, CanAddDiscountRule) {
	checkOut.addDiscount("item1", 3, 2);
}

TEST_F(CheckoutTests, CanApplyDiscountAndCalculateTotal) {
	checkOut.addItemPrice("item1", 1);
	checkOut.addItemPrice("item2", 5);
	checkOut.addDiscount("item1", 3, 2);
	checkOut.addItem("item1");
	checkOut.addItem("item1");
	checkOut.addItem("item1");
	checkOut.addItem("item2");
	ASSERT_EQ(7, checkOut.calculateTotal());
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException) {
	ASSERT_THROW(checkOut.addItem("item1"), std::invalid_argument);
}