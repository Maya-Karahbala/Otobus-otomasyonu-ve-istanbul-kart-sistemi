/*
 * Person.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#include "Person.h"

namespace std {

Person::Person() {
}
 Person:: ~Person(){
		//cout<<"person deleted"<<endl;
	}
Person::Person(string name,string surname,int tcNo,PersonType personType) {
	this->name= name;
	this->surname= surname;
	this->tcNo= tcNo;
	this->personType =personType;
}
string Person:: getName() {
	return name;
}
void Person:: setSurname(string surname) {
	this->surname = surname;
}
string Person:: getSurname() {
	return surname;
}
void Person:: setName(string name) {
	this->name = name;
}
int Person:: getTc() {
	return tcNo;
}
void Person:: setTc(int tcNo) {
	// tc kimlic no const yapılabilir ozaman initilizer list kullanmamız gerekecektir
	// constructor içinde :tcNo(tcNo)
	this->tcNo = tcNo;
}
PersonType Person:: getPersonType() {
	return personType;
}
void Person:: setPersonType(PersonType personType) {
	this->personType = personType;
}
} /* namespace std */
