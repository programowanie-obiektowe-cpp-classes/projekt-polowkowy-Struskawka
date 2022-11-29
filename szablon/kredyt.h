#ifndef kredyt_H
#define kredyt_H

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class kredyt{
    public:
		kredyt(double dl, int po_ra){dlug=dl; pozostale_raty=po_ra;}
		//kredyt(){dlug=0; pozostale_raty=0;}
		virtual ~kredyt() {cout << " d kredyt " << endl;}

		int	getraty() { return pozostale_raty; }

		virtual void drukuj_k()	{cout<<" dlug "<<dlug<<" pozostale raty "<<pozostale_raty<<endl;}
		double		rata()	{double zap=dlug/pozostale_raty; dlug=dlug-zap; pozostale_raty--; if(pozostale_raty==0)dlug=0; return zap;}


    protected:
	double	dlug;
    int		pozostale_raty;
	

};

#endif