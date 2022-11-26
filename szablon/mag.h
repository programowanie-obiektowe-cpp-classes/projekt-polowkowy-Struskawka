#ifndef mag_H
#define mag_H

#include "pracownik.h"


class mag : public pracownik{
    public:
		mag(string im, int wyd, bool ce){imie=im; wydajnosc=wyd; ce_mag=ce;}
		mag(){ imie="0"; wydajnosc=0; ce_mag="0";}
		~mag() {cout << " d mag " << endl;}

		bool	getce_mag() { return ce_mag; }
		virtual void drukuj()	{cout<<" imie "<<imie<<" wydajnosc "<<wydajnosc<<" but " <<ce_mag<<endl;}


    private:
		bool ce_mag;
		static const int wyn_mag;
    
};

#endif