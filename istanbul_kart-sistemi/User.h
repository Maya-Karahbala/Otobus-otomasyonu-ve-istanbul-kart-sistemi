/*
 * User.h
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#ifndef USER_H_
#define USER_H_
#include "Person.h"
#include "Card.h"

namespace std {

class User :public Person{
public:
	User(string,string,int,PersonType,Card,Card);
	Card userCart1,userCart2;
	void loadBalance(Card &,int);
	void ReadCard(Card &,int);
	void showCardState(Card );

};

} /* namespace std */

#endif /* USER_H_ */
