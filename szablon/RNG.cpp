#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

string losowy_wydzial() {
	int numer=rand() % 16;
	//cout<<endl<<numer<<endl;
 string wydzialy[] = {" Chemiczny",
	 " Elektroniki i Technik Informacyjnych",
	 " Elektryczny",
	 " Fizyki",
	 " Geodezji i Kartografii",
	 " Instalacji Budowlanych, Hydrotechniki i Inzynierii Srodowiska",
	 " Inzynierii Chemicznej i Procesowej",
	 " Inzynierii Ladowej",
	 " Inzynierii Materia³owej",
	 " Matematyki i Nauk Informacyjnych",
	 " Mechaniczny Energetyki i Lotnictwa",
	 " Mechaniczny Technologiczny",
	 " Mechatroniki",
	 " Samochodow i Maszyn Roboczych",
	 " Transportu",
	 " Zarzadzania"};

  return wydzialy[numer];
}


string losowe_imie() {
	int length=rand() % 4+4;
  char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char vowels[] = {'a','e','i','o','u','y'};

  string name = "";

  int random = rand() % 2;
  int count = 0;

  for(int i = 0; i < length; i++) {

    if(random < 2 && count < 2) {
      name = name + consonents[rand() % 19];
      count++;
    }
    else {
      name = name + vowels[rand() % 5];
      count = 0;
    }
    random = rand() % 2;
  }
  return name;
}

	double losowy_but(){double but=rand() % 800+3600;return but/100;}
	int losowy_follow(){int fol=rand() % 1000+100;return fol;}
	bool losowy_wozek(){bool woz=rand() % 2;return woz;}