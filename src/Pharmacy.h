#ifndef SRC_PHARMACY_H_
#define SRC_PHARMACY_H_

#include <string>
#include <vector>
#include <map>

class Pharmacy {
public:
	Pharmacy(string name, Address address, Employee manager);
	virtual ~Pharmacy();
	bool addProduct(Product product);
	bool removeProduct(Product product, int quantity);
private:
	string name;
	Address address;
	Employee manager;
	vector< Employee > employees;
	map<Product, int> stock;
};

#endif /* SRC_PHARMACY_H_ */
