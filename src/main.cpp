#include <iostream>
#include "Person.h"

using namespace std;


int main() {

	Person *p = new Person("TOZE");

	cout << p->getName() << endl;

	return 0;
}



