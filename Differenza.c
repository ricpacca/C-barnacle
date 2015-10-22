#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Scrivi una funzione diff, che prenda in ingresso due stringhe,
rappresentanti due numeri interi (numero1>=numero2) codificati in base 10, 
e ritorni la loro differenza, sempre sotto forma di stringa.
NB: Deve funzionare anche con numeri molto grandi*/

char* diff (char* numero1, char* numero2) {
	int l1=strlen(numero1);
	int l2=strlen(numero2);
	long long int maxlen=l1>l2?l1:l2; //numero massimo di cifre da allocare
	
	char* somma = malloc(sizeof(char)*maxlen);
	somma[maxlen]='\0';
	maxlen--;
	
	int colonna=0, minuendo=0, sottraendo=0, ricordaprestito=0;
	
	for( ; l1>0 || l2>0; l1--, l2--, maxlen--) {
		
		if(l1>0 && l2>0) {
			minuendo=numero1[l1-1]-48;
			sottraendo=numero2[l2-1]-48;
			
			if(ricordaprestito==1 && minuendo!=0) {
				minuendo-=1;
				ricordaprestito=0;
			}
			
			if (minuendo==0 && sottraendo==0 && ricordaprestito==1) colonna=9;
			else if (minuendo>=sottraendo) colonna=minuendo-sottraendo;
			else {
				colonna = (10+minuendo-ricordaprestito)-sottraendo;
				ricordaprestito=1;
			}
		}
		
		else if (l2<=0) {
			minuendo=numero1[l1-1]-48;
			
			if(minuendo==0 && ricordaprestito==1) colonna=9;
			else {
				colonna=minuendo-ricordaprestito;
				ricordaprestito=0;
			}
		}
		
		if(colonna>=0 && colonna<=9) somma[maxlen] = colonna + 48;
		colonna=0;
	}
	
	if(colonna>=0 && colonna<=9) somma[maxlen] = colonna + 48;
	
	int i;
	for (i=0; i<maxlen; i++)
		somma[i]='0';
	/*pongo uguali a zero tutti gli elementi della stringa somma rimasti vuoti*/
	
	for ( ; *somma=='0'; somma++ ) ;
	
	return somma;
}

void main () {
	char* numero1 = "000000011874194323020102401200004817364287429834730102401000124010484710284711";
	char* numero2 = "9999487134178147928741410001024104910491001041999";
	char* risultato = diff(numero1, numero2);
	
	printf("%s", somma);
	FILE* f = fopen ("risultato.txt", "w");
	
	int i, zeri;
	int l1 = strlen(numero1);
	int l2 = strlen(numero2);
	zeri = l2>l1 ? l2-l1 : (l1-l2);
	
	char prima[zeri];
	for (i=0; i<zeri; i++) prima[i]='0';
	prima[i]='\0';
	
	fprintf(f, "%s -\n%s%s =\n%s", l2>l1?numero2:numero1, prima, l2>l1?numero1:numero2, risultato);
	fclose(f);
}
