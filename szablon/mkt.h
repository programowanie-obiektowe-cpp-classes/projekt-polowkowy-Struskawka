#ifndef mkt_H
#define mkt_H

#include "pracownik.h"


class mkt : public pracownik{
    public:
		mkt(string im, int wyd, int ce){imie=im; wydajnosc=wyd; ce_mkt=ce;}
		mkt(){ imie="0"; wydajnosc=0; ce_mkt=0;}
		~mkt() {cout << " d mkt " << endl;}

		int	getce_mkt() { return ce_mkt; }
		virtual void drukuj()	{cout<<" imie "<<imie<<" wydajnosc "<<wydajnosc<<" but " <<ce_mkt<<endl;}


    private:
		int ce_mkt;
		static const int wyn_mkt;
    
};

#endif