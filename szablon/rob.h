#ifndef rob_H
#define rob_H

#include "pracownik.h"


class rob : public pracownik{
    public:
		rob(string im, double ce){imie=im;  ce_rob=ce;}
		rob(){ imie="0"; ce_rob=0;}
		~rob() {cout << " d rob " << endl;}

		double	getce_rob() { return ce_rob; }
		virtual int		wyn()	{return wyn_rob;}
		virtual void drukuj()	{cout<<" rob "<<imie<<"   wynagrodzenie "<<wyn_rob<<"   but " <<ce_rob<<endl;}
		

    private:
		double ce_rob;
		static const int wyn_rob=1;
    
};

#endif