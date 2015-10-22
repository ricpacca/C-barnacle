#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h> 

int numCifreConv (long int n, int b) {
	int i;
	for(i=0;n>0;i++)
		n=n/b;
	return i;
}

/*cambio basi per basi qualsiasi*/
char* FromInt (long int n, int base) {
	int num= numCifreConv(n, base);
	int r[num], i=-1, j=0;
		
	while(n) {
		i++;
		r[i]=n%base;
		n=n/base;
	}
	
	char lettera='A';
	char* Conv = malloc(sizeof(char)*(i));
	
	for(; i>=0; i--, j++) {
		if(r[i]<10) Conv[j]=r[i]+48;
		else Conv[j]=lettera+(r[i]-10);
	}
	
	Conv[j]='\0';
	return Conv;
}

long int ToInt (char* n, int base) {
	int i, tmp, l=strlen(n);
	long int nuovo=0;
	char numero='0', lettera='A';
	
	for (i=0; i<l; i++)
	{
		if(n[i]-numero<10) tmp=n[i]-numero;
		else tmp=n[i]-lettera+10;
		nuovo = nuovo + tmp*pow(base, l-1-i);
	}
	return nuovo;
}

int main() {
	long int n = 315788898;
	int i, base = 35;
	
	printf("%ld\n", n);
	char* Hex = FromInt(n, base);
		
	for (i=0; i<strlen(Hex); i++)
		printf("%c", Hex[i]);
	
	long int nw = ToInt(Hex, base);
	printf("\n%ld\n", nw);
}
