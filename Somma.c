#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Scrivi una funzione sum, che prenda in ingresso due stringhe,
rappresentanti due numeri interi codificati in base 10, e ritorni
la loro somma, sempre sotto forma di stringa.
NB: Deve funzionare anche con numeri molto grandi*/

char* sum (char* numero1, char* numero2) {
	int l1=strlen(numero1);
	int l2=strlen(numero2);
	long long int maxlen=l1*l2; //numero massimo di cifre da allocare
	
	char* somma = malloc(sizeof(char)*maxlen);
	somma[maxlen]='\0';
	
	int riporto=0;
	int colonna=0;
	maxlen--;
	
	for( ; l1>0 || l2>0; l1--, l2--, maxlen--) {
		
		if(l2>0 && l1>0) {
			colonna=(numero2[l2-1]-48)+(numero1[l1-1]-48);
		}
		else if (l1<=0) {
			colonna=numero2[l2-1]-48;
		}
		else if (l2<=0) {
			colonna=numero1[l1-1]-48;
		}
		
		riporto=riporto+colonna;
		somma[maxlen] = (riporto%10) + 48;
		riporto=riporto/10;
	
	}
	
	somma[maxlen] = (riporto%10) + 48;
	
	int i;
	for (i=0; i<maxlen; i++) {
		somma[i]='0';
	} /*pongo uguali a zero tutti gli elementi della stringa somma rimasti vuoti*/
	
	for ( ; *somma=='0'; somma++) ;
	
	return somma;
}

void main () {
	char* numero1 = "1234567898766543221338434858358385385299239230249201851851";
	char* numero2 = "131397461357693619845691823756912837569128735691823756198375691823518";
	char* somma = sum(numero1, numero2);
	
	printf("%s", somma);
	FILE* f = fopen ("risultato.txt", "w");
	
	int i, zeri;
	int l1 = strlen(numero1);
	int l2 = strlen(numero2);
	zeri = l2>l1 ? l2-l1 : (l1-l2);
	
	char prima[zeri];
	for (i=0; i<zeri; i++) prima[i]='0';
	prima[i]='\0';
	
	fprintf(f, "%s%s +\n%s =\n%s", prima, l2>l1?numero1:numero2, l2>l1?numero2:numero1, somma);
	fclose(f);
}
