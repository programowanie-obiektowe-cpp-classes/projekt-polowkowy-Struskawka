#ifndef mkt_H
#define mkt_H

#include "pracownik.h"


class mkt : public pracownik{
    public:
		mkt(string im, int ce){imie=im; ce_mkt=ce;}
		mkt(){ imie="0"; ce_mkt=0;}
		~mkt() {cout << " d mkt " << endl;}

		int	getce_mkt() { return ce_mkt; }
		virtual int		wyn()	{return wyn_mkt;}
		virtual void drukuj()	{cout<<" mkt "<<imie<<"   wynagrodzenie "<<wyn_mkt<<"   obserwujacy " <<ce_mkt<<endl;}


    private:
		int ce_mkt;
		static const int wyn_mkt=1;
    
};

#endif