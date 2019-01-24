/*
 * User.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#include "User.h"
#include <iostream>
namespace std {

User::User(string name,string surname,int tcNo,PersonType personType,Card c1,Card c2)
:Person(name,surname,tcNo,personType)
{
this->userCart1=c1;
this->userCart2=c2;
}
void User::loadBalance(Card &c,int miktar){
	if(c.cardType!=2){//  emekliler yükleme yapmazlar
		c.Balance+=miktar;
	}
	else if(c.cardType==2){
			cout<< "emekli  para yüklenmedi"<<endl;
		}
	}
void User::ReadCard(Card &c, int miktar){
	if(c.cardType!=2){//  emeklilerden çekim yapılmaz
		// kart türüne göre çekim miktarı belirlemek
			if(c.cardType==0){//normal kullanıcı
				// kartta yeterli bakiye bulunmadığı zaman
				if(c.Balance-miktar<0){
					cout<<"yetersiz bakiye"<<endl;
				}
				else	c.Balance-=miktar;
			}
			if(c.cardType==1){//oğrenci
							// kartta yeterli bakiye bulunmadığı zaman
							if(c.Balance-(miktar/2)<0){
								cout<<"yetersiz bakiye"<<endl;
							}
							else	c.Balance-=(miktar/2);
						}
	}
	else if(c.cardType==2){
		cout<< "emekli para çekilmedi!"<<endl;
	}
}
void User::showCardState(Card c) {
	string cardTypes[]={"Normal","Student","Retired"};
	cout<<"Ad             : "<<this->name<<endl;
	cout<<"soyad          : "<<this->surname<<endl;
	cout<<"Tc             : "<<this->tcNo<<endl;
	cout<<"Bakiye miktarı : "<<c.Balance<<endl;
	cout<<"kart türü      : "<< cardTypes[c.cardType]<<endl;
}
} /* namespace std */
