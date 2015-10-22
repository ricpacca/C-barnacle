#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*supporta solo addizione e sottrazione*/
int eval(char* expr) {
    int i, numero, risultato=0;
    risultato+=(expr[0]-48);
    for(i=2; i<strlen(expr);i+=2) {
        numero=expr[i]-48;
        if(expr[i-1]=='-') risultato=risultato-numero;
        if(expr[i-1]=='+') risultato=risultato+numero;
    }
    return risultato;
}

/*supporta addizione, sottrazione, moltiplicazione, divisione, numeri di più di una cifra, e decimali*/
float eval2(char* expr) {
    int i, j, k;
	float numero, risultato=0;
	
    for(i=1; i<=strlen(expr);i+=2) {
        if(expr[i-1]=='-' || expr[i-1]=='+') i++;
		numero=expr[i-1]-48; j=i;
        while(expr[i]>='0' && expr[i]<='9') {numero=numero*10+expr[i]-48; i++;}
        while(expr[i]=='*' || expr[i]=='/') {
        	float temp=expr[i+1]-48; k=i;
        	while(expr[i+2]>='0' && expr[i+2]<='9') {temp=temp*10+expr[i+2]-48; i++;}
			if(expr[k]=='/') numero/=temp;
			if(expr[k]=='*') numero*=temp;
			i+=2;
		}
		if(expr[j-2]=='-') risultato-=numero;
		else risultato+=numero;
    }
    return risultato;
}

/*supporta anche le parentesi*/
float eval3 (char* e) {
	int l=strlen(e), i, j, k, t, z[20];
	char*p=malloc(sizeof(char)*l),*s=malloc(sizeof(char)*l);
	for(i=0, k=0; i<l; k++, i++) {
		s[k]=e[i];
		if(e[i-1]=='(') {
			for(j=0; e[i]!=')'; j++, i++) p[j]=e[i];
			p[j]='\0';
			j=eval2(p);
			if(j<0) {
				t=k-2; j=0-j;
				while(s[t]!='+' || s[t]!='-') {
					if (s[t]=='+') {s[t]='-'; break;}
					else if (s[t]=='-') {s[t]='+'; break;}
					t--;
				}
			}
			for(t=0; j>0; t++) {z[t]=j%10; j/=10;}
			while (t>0) {s[k-1]=z[t-1]+48; t--; k++;}
			k-=2;
		}
	}
	s[k]='\0';
	for (j=0; j<strlen(s); j++) printf("%c", s[j]); /*stampa l'espressione semplificata senza parentesi*/
	return eval2(s);
}

void main() {
	int j;
	char expr[]="1*(1+3*2)+40761+150*17*(-2*9+1)-150*(1-2*9)+40/10+1033-1*22*(90/9+4*3)*1-1*500*1-2*(3*85)/3*44+2*888*4+356";
	for (j=0; j<strlen(expr); j++) printf("%c", expr[j]); /*stampa l'espressione iniziale*/
	printf("\n");
	printf("\n%.2f", eval3(expr)); /*stampa il risultato*/
}
