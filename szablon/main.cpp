#include <iostream>
#include <conio.h>
#include <string>

#include "pracownik.h"
#include "inz.h"
#include "mag.h"
#include "mkt.h"
#include "rob.h"
#include "firma.h"

using namespace std;

int main()
{

	firma fi;

	for(int i=0; i<4; ++i){fi.zatrudnij(i);}

	fi.drukuj_prac();



system("pause")	;
return(0);
}
