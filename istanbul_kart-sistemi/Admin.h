/*
 * Admin.h
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#ifndef ADMIN_H_
#define ADMIN_H_
#include "Person.h"
#include "User.h"
#include <iostream>
namespace std {

class Admin: public Person {
public:
	Admin();
	~Admin();
	User* createUser(string, string, int, PersonType, CardType, CardType);
	void DeleteUser(User*);
	void CombineUserCards(User *);
	int findUser(Person*[], int, int);
	bool ShowPersonState(Person*[], int, int);
	void ShowUserState(User*);
	void changeNameSurname(User*, const string&, const string &);

};

} /* namespace std */

#endif /* ADMIN_H_ */
