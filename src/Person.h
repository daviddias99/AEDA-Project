#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;


class Person {
public:
	Person(string n);
	string getName();
private:
	string name;
};


#endif
