/*
 * Person.h
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>

enum PersonType {
	user, admin
};

namespace std {

class Person {
public:
	 Person();
	 ~Person();
    Person(string,string,int,PersonType);
	string getName();
	void setSurname(string );
	string getSurname();
	void setName(string ) ;
	int getTc() ;
	void setTc(int );
	PersonType getPersonType();
	void setPersonType(PersonType );
protected:
	string name, surname;
	int tcNo;
	PersonType personType;
};

} /* namespace std */

#endif /* PERSON_H_ */
