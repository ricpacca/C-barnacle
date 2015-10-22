#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sum (char* numero1, char* numero2) {
	int l1=strlen(numero1);
	int l2=strlen(numero2);
	long long int maxlen=l1*l2;
	
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
	}
	
	for ( ; *(somma+1)=='0'; somma++) ;
	
	return somma;
}

char* multiplication (char* numero1, char* numero2) {
	int l1=strlen(numero1);
	int l2=strlen(numero2);
	long long int len=(l1*l2*l1*l2); //numero massimo di cifre da allocare
	
	char* multiplication = malloc(sizeof(char)*len);
	multiplication="0";
	
	int riporto=0;
	int colonna=0;
	int tmp;
	int pointer;
	int k=0;
	
	for( ; l2>0; l2--, k++) {
		
		char* temp = malloc(sizeof(char)*len);
		temp[len]='\0';
		int j=k;
		riporto=0;
		
		tmp=len-1; 
		while(j>0) {
			temp[tmp]='0';
			tmp--;
			j--;
		}
		
		for(pointer=l1 ; pointer>0 ; pointer--, tmp--) {
		
			colonna=(numero2[l2-1]-48)*(numero1[pointer-1]-48);
			
			riporto=riporto+colonna;
			temp[tmp] = (riporto%10) + 48;
			riporto=riporto/10;
		}
		
		temp[tmp] = (riporto%10) + 48;
		tmp--;
		
		while(tmp>=0) {
			temp[tmp]='0';
			tmp--;
		}
		
		multiplication=sum(multiplication, temp);
	}
	
	for ( ; *(multiplication)=='0'; multiplication++) ;
	
	return multiplication;
}

void main () {
	char* numero2 = "3712938391822123";
	char* numero1 = "24719481131248124812948723812381199";
	char* somma = malloc (sizeof(char)*(strlen(numero1)*strlen(numero2)));
	somma = multiplication(numero1, numero2);

	printf("%s", somma);
	FILE* f = fopen ("risultato.txt", "w");
	
	fprintf(f, "%s *\n%s =\n%s", numero1, numero2, somma);
	fclose(f);
}
