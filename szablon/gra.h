#ifndef gra_H
#define gra_H

#include "pracownik.h"
#include "inz.h"
#include "mag.h"
#include "mkt.h"
#include "rob.h"
#include "kredyt.h"
#include "firma.h"

using namespace std;


class gra {
    public:
		~gra() {cout << " d gra " << endl;}

		gra(){	tura=1; 
		firma fi;
		fi.wyczysc_k();
		fi.wyczysc_h();
		for(int i=0; i<4; ++i){fi.zatrudnij(i);}
		fi.set_stan_konta(konto_start);
		fi.drukuj_prac();
		fi.drukuj_stan_konta();
nowa_tura:
		if(fi.getwartosc_firmy()>=cel)cout<<endl<<endl<<"WYGRANA"<<endl<<endl;
		else if(fi.getstan_konta()<=0)cout<<endl<<endl<<"PRZEGRANA"<<endl<<endl;
		else if(fi.getstan_konta()>0&&fi.getwartosc_firmy()<=cel){
wybierz_opcje:
		cout<<endl<<"tura: "<<tura<<endl;
		cout<<endl<<"wybierz opcje:"<<endl;
		cout<<"1. wylistuj pracownikow"<<endl<<"2. wylistuj kredyty"<<endl<<"3. podaj wartosc spolki"<<endl<<"4. podaj stan konta"<<endl;
		cout<<"5. zatrudnij inz."<<endl<<"6. zatrudnij mag."<<endl<<"7. zatrudnij mkt."<<endl<<"8. zatrudnij rob."<<endl;
		cout<<"9. wez kredyt"<<endl<<"0. zakoncz ture"<<endl;
		int opcja; cin>>opcja; while(opcja<0||opcja>9){cout<<"nie ma takiej opcji"<<endl; cin>>opcja;}


		switch (opcja) {
					case 1:	{cout<<endl;fi.drukuj_prac();cout<<endl;system("pause");goto wybierz_opcje;}
					case 2:	{cout<<endl;fi.drukuj_kred();cout<<endl;system("pause");goto wybierz_opcje;}
					case 3:	{cout<<endl;cout<<"wartosc firmy: "<<fi.getwartosc_firmy()<<endl<<endl;system("pause");goto wybierz_opcje;}
					case 4:	{cout<<endl;cout<<"stan konta: "<<fi.getstan_konta()<<endl<<endl;system("pause");goto wybierz_opcje;}
					
					case 5: {if(fi.getn_prac()>=fi.getmax_prac()){cout<<endl<<" maksymalna ilosc pracownikow "<<endl<<endl;}
							else{fi.zatrudnij(0);cout<<endl<<"zatrudniono inz"<<endl<<endl;}
							system("pause");goto wybierz_opcje;} 

					case 6:	{if(fi.getn_prac()>=fi.getmax_prac()){cout<<endl<<" maksymalna ilosc pracownikow "<<endl<<endl;}
							else{fi.zatrudnij(1);cout<<endl<<"zatrudniono mag"<<endl<<endl;}
							system("pause");goto wybierz_opcje;}

					case 7:	{if(fi.getn_prac()>=fi.getmax_prac()){cout<<endl<<" maksymalna ilosc pracownikow "<<endl<<endl;}
							else{fi.zatrudnij(2);cout<<endl<<"zatrudniono mkt"<<endl<<endl;}
							system("pause");goto wybierz_opcje;}

					case 8:	{if(fi.getn_prac()>=fi.getmax_prac()){cout<<endl<<" maksymalna ilosc pracownikow "<<endl<<endl;}
							else{fi.zatrudnij(3);cout<<endl<<"zatrudniono rob"<<endl<<endl;}
							system("pause");goto wybierz_opcje;}

					case 9:	{if(fi.getn_kred()>=fi.getmax_kred()){cout<<endl<<" maksymalna ilosc kredytow "<<endl<<endl;}
							else{double kwota; int czas; 
							cout<<endl<<"podaj kwote kredytu: "; cin>>kwota; while(kwota<=0){cout<<"niepoprawna kwota"<<endl; cin>>kwota;}
							cout<<"podaj ilosc rat "; cin>>czas; while(czas<=0){cout<<"niepoprawna ilosc rat"<<endl; cin>>czas;}
							fi.wez_kredyt(kwota, czas);cout<<endl<<" wzieto "<<kwota<<" kredytu, ilosc rat: "<<czas<<", wartosc raty: "<<kwota/czas<<endl<<endl;}
							system("pause");goto wybierz_opcje;}

					case 0:	{fi.otrzymaj_dochod();tura++;system("pause");goto nowa_tura;}
					}	
				}

		}


	private:
	int tura;
	static const int konto_start=500;
	static const int cel=12;
    
};

#endif