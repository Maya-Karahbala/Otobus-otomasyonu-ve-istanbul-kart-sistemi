# include <stdio.h>
# include <stdlib.h>
#include <conio.h>
#include <string.h>
//#define clrscr() printf("\e[1;1H\e[2J")
#define bool int
#define true 1
#define false 0
enum gunler {
	pazartesi, sali, carsamba, persembe, cume, cumartesi, pazar
} gun;
enum cinsiyet {
	kiz, erkek
} cinsiyet1, cinsiyet2;
typedef struct Musteri {
	char isim[30];
	char soyisim[30];
	long int tcNo;
	enum cinsiyet cin;
};
struct koltuk {
	int no;
	bool doluMu;
	struct Musteri m;
	enum gunler gun;

};
struct otobus {
	char plaka[30];
	char marka[30];
	int model;
	//int myArray[SIZE] = {1,2,3,4....};
	struct koltuk koltuklar[10][4];

};

	  // system("cls");
	  //clrscr();
	  //cls( GetStdHandle( STD_OUTPUT_HANDLE ));
	  // system("@cls||clear");
    int anaMenu() {
     // system("cls");
	int secilen;
	puts("\t\tGidereGider Turizm");
	puts("1-Otobüs durumu göster.");
	puts("2-Koltuk satış.");
	puts("3-Kişi arama.");
	puts("4-Çıkış.");
	puts("\t\tlütfen seçim yapınız");
	scanf("%d", &secilen);
	return secilen;
}
//void otobusDurumuYazdir(struct koltuk koltuklar[10][4]) {
	void otobusDurumuYazdir(struct otobus o) {
		printf("\t\t%s\n",o.plaka);
		printf("\t\t%s\n",o.marka);
		printf("\t\t%d\n",o.model);
	int i, j;
		for (i = 0; i < 10; ++i) {
			for (j = 0; j < 4; ++j) {

				if (o.koltuklar[i][j].doluMu == false) {
					printf("%d\t", o.koltuklar[i][j].no);
				} else if (o.koltuklar[i][j].doluMu == true) {
					if (o.koltuklar[i][j].m.cin == 0)
						printf("x\t");
					else
						printf("o\t");
				}
			}
			printf("\n");
		}
}
struct Musteri *musteriOlustur() {
	setbuf(stdout, NULL);
	long int tc;
	char cinsiyetChar;
	char isim[30], soyisim[30];


	puts("-Müşteri bilgileri giriniz");
	printf("isim : ");
	scanf("%s", &isim);
	printf("soyisim : ");
    scanf("%s" ,&soyisim);
	printf("tc : , Cinsiyet  k/e :");
	scanf("%ld ", &tc);
	//printf("Cinsiyet  k/e :");
	scanf(" %c", &cinsiyetChar);
	printf("\n");
	enum cinsiyet cin;
	if (cinsiyetChar == 'k')
		cin = kiz;
	else if (cinsiyetChar == 'e')
		cin = erkek;
	struct Musteri *m = malloc(sizeof(struct Musteri));
	strcpy(m->isim, isim);
	strcpy(m->soyisim, soyisim);
	m->tcNo = tc;
	m->cin = cin;

	return m;
}
void koltukSatis(struct otobus *o) {
	char *gunlerDizisi[7]={"pazartesi","sali","carsamba","persembe","cume","cumartesi","pazar"};
	satis:puts("\t\tKOLTUK SATIS");
	struct Musteri *m = musteriOlustur();
	puts("-koltuk bilgileri");
	int num = 666,i, j;
	char gun2[10];
	do {
bas:	printf("No :");
		scanf("%d", &num);
		printf("gun :");
		scanf("%s", &gun2);
		if (num > 40 || num < 1) {
			puts("Koltuk no 1-40 arası olmalı");
			goto bas;
		}
		for (i = 0; i < 10; ++i) {
			for (j = 0; j < 4; ++j) {
				if (o->koltuklar[i][j].no == num && o->koltuklar[i][j].doluMu == true) {
					puts("Koltuk boş değil !");
					goto bas;
				}
				else if (o->koltuklar[i][j].no
						== num&&o->koltuklar[i][j].doluMu==false) {
					o->koltuklar[i][j].doluMu=true;
					o->koltuklar[i][j].m.cin=m->cin;
					o->koltuklar[i][j].m.tcNo=m->tcNo;
					strcpy(o->koltuklar[i][j].m.isim,m->isim);
					strcpy(o->koltuklar[i][j].m.soyisim,m->soyisim);
					int i;
                    for (i = 0; i < 7; ++i) {
                    	if(!strcmp(gun2,gunlerDizisi[i]))o->koltuklar[i][j].gun=i;
					}
					goto dis;
				}
			}
		}
	} while (true);
	dis: puts("İşlem tamamlanmıştır.");
   puts("Yeni koltuk satısı yapmak ister misiniz? y/n");
   char secim='a';
   scanf(" %c",&secim);
   if(secim=='y')goto satis;
}
void kisiArama(struct otobus o){
	puts("KISI ARAMA");
	long int girilenTc=0;
	bool bulunduMu=false;
	arama: printf("Tc :");
	scanf("%ld",&girilenTc);
	int i,j;
	char cinsiyeti[10]="";
	for (i = 0; i < 10; ++i) {
		for (j = 0; j < 4; ++j) {
			if(o.koltuklar[i][j].m.tcNo==girilenTc){
				puts("Müşteri bilgileri");
				printf("%s\n",o.koltuklar[i][j].m.isim);
				printf("%s\n",o.koltuklar[i][j].m.soyisim);
				printf("%d\n",o.koltuklar[i][j].m.tcNo);
				if(o.koltuklar[i][j].m.cin==1)strcpy(cinsiyeti,"erkek");
				else strcpy(cinsiyeti,"kız");
				printf("%s\n",cinsiyeti);
				bulunduMu=true;
				break;
			}
			}
	}
if(!bulunduMu){
	puts("girdiğniz bilgilere dikkat ediniz, kişi bulunamadı !");
	goto arama;
}
puts("yeni kişi arama yapmak ister misiniz? y/n”");
  char secim='a';
  scanf(" %c",&secim);
  if(secim=='y')goto arama;
}
void cikis(struct otobus o){
	FILE *f;
	f=fopen("otobus.txt","w");
	fputs(" ",f);
	int i, j;
	struct Musteri musteri;
		for (i = 0; i < 10; ++i) {
			for (j = 0; j < 4; ++j) {
				musteri=o.koltuklar[i][j].m;
				if (o.koltuklar[i][j].doluMu == true) {
					if (musteri.cin == 0){
						fprintf(f,"%d-%s-%s-%d-%d-%s-\n", o.koltuklar[i][j].no,musteri.isim,musteri.soyisim,musteri.tcNo,musteri.cin,"D");
					   //fprintf(f,"x\t\n");
					}
					else{
						fprintf(f,"%d-%s-%s-%d-%d-%s-\n", o.koltuklar[i][j].no,musteri.isim,musteri.soyisim,musteri.tcNo,musteri.cin,"D");
					}
				}
				else if(o.koltuklar[i][j].doluMu == false){
					fprintf(f,"%d%s\n",o.koltuklar[i][j].no,"-0-0-0-0-B-");
				}
			}

		}
		exit(0);
}
		void setOtobusDurumu(struct otobus *o){
			int i, j, sayac = 1;
				for (i = 0; i < 10; ++i) {
					for (j = 0; j < 4; ++j) {
						o->koltuklar[i][j].doluMu = false;
						o->koltuklar[i][j].no = sayac++;
						o->koltuklar[i][j].gun = gun;
					}
				}
		  	FILE * f;
		  	    int c;
		  	    char satir[1000];
		  	  char *bilgiler[6];
		  	   sayac=0;
		  	char *kelime;
		  	  if((f=fopen("otobus.txt","r"))!=NULL){
		  	  		//puts("açıldı");
		  	  	}
		  	start: while((c=getc(f))!=EOF){
		  				fscanf(f,"%s", satir);
		  				 kelime=strtok(satir,"-");
		  				 sayac=0;
		  				 while (kelime!=NULL) {
						    bilgiler[sayac]=kelime;
		  					kelime=strtok(NULL,"-");
		  				//	printf(" %s  * \t",bilgiler[sayac]);
		  					sayac++;
		  						 }
                        //   printf("\n");
                           //int temp=0;
		  				 for (i = 0; i < 10; ++i) {
							for (j = 0; j < 4; ++j) {
								//printf("%d \t i %d\t j %d\t\t",temp++,i,j);
                                // printf("%d\t%dx\n",o->koltuklar[i][j].no,atoi(bilgiler[0]));
                                 // sadece dolu olanların bilgilerini okuyor
								if(o->koltuklar[i][j].no==atoi(bilgiler[0])&&!strcmp(bilgiler[5],"D")){
									o->koltuklar[i][j].doluMu=true;
									strcpy(o->koltuklar[i][j].m.isim,bilgiler[1]);
									strcpy(o->koltuklar[i][j].m.soyisim,bilgiler[2]);
									o->koltuklar[i][j].m.tcNo=atoi(bilgiler[3]);
									o->koltuklar[i][j].m.cin=atoi(bilgiler[4]);

									//printf("%d/%s/%s/\n",o->koltuklar[i][j].m.tcNo,o->koltuklar[i][j].m.isim,o->koltuklar[i][j].m.soyisim);
									goto start;
									//break;

								}
							}
					}


		  			}
		  			  fclose (f);
		  			// printf("l%d/%d/%d/%s/%s/\n",o->koltuklar[0][0].m.cin,o->koltuklar[0][0].m.tcNo,o->koltuklar[0][0].no,o->koltuklar[0][0].m.isim,o->koltuklar[0][0].m.soyisim);

}

int main() {

	setbuf(stdout, NULL);

	int secilen;
	cinsiyet1 = kiz;
	cinsiyet2 = erkek;
	gun = pazartesi;
	struct koltuk koltuklar[10][4];
	struct otobus o = { "432As", "MERCEDES", 1523, koltuklar};

	setOtobusDurumu(&o);
	/*// filden değil elle otobus ilk durumu bilirlemek
	 * struct Musteri m1 = { "maya", "kara", 1234, cinsiyet1 };
	struct Musteri m2 = { "sara", "kara", 243, cinsiyet1 };
	struct Musteri m3 = { "said", "kara", 2948, cinsiyet2 };*/
	//struct Musteri m4 = { "ali", "kara", 2123, cinsiyet2 };
	/*int i, j, sayac = 1;
	for (i = 0; i < 10; ++i) {
		for (j = 0; j < 4; ++j) {
			o.koltuklar[i][j].doluMu = false;
			o.koltuklar[i][j].no = sayac++;
			o.koltuklar[i][j].gun = gun;
		}
	}*/


	/*o.koltuklar[0][0].doluMu = true;
	o.koltuklar[0][0].m = m1;
	//
	o.koltuklar[2][3].doluMu = true;
	o.koltuklar[2][3].m = m2;
	//
	o.koltuklar[5][3].doluMu = true;
	o.koltuklar[5][3].m = m3;

	o.koltuklar[9][3].doluMu = true;
   o.koltuklar[9][3].m = m4;
*/

   do {
	     secilen=0;
	  	 secilen=anaMenu();
	    if (secilen==4){
	  		 cikis(o);
	  		 break;
	  	 }
	    else if(secilen==1)otobusDurumuYazdir(o);
	 else if(secilen==2)koltukSatis(&o);
	 else if(secilen==3)kisiArama(o);

	 else if(secilen!=NULL) puts("girdiğiniz numaraya dikkat ediniz");

	} while(secilen!=0);



}

