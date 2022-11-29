#ifndef mag_H
#define mag_H

#include "pracownik.h"


class mag : public pracownik{
    public:
		mag(string im, bool ce){imie=im; ce_mag=ce;}
		mag(){ imie="0"; ce_mag="0";}
		~mag() {cout << " d mag " << endl;}

		bool	getce_mag() { return ce_mag; }
		virtual int		wyn()	{return wyn_mag;}
		virtual void drukuj()	{cout<<" mag "<<imie<<"   wynagrodzenie "<<wyn_mag<<"   wozek ";if(ce_mag==false)cout<<"nie"<<endl; else cout<<"tak"<<endl;}


    private:
		bool ce_mag;
		static const int wyn_mag=1;
    
};

#endif