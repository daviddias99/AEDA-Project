#include <string>
#include <util.h>



/*struct Address {
	string street;
	string zipCode;
	int doorNumber;
	string
}; */





Address::Address(string streetName, string zipCode, int doorNumber, string city){

	this->city = city;
	this->doorNumber = doorNumber;
	this->zipCode = zipCode;
	this->streetName = streetName;

}
