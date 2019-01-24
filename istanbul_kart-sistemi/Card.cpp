/*
 * Card.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#include "Card.h"

namespace std {

Card::Card() {
}
Card::Card(int Balance,CardType cardType){
	this->Balance= Balance;
	this->cardType =cardType;
}
Card & Card:: operator+( Card& c){
this->Balance+= c.Balance;
c.Balance=0;
return *this;
}
} /* namespace std */
