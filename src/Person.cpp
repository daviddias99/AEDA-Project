#include <string>
#include "Person.h"
using namespace std;


Person::Person(string n) {
	name = n;
}

string Person::getName() {
	return name;
}
