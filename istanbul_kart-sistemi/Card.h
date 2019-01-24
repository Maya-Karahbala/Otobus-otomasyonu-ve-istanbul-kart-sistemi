/*
 * Card.h
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#ifndef CARD_H_
#define CARD_H_

enum CardType{
	Normal,Student,Retired
};

namespace std {

class Card {
public:
	Card();
	Card(int,CardType);
	int Balance;
	CardType cardType;
	Card& operator+( Card& );
};

} /* namespace std */

#endif /* CARD_H_ */
