#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <util.h>
#include <Pharmacy.h>
#include <Sale.h>

using namespace std;


class Person {
public:
	Person(string n, unsigned int nif, Address add);
	
	string getName() const;
	unsigned int getNIF() const; 
	Address getAddress() const; 

	bool changeAddress(Address newAddress);


private:
	const string name;
	const unsigned int NIF;
	Address address;
	

};

class Employee :protected Person {
public:
	Employee(unsigned int sal, Pharmacy* pharm, string pos);

	unsigned int getSalary() const; 
	string getWorkplaceName() const; 
	string getPosition() const; 

	bool changeSalary(unsigned int newSalary);
	bool changeFarmacy(Pharmacy* newWorkplace);
	bool changePosition(string newPosition);
	

private:
	unsigned int salary;
	Pharmacy* workPlace;
	string position;
};

class Client :protected Person {
public:

	Client();

	bool addSale(Sale*);
	bool viewHistory(); 


private:
	vector<Sale*> saleHistory;
};


#endif
