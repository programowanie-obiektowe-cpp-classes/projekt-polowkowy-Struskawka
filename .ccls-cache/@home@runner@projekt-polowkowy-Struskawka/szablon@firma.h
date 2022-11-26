#ifndef firma_H
#define firma_H

#include "pracownik.h"
#include "inz.h"
#include "mag.h"
#include "mkt.h"
#include "rob.h"


class firma {
    public:
		//firma(double kon, int n){stan_konta=kon; n_prac=n;}
		firma(){stan_konta=0; n_prac=0;}
		~firma() {cout << " d firma " << endl;}

		double	getstan_konta() { return stan_konta; }
		void    set_pracownik(pracownik* prac, int n) {prac_tab[n]=prac;}

		void drukuj_prac() {for(int i=0; i<max_prac; ++i){prac_tab[i]->drukuj();}}
		
		void zatrudnij (int typ){	
				if(typ==0)prac_tab[n_prac]=new inz("marek0",0,"meil");
				if(typ==1)prac_tab[n_prac]=new mag("marek1",1,1);
				if(typ==2)prac_tab[n_prac]=new mkt("marek2",2,24);
				if(typ==3)prac_tab[n_prac]=new rob("marek3",3,1.2);
			n_prac++;
		}



	friend class pracownik;

    private:
	double stan_konta;
	int n_prac;
	static const int max_prac=4;
	pracownik *prac_tab[max_prac];
    
};

#endif