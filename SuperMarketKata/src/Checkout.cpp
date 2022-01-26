#include "Checkout.h"
#include <stdexcept>

using std::string;
using std::invalid_argument;

Checkout::Checkout() {

}

Checkout::~Checkout() {

}

void Checkout::addItemPrice(string item, int price) {
	prices_[item] = price;
}

void Checkout::addItem(string item) {
	if (!isItemPresent(item)) {
		throw invalid_argument("Item does not exist");
	}
	++items_[item];
}

int Checkout::calculateTotal() {
	int total = 0;
	for (const auto& it : items_) {
		string item = it.first;
		int itemCount = it.second;
		total += calculateTotalForItem(item, itemCount);
	}
	return total;
}

int Checkout::calculateTotalForItem(string item, int itemCount) {
	if (canApplyDiscount(item)) {
		return calculateTotalWithDiscount(item, itemCount);
	}
	else {
		return calculateTotalWithoutDiscount(item, itemCount);
	}
}

bool Checkout::canApplyDiscount(string item) {
	return discounts_.find(item) != discounts_.end();
}

int Checkout::calculateTotalWithDiscount(string item, int itemCount) {
	Discount discount = discounts_[item];
	const int numDiscounts = itemCount / discount.numItems;
	const int remainingItems = itemCount % discount.numItems;

	int total = 0;
	total += numDiscounts * discount.discountPrice;
	total += calculateTotalWithoutDiscount(item, remainingItems);
	return total;
}

int Checkout::calculateTotalWithoutDiscount(string item, int itemCount) {
	return itemCount * prices_[item];
}

void Checkout::addDiscount(string item, int numItems,
														int discountPrice) {
	Discount discount;
	discount.discountPrice = discountPrice;
	discount.numItems = numItems;
	discounts_[item] = discount;
}

bool Checkout::isItemPresent(string item) {
	return prices_.find(item) != prices_.end();
}
