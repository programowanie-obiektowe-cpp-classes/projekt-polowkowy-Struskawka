#ifndef firma_H
#define firma_H

#include "pracownik.h"
#include "inz.h"
#include "mag.h"
#include "mkt.h"
#include "rob.h"
#include "kredyt.h"
#include "RNG.h"


class firma {
    public:
		//firma(double kon, int n){stan_konta=kon; n_prac=n;}
		firma(){stan_konta=100; n_prac=0; n_kred=0; n_inz=0; n_mag=0; n_mkt=0; n_rob=0; wartosc_firmy=0; his_i=0;}
		~firma() {cout << " d firma " << endl;}

		double	getstan_konta() { return stan_konta; }
		void    set_stan_konta(double kw) { stan_konta=kw;}
		void	drukuj_stan_konta(){cout<<" stan konta: "<<stan_konta<<endl;}
//-----------------------------------------------------------------------------------------------------------------------------
//drukuj_pracownikow	
		void drukuj_prac() {cout<< "lista pracownikow"<<endl; for(int i=0; i<n_prac; i++){cout<<i+1<<" "; prac_tab[i]->drukuj();}}
//zatrudnij	
		int getn_prac(){ return n_prac; }
		int getmax_prac(){ return max_prac; }
	
		void zatrudnij (int typ){	
				
				if(typ==0){prac_tab[n_prac]=new inz(losowe_imie(),losowy_wydzial());n_inz++;}
				if(typ==1){prac_tab[n_prac]=new mag(losowe_imie(),losowy_wozek());n_mag++;}
				if(typ==2){prac_tab[n_prac]=new mkt(losowe_imie(),losowy_follow());n_mkt++;}
				if(typ==3){prac_tab[n_prac]=new rob(losowe_imie(),losowy_but());n_rob++;}
				n_prac++;}

//oblicz_przych
		double oblicz_przych(){
			int licz_prod=n_rob*prac_tab[0]->getcorob();		cout<<" teor_licz_prod---"<<licz_prod<<endl;
			int poj_mag=n_mag*prac_tab[0]->getcomag();			cout<<" poj_mag----------"<<poj_mag<<endl;
			if(poj_mag<licz_prod)licz_prod=poj_mag;				cout<<" licz_prod--------"<<licz_prod<<endl;
			int popyt=n_mkt*prac_tab[0]->getcomkt();			cout<<" popyt------------"<<popyt<<endl;
			if(licz_prod>popyt)licz_prod=popyt;					cout<<" licz_sprzed_prod-"<<licz_prod<<endl;
			int cena=n_inz*prac_tab[0]->getcoinz();				cout<<" cena-------------"<<cena<<endl;
			                                                    cout<<" przychod---------"<<cena*licz_prod<<endl;
			return cena*licz_prod;}
//-----------------------------------------------------------------------------------------------------------------------------
//wez_kredyt
		int getn_kred(){ return n_kred; }
		int getmax_kred(){ return max_kred; }

		void wez_kredyt(double kwota, int raty){
				stan_konta=stan_konta+kwota;
				int i=0;
				while(dost_kred[i]!=0)i++;
				kred_tab[i]=new kredyt(kwota, raty);
				dost_kred[i]=1;
				n_kred++;
			}
//drukuj_kred
		void drukuj_kred() {for(int i=0; i<max_kred; i++){if(dost_kred[i]==1)kred_tab[i]->drukuj_k();}}
//wyczysc
		void wyczysc_k(){for(int i=0;i<max_kred;i++)dost_kred[i]=0;}
//splac_raty
		void zaplac_raty(){double suma_rat=0;
			for(int i=0; i<max_kred; i++){
			if(dost_kred[i]==1){
				suma_rat=suma_rat+kred_tab[i]->rata();
				if(kred_tab[i]->getraty()==0){dost_kred[i]=0;delete kred_tab[i];n_kred--;}}}
			stan_konta=stan_konta-suma_rat;  cout<<endl<<" raty-------------"<<suma_rat<<endl;}
//-----------------------------------------------------------------------------------------------------------------------------
//zaplac_wyn
		void zaplac_wyn(){double suma_wyn=0;
			for(int i=0; i<n_prac; i++){suma_wyn=suma_wyn+prac_tab[i]->wyn();}
			stan_konta=stan_konta-suma_wyn;  cout<<endl<<" wynagrodzenia----"<<suma_wyn<<endl;}
//-----------------------------------------------------------------------------------------------------------------------------
//otrzymaj_przychod
		void otrzymaj_dochod(){
			double przych=oblicz_przych();
			his_przych[his_i]=przych; his_i++; if(his_i==historia)his_i=0;
			stan_konta=stan_konta+przych;zaplac_raty();zaplac_wyn();
			cout<<endl; drukuj_stan_konta(); cout<<" wartosc firmy: "<<getwartosc_firmy()<<endl<<endl;}
//-----------------------------------------------------------------------------------------------------------------------------
//wyczysc
		void wyczysc_h(){for(int i=0;i<historia;i++)his_przych[i]=0;}
//wartosc_firmy
		void policz_wartosc_firmy(){double suma=0;for(int i=0;i<historia;i++)suma=suma+his_przych[i];wartosc_firmy=suma/historia;}
		double	getwartosc_firmy() { policz_wartosc_firmy(); return wartosc_firmy; }
		
	

	friend class pracownik;
	friend class kredyt;
    private:
	double stan_konta;

	static const int historia=6;
	int his_i;
	double his_przych[historia];
	double wartosc_firmy;
	
	int n_kred;
	static const int max_kred=1000;
	bool dost_kred[max_kred];
	kredyt *kred_tab[max_kred];

	int n_prac;
	int n_inz, n_mag, n_mkt, n_rob;
	static const int max_prac=1000;
	pracownik *prac_tab[max_prac];
    
};

#endif