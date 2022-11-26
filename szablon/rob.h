#ifndef rob_H
#define rob_H

#include "pracownik.h"


class rob : public pracownik{
    public:
		rob(string im, int wyd, double ce){imie=im; wydajnosc=wyd; ce_rob=ce;}
		rob(){ imie="0"; wydajnosc=0; ce_rob=0;}
		~rob() {cout << " d rob " << endl;}

		double	getce_rob() { return ce_rob; }
		virtual void drukuj()	{cout<<" imie "<<imie<<" wydajnosc "<<wydajnosc<<" but " <<ce_rob<<endl;}
		

    private:
		double ce_rob;
		static const int wyn_rob;
    
};

#endif