#ifndef pracownik_H
#define pracownik_H

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class pracownik{
    public:
		pracownik(string im){imie=im;}
		pracownik(){ imie="0";}
		virtual ~pracownik() {cout << " d pracownik " << endl;}
		

	string	getimie() { return imie; }
	virtual void drukuj()=0;
	virtual int wyn()=0;
	virtual int getco()=0;//poprawione//


    protected:
	string	imie;			//imiê (losowe)

};

#endif