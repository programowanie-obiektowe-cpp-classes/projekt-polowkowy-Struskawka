#ifndef inz_H
#define inz_H

#include "pracownik.h"


class inz : public pracownik{
    public:
		inz(string im, string ce){imie=im;ce_inz=ce;}
		inz(){ imie="0";ce_inz="0";}
		~inz() {cout << " d inz " << endl;}

		string	getce_inz() { return ce_inz; }
		virtual int		wyn()	{return wyn_inz;}
		virtual void drukuj()	{cout<<" inz "<<imie<<"   wynagrodzenie "<<wyn_inz<<"   wydzial "<<ce_inz<<endl;}
		virtual int getco(){return 2;} //CI//poprawione//



    private:
		string ce_inz;
		static const int wyn_inz=1;
    
};

#endif