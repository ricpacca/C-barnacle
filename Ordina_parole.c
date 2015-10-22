#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

int tot=100;

/*scambia due stringhe*/
void scambia(char** s1, char** s2) {
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int distanza(char* s1, char* s2) {
	int diff = ( s1[0]>s2[0] ? (s1[0]-s2[0]) : (s2[0]-s1[0]) );
	return diff;
}

/*stampa tutte le permutazioni con la distanza*/
void permuta (char** s, int start, int dim) {
    int i;
	
	if (dim - start != 1) { 
		for (i=start;i<dim; i+=1) {	
			scambia(&s[start], &s[i]);
      		permuta(s, start+1, dim);
       		scambia(&s[start], &s[i]); } }

    else {
		short int counter=0;
		for (i=0;i<dim; i+=2) {
			counter+=distanza(s[i], s[i+1]);}
    	
		if (counter<tot) {
			tot=counter;
			
			for (i=0; i<dim; i++)
				printf(" %s\t", s[i]);
			printf("--> %d\n",counter);}
	}
}

/* prende le parole a due a due, ne conta la "distanza", e poi somma le distanze */
int main() {
    int i, n;
	char stringa[40];
    
	do {printf("\n Quante parole vuoi inserire (accetto solo numeri pari)? ");
    	scanf("%d",&n); } while(n%2!=0);
    	
    char** v = malloc(sizeof(char*)*n);
    
    printf("\n Inserisci ora le parole dell'array:\n\n");
    for (i=0;i<n;i++)
        {printf(" casella [%i]: ", i);
		scanf("%s", stringa);
		v[i] = strdup(stringa);}
    
    permuta (v,0,n);
	
	printf("\n La distanza minima e': %d\n", tot);
    return 0;
}
