/*
 * test.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: maya
 */

#include <iostream>
#include "User.h"
#include "Card.h"
#include "Admin.h"
#include "Person.h"
using namespace std;
int anaMenu() {
	system("cls");
	int secilen;
	cout << "1-Yonetici İslemleri" << endl;
	cout << "2-Kullanıcı İslemleri" << endl;
	cout << "3-Çıkış." << endl;
	cout << "\t\tlütfen seçim yapınız" << endl;
	cin >> secilen;
	return secilen;
}
int yoneticiMenu() {
	int secilen;

	cout << "1- Kullanici olustur" << endl;
	cout << "2- Kullanici sil" << endl;
	cout << "3- Kisi Durumumu Goster" << endl;
	cout << "4- Kullanıcı bul" << endl;
	cout << "5- Kullanici Kartlarini Birlestir" << endl;
	cout << "6- İsim Soyisim değiştir" << endl;
	cout << "7- Ana Menu" << endl;
	cout << "\t\tlütfen seçim yapınız" << endl;
	cin >> secilen;
	return secilen;
}
int kullaniciMenu() {
	int secilen;
	cout << "1- Bakiye Yukle" << endl;
	cout << "2- Kart Okut" << endl;
	cout << "3- Kart Durumu Goster" << endl;
	cout << "4- Ana Menu" << endl;
	cout << "\t\tlütfen seçim yapınız" << endl;
	cin >> secilen;
	return secilen;
}
int findAdmin(Person* personeller[], int size, int tc) {
	int i;
	bool bulunduMu = false;
	for (i = 0; i < size; ++i) {
		if (personeller[i]->getTc() == tc
				&& personeller[i]->getPersonType() == admin) {
			bulunduMu = true;
			break;
		}
	}
	if (bulunduMu == false)
		return -1;
	else
		return i;

}
char anaMenuyeDon(const string & s) {
	cout << s << " Ana menüye dönmek istiyor musunuz? y/n" << endl;
	char secim;
	cin >> secim;
	if(secim=='n') exit(0);
	return secim;
}
int main() {

	Admin *Admin1 = new Admin();
	Admin1->setName("hakkı");
	Admin1->setName("haklı");
	Admin1->setTc(1234);
	Admin1->setPersonType(admin);
	Card c1(10000, Student);
	Card c2(200, Student);
	User* u1 = new User("selin", "saklı", 4321, user, c1, c2);
	Person* tempPer=new Person("","",0,user);
	Person* personeller[10];
	personeller[0] = Admin1;
	personeller[1] = u1;
	int k;
	for (k = 2; k < 10; ++k) {
		personeller[k] = tempPer;// initilization
	}
	int sayac=2;

	Admin* tempAdmin=new Admin();// kullanıcı işlemlerinde  find user metuduna ulasmak icin
	int girilenTc = -2; // islem yapacak user yada admin
	int i; // index
	string ad, soyad;
	int tcNo;
	anaMenu: int secilen = anaMenu();

	if (secilen == 1) { //1-Yonetici İslemleri
		cout << "Yonetici Girisi: " << endl << "TC giriniz" << endl;
		cin >> girilenTc;
		i = findAdmin(personeller, 10, girilenTc);
		if (i != (-1)) { // findAdmin user bulunursa indexi dödürür bulamazsa -1 dödürür
			Admin *girisYapanA = ((Admin*) personeller[i]);
			yoneticiMenu: secilen = yoneticiMenu();
            bas:
			if (secilen == 1) // 1- Kullanici olustur
					{
				cout << "ad :";
				cin >> ad;
				cout << "soyad :";
				cin >> soyad;
				cout << "tc :";
				cin >> tcNo;
				cout << "personel tipi(admin , user) a/u :";
				PersonType personType;
				char perTipi;
				cin >> perTipi;
				if (perTipi == 'a')
					personType = admin;
				else if (perTipi == 'u')
					personType = user;
				cout << "1.kartın tipi(Normal,Student,Retired) n/s/r :";
				CardType c1T, c2T;
				char kart1Tipi;
				cin >> kart1Tipi;
				if (kart1Tipi == 'n')
					c1T = Normal;
				else if (kart1Tipi == 's')
					c1T = Student;
				else if (kart1Tipi == 'r')
					c1T = Retired;
				cout << "2.kartın tipi(Normal,Student,Retired) n/s/r :";
				char kart2Tipi;
				cin >> kart2Tipi;
				if (kart2Tipi == 'n')
					c2T = Normal;
				else if (kart2Tipi == 's')
					c2T = Student;
				else if (kart2Tipi == 'r')
					c2T = Retired;
				User* yeni = girisYapanA->createUser(ad, soyad, tcNo,
						personType, c1T, c2T);
				personeller[sayac++]=yeni;
				if (anaMenuyeDon("kullanıcı olüştürüldü") == 'y')
					goto yoneticiMenu;
				//cout<<yeni->getName()<<endl;

			} else if (secilen == 2) { //2- Kullanici sil
				cout
						<< "silmek istediğiniz kullncının tc kimlik numarasını giriniz "
						<< endl;
				cin >> tcNo; //silinecek user
				i = girisYapanA->findUser(personeller, 10, tcNo); // kullanıcı bulunursa indexi dödürür yoksa -1 dödürür
				if (i != -1) {

					girisYapanA->DeleteUser((User*) personeller[i]);
					if (anaMenuyeDon("kullanıcı silindi") == 'y')
						goto yoneticiMenu;
				} else if (anaMenuyeDon("user bulunamadı.") == 'y')
					goto yoneticiMenu;
				// silinecek user bulunamadı
			} else if (secilen == 3) { // Kisi Durumumu Goster
				cout << " kişinin tc kimlik numarasını giriniz " << endl;
				cin >> tcNo;
				if (!girisYapanA->ShowPersonState(personeller, 3, tcNo)) {
					// personel bulumadıysa
					if (anaMenuyeDon("personel bulunamadı.") == 'y')
						goto yoneticiMenu;
				} else if (anaMenuyeDon("") == 'y')
					goto yoneticiMenu;

			} else if (secilen == 4) { //4- Kullanıcı bul
				cout << "kullncının tc kimlik numarasını giriniz " << endl;
				cin >> tcNo;
				i = girisYapanA->findUser(personeller, 10, tcNo); // kullanıcı bulunursa indexi dödürür yoksa -1 dödürür
				if (i != -1) {
					girisYapanA->ShowUserState((User*) personeller[i]);
					if (anaMenuyeDon("") == 'y')
						goto yoneticiMenu;
				} else if (anaMenuyeDon("kullanıcı bulunamadı") == 'y')
					goto yoneticiMenu;
			} else if (secilen == 5) { //5- Kullanici Kartlarini Birlestir
				cout << "kullncının tc kimlik numarasını giriniz " << endl;
				cin >> tcNo;
				i = girisYapanA->findUser(personeller, 10, tcNo); // kullanıcı bulunursa indexi dödürür yoksa -1 dödürür
				if (i != -1) {
					girisYapanA->CombineUserCards((User*) personeller[i]);
					if (anaMenuyeDon("Kartlar Birlestirildi") == 'y')
						goto yoneticiMenu;
				} else if (anaMenuyeDon("kullanıcı bulunamadı") == 'y')
					goto yoneticiMenu;
			}
			 else if (secilen == 6) { // 6- İsim Soyisim değiştir
							cout << "kullncının tc kimlik numarasını giriniz " << endl;
							cin >> tcNo;
							cout<<"yeni ad giriniz"<<endl;
							cin>>ad;
							cout<<"yeni soyad giriniz"<<endl;
							cin>>soyad;
							i = girisYapanA->findUser(personeller, 10, tcNo); // kullanıcı bulunursa indexi dödürür yoksa -1 dödürür
							if (i != -1) {
								girisYapanA->changeNameSurname((User*) personeller[i],ad,soyad);
								if (anaMenuyeDon("isim ve soyisim değiştirildi ") == 'y')
									goto yoneticiMenu;
							} else if (anaMenuyeDon("kullanıcı bulunamadı") == 'y')
								goto yoneticiMenu;
						}
			 else if (secilen == 7) {
				 goto anaMenu;
			 }
			 else { cout<< "girdiğiniz numaraya dikkat ediniz !"<<endl;// kullanıcı seceneklerden farklı bir değer girerse

			 cin>>secilen;
			goto bas;}

		} else if(i==-1){
			if (anaMenuyeDon("girilen kullanıcı yönetici değildir.") == 'y')
				goto anaMenu;
		}

	}
	else if(secilen==2)//kullanıcı işlemleri
	{
				cout << "kullanıcı Girisi: " << endl << "TC giriniz" << endl;
				cin >> girilenTc;
                i=tempAdmin->findUser(personeller, 10, girilenTc);
				if (i != (-1)) {
					User *girisYapanK = ((User*) personeller[i]);
					kullaniciMenu: secilen = kullaniciMenu();
		            bas2:
					  int secilenKart,miktar;
					  if (secilen == 1) {//1- Bakiye Yukle
						  cout <<"yükleme miktarı"<<endl;
						   cin>>miktar;
                      cout <<"kart seç 1/2"<<endl;
                      cin>>secilenKart;
                      if(secilenKart==1){
                    	  girisYapanK->loadBalance(girisYapanK->userCart1,miktar);
                      }
                      else if(secilenKart==2){
                    	  girisYapanK->loadBalance(girisYapanK->userCart2,miktar);
                      }

                      if (anaMenuyeDon("yükleme yapılmış") == 'y')
                      	   goto kullaniciMenu;

					} else if (secilen == 2) { //2- Kart Okut
					   int ucret=10;// ornek
					                       cout <<"kart seç 1/2"<<endl;
					                       cin>>secilenKart;
					                       if(secilenKart==1){
					                     	  girisYapanK->ReadCard(girisYapanK->userCart1,ucret);
					                       }
					                       else if(secilenKart==2){
					                     	  girisYapanK->ReadCard(girisYapanK->userCart2,ucret);
					                       }

					                       if (anaMenuyeDon("işlem tamamlanmış") == 'y')
					                       	   goto kullaniciMenu;



					}
					 else if (secilen == 3) { // 3- Kart Durumu Goster
						 cout <<"kart seç 1/2"<<endl;
						                       cin>>secilenKart;
						                       if(secilenKart==1){
						                     	  girisYapanK->showCardState(girisYapanK->userCart1);
						                       }
						                       else if(secilenKart==2){
						                    	   girisYapanK->showCardState(girisYapanK->userCart2);
						                       }

						                       if (anaMenuyeDon("") == 'y')
						                       	   goto kullaniciMenu;

						 					}

					 else if (secilen == 4) {//Ana Menu
						 goto anaMenu;
					 }
					 else cout<< "girdiğiniz numaraya dikkat ediniz !"<<endl;// kullanıcı seceneklerden farklı bir değer girerse
					 cin>>secilen;
					goto bas2;

				} else {
					if (anaMenuyeDon("girilen kullanıcı  değildir.") == 'y')
						goto anaMenu;
				}

	} else if(secilen==3){//çikiş
		 exit(0);
	}

	return 0;
}

