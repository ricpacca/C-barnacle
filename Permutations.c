#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scambia(char** s1, char** s2)
{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void permuta (char** s, int start, int dim)
{
    int i;
	if (dim - start != 1) { 
		for (i=start;i<dim; i++) {	
			scambia(s+start, s+i);
      		permuta(s, start+1, dim);
       		scambia(s+start, s+i); } }

    else {	
		for (i=0; i<dim; i++)
			printf(" %s\t", *(s+i));
		printf("\n");
	}
}

int main()
{
    int i, n;
	char** v;
	char stringa[30];
    printf("\n Quante parole vuoi inserire? ");
    scanf("%d", &n);
    v = malloc(sizeof(char*)*n);
    
    printf("\n Inserisci ora le parole dell'array:\n\n");
    for (i=0;i<n;i++)
        {printf(" casella [%d]: ", i);
		scanf("%s", stringa);
		v[i]=strdup(stringa);
		}
		
	/*for (i=0;i<n;i++)
        {printf(" %s\n", v[i]);}*/
    
    printf("\n Ecco le permutazioni:\n\n");
    permuta (v,0,n);
    
    return 0;
}
