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
		
		int getcoinz(){return 2;} //CI
		int getcomag(){return 3;} //CMag
		int getcomkt(){return 4;} //CMkt
		int getcorob(){return 5;} //CR

	string	getimie() { return imie; }
	virtual void drukuj()=0;
	virtual int wyn()=0;


    protected:
	string	imie;			//imiê (losowe)

};

#endif