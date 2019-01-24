/*
 * Admin.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#include "Admin.h"

namespace std {

Admin::Admin() {


}
User* Admin::createUser(string name, string surname, int tcNo,
		PersonType personType, CardType c1T, CardType c2T) {
  // kartlarin balance başlangıç değeri 0 olacak
	User *u=new User(name, surname, tcNo, personType, Card(0,c1T), Card(0,c2T));
	return  u;
}
void Admin::DeleteUser(User *u) {
// user new ile oluştşrulmuş olmalı yoksa hata verir
	delete u;
}
void Admin::CombineUserCards(User* u) {
	u->userCart1 + u->userCart2;
}
bool Admin::ShowPersonState(Person* personeller[], int size, int tc) {
	int i;
	string strPersonTypes[] = { "user", "admin" };
	bool bulunduMu = false;
	for (i = 0; i < size; ++i) {
		if (personeller[i]->getTc() == tc) {
			cout << "Ad             : " << personeller[i]->getName() << endl;
			cout << "soyad          : " << personeller[i]->getSurname() << endl;
			cout << "Tc             : " << personeller[i]->getTc() << endl;
			cout << "kişi           : "
					<< strPersonTypes[personeller[i]->getPersonType()] << endl;
			bulunduMu = true;

			break;
		}
	}
	return bulunduMu;

}
void Admin::ShowUserState(User* u) {
	string cardTypes[] = { "Normal", "Student", "Retired" };
	cout << "Ad             : " << u->getName() << endl;
	cout << "soyad          : " << u->getSurname() << endl;
	cout << "Tc             : " << u->getTc() << endl;
	cout << "1. kart        ::bakiye: " << u->userCart1.Balance << "  türü: "
			<< cardTypes[u->userCart1.cardType] << endl;
	cout << "2. kart        ::bakiye: " << u->userCart2.Balance << "  türü: "
			<< cardTypes[u->userCart2.cardType] << endl;

}
void Admin::changeNameSurname(User* u, const string &name, const string & surname) {
	u->setName(name);
	u->setSurname(surname);
}


int Admin::findUser(Person* personeller[], int size, int tc) {

	int i;
	bool bulunduMu = false;
	for (i = 0; i < size; ++i) {
		if (personeller[i]->getTc() == tc
				&& personeller[i]->getPersonType() == user) {
			bulunduMu = true;
			break;
		}
	}
	if( !bulunduMu)return -1;//kullanıc bulunmadığı  zaman -1 dödürür
	else return i;// kullanıc bulunduğu zaman indexi dödürür

}

} /* namespace std */
