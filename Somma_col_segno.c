#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Scrivi una funzione SumDiff, che prenda in ingresso due stringhe,
rappresentanti due numeri interi codificati in base 10, con un segno (+ o -)
davanti, e ritorni la loro somma, sempre sotto forma di stringa con segno.
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
			
			if (minuendo==0 && sottraendo==0 && ricordaprestito==1) { colonna=9; }
			
			else if (minuendo>=sottraendo) {
				colonna=minuendo-sottraendo;
			}
			
			else {
				colonna = (10+minuendo-ricordaprestito)-sottraendo;
				ricordaprestito=1;
			}
		}
		
		else if (l2<=0) {
			minuendo=numero1[l1-1]-48;
			
			if(minuendo==0 && ricordaprestito==1) {
				colonna=9;
			}
			
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
	for (i=0; i<maxlen; i++) {
		somma[i]='0';
	} /*pongo uguali a zero tutti gli elementi della stringa somma rimasti vuoti*/
	
	for ( ; *somma=='0'; somma++ ) ;
	
	return somma;
}

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

char* SumDiff (char* numero1, char* numero2) {
	int l1=strlen(numero1);
	int l2=strlen(numero2);
	char* ris = malloc (sizeof(char)*(l1*l2));
	
	if (numero1[0]=='+' && numero2[0]=='+') {
		*numero1++;
		*numero2++;
		ris[0]='+';
		ris[1]='\0';
		return strcat(ris, sum(numero1, numero2));
	}
	
	if (numero1[0]=='-' && numero2[0]=='-') {
		*numero1++;
		*numero2++;
		ris[0]='-';
		ris[1]='\0';
		return strcat(ris, sum(numero1, numero2));
	}
	
	if (numero1[0]=='-'&& numero2[0]=='+') {
		*numero1++;
		*numero2++;
		
		int i=1;
		for(; numero1[i]==numero2[i]; i++) ;
		if (l1==l2 && i==l1) return "0";
		
		if(l1>l2 || (l1==l2 && numero1[i]>numero2[i]) ) {
			ris[0]='-';
			ris[1]='\0';
			return strcat(ris, diff(numero1, numero2));
		}
		
		if(l2>l1 || (l1==l2 && numero1[i]<numero2[i]) ) {
			ris[0]='+';
			ris[1]='\0';
			return strcat(ris, diff(numero2, numero1));
		}
	}
	
	if (numero1[0]=='+'&& numero2[0]=='-') {
		*numero1++;
		*numero2++;
		
		int i=1;
		for(; numero1[i]==numero2[i]; i++) ;
		if (l1==l2 && i==l1) return "0";
		
		if(l1>l2 || (l1==l2 && numero1[i]>numero2[i]) ) {
			ris[0]='+';
			ris[1]='\0';
			return strcat(ris, diff(numero1, numero2));
		}
		
		if(l2>l1 || (l1==l2 && numero1[i]<numero2[i]) ) {
			ris[0]='-';
			ris[1]='\0';
			return strcat(ris, diff(numero2, numero1));
		}
	}
}

void main () {
	char* numero1 = "+1234567898766543221338434858358385385299239230249201851851";
	char* numero2 = "-66543221338434858358385385299239230249201851859";
	char* somma = SumDiff(numero1, numero2);
	
	printf("%s", somma);
	FILE* f = fopen ("risultato.txt", "w");
	
	int i, zeri;
	int l1 = strlen(numero1);
	int l2 = strlen(numero2);
	zeri = l2>l1 ? l2-l1 : (l1-l2);
	
	char prima[zeri];
	for (i=0; i<zeri; i++) prima[i]=' ';
	prima[i]='\0';
	
	fprintf(f, "%s\n%s%s =\n%s", l2>l1?numero2:numero1, prima, l2>l1?numero1:numero2, somma);
	fclose(f);
}
