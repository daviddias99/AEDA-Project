#include <string>
#include "Person.h"
using namespace std;


Person::Person(string n, unsigned int nif, Address add) :name(n), NIF(nif), address(add)  {
	
}

string Person::getName() const
{
	return this->name;
}

unsigned int Person::getNIF() const
{
	return this->NIF;
}

Address Person::getAddress() const
{
	return this->address;
}

bool Person::changeAddress(Address newAddress)
{
	this->address = newAddress;
}

Employee::Employee(unsigned int sal, Pharmacy * pharm, string pos):salary(sal), workPlace(pharm),position(pos)
{


}

unsigned int Employee::getSalary() const
{
	return this->salary;
}

string Employee::getWorkplaceName() const
{
	return workPlace.getName();
}

string Employee::getPosition() const
{
	return this->position;
}

bool Employee::changeSalary(unsigned int newSalary)
{
	if (newSalary < 0)
		return false;


	this->salary = newSalary;

	return true;
}

bool Employee::changeFarmacy(Pharmacy * newWorkplace)
{
	this->workPlace = newWorkplace;

	return true;
}

bool Employee::changePosition(string newPosition)
{

	this->position = newPosition;

	return true;
}

Client::Client()
{
}

bool Client::addSale(Sale *)
{
	this->saleHistory.push_back(Sale);

	return true;
}
