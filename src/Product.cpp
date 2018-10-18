#include "product.h"

Product::Product(long int code, string n, string desc, float pr) {
	codeNo = code;
	name = n;
	description = desc;
	price = pr;
}

long int Product::getCodeNo() const {
	return codeNo;
}

string Product::getName() const {
	return name;
}

string Product::getDesc() const {
	return description;
}

float Product::getPrice() const {
	return price;
}

int Product::changePrice(float newPrice) {

	if (newPrice > 0) {
		price = newPrice;
		return 0;
	}
	else
		return 1;
}

//////////////////////////////////////////////////////////////

Medicine::Medicine(long int code, string n, string desc, float pr, bool soldWithNoPresc, bool possiblePresc, float discountIfPresc) : Product(code, n, desc, pr) {
	canBeSoldWithNoPresc = soldWithNoPresc;
	canBePresc = possiblePresc;
	discountWhenPresc = discountIfPresc;
}

float Medicine::discountIfPrescripted() const {
	return discountWhenPresc;
}

bool Medicine::canBePrescripted() const {
	return canBePresc;
}

bool Medicine::canBeSoldWithNoPrescription() const {
	return canBeSoldWithNoPresc;
}
