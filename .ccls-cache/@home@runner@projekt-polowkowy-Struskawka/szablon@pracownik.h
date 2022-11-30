#ifndef pracownik_H
#define pracownik_H

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class pracownik{
    public:
		pracownik(string im, int wyd){imie=im; wydajnosc=wyd;}
		pracownik(){ imie="0"; wydajnosc=0;}
		virtual ~pracownik() {cout << " d pracownik " << endl;}


	string	getimie() { return imie; }
	int		getwydajnosc() { return wydajnosc; }
	virtual void drukuj()=0;


    protected:
	string	imie;			//imiê (losowe)
    int		wydajnosc;		//wydajnoœæ (indywidualna)

};

#endif