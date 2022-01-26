#pragma once

#include <string>
#include <unordered_map>

class Checkout {
public:
	Checkout();
	virtual ~Checkout();
	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	int calculateTotal();
	void addDiscount(std::string item, int numItems, int discountPrice);
private:
	bool isItemPresent(std::string item);
	bool canApplyDiscount(std::string item);
	int calculateTotalForItem(std::string item, int itemCount);
	int calculateTotalWithDiscount(std::string item, int itemCount);
	int calculateTotalWithoutDiscount(std::string item, int itemCount);
private:
	struct Discount {
		int numItems;
		int discountPrice;
	};
	std::unordered_map<std::string, int> prices_;
	std::unordered_map<std::string, Discount> discounts_;
	std::unordered_map<std::string, int> items_;
};