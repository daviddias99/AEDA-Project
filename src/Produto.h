#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;


class Product {
	Product(long int code, string n, string desc, float pr);
	long int getCodeNo() const;
	string getName() const;
	string getDesc() const;
	float getPrice() const;
	int changePrice(float newPrice);
private:
	const long int codeNo;
	const string name;
	const string description;
	float price;
};

class Medicine : public Product {
	Medicine(long int code, string n, string desc, float pr, bool soldWithNoPresc, bool canBePresc, float discountIfPresc);
	float discountIfPrescripted() const;
	bool canBePrescripted() const;
	bool canBeSoldWithNoPrescription() const;
private:
	const bool canBeSoldWithNoPresc;
	const bool canBePresc;
	const float discountWhenPresc;
};

#endif /* PRODUCT_H */
