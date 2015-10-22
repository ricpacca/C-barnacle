#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*restituisce la stringa b senza il carattere a*/
char *f(char a, char *b) {
	char* s=malloc(sizeof(char)*strlen(b));
	char* r=s;
	if (*b=='\0') return b;
	for (;*b!=a; b++,r++)
		*r=*b;
	b++;
	for (;*b!='\0';b++, r++)
		*r=*b;
	*r='\0';
	return s;
}

/*restituisce 1 se il carattere a è presente in b*/
int h(char a, char* b) {
	if (*b=='\0')
		return 0;
	return (a==*b) || h(a, b+1);
}

/*restituisce 1 se le due parole sono anagrammi*/
int g(char *a, char *b) {
	if (*a=='\0' && *b=='\0') return 1;
	if (*a=='\0' || *b=='\0') return 0;
	if (h(*a,b)) return g(a+1,f(*a,b));
	return 0;
}

int main() {
	char* s[7]={"nescio","sed","fieri","sentio","et", "excurcior", "albero"};
	char c[7]={'c','e','r','t','i','o','a'};
	int i, j;
	
	for (i=0;i<7;i++)
		if(h(c[i],s[i]))
			printf("%s\n", f(c[i],s[i]));
	
	
	printf("\n");
	char *n[5]={"xayxz","zzyax","azxya","yzxay","xzyax"};
	
	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			printf("%s e %s: ", n[i], n[j]);
			printf("%i\n", g(n[i],n[j]));
		}
		printf("\n");
	}
	return 0;
}
