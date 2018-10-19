#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>

using namespace std;

/*Class Address {

public:
	Address(string streetName, string zipCode, int doorNumber, string city);
	changeAddress(Address address);
private:
	string streetName;
	string zipCode;
	int doorNumber;
	string city;
};*/

class Address {

public:
	Address(string streetName, string zipCode, int doorNumber, string city);
	bool changeAddress(Address address);
private:
	string streetName;
	string zipCode;
	int doorNumber;
	string city;
};



#endif /* SRC_UTIL_H_ */
