#ifndef inz_H
#define inz_H

#include "pracownik.h"

class inz : public pracownik{
    public:
		inz(string im, int wyd, string ce){imie=im; wydajnosc=wyd; ce_inz=ce;}
		inz(){ imie="0"; wydajnosc=0; ce_inz="0";}
		~inz() {cout << " d inz " << endl;}

		string	getce_inz() { return ce_inz; }
		virtual void drukuj()	{cout<<" imie "<<imie<<" wydajnosc "<<wydajnosc<<" but " <<ce_inz<<endl;}



    private:
		string ce_inz;
		static const int wyn_inz;
    
};

#endif