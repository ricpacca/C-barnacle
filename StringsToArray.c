#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*prende una frase separata da spazi e restituisce
un array con tutte le parole*/
char** string_to_array(char stringa[]) {
	int i=0, j=0, k=0;
	char** array=malloc(sizeof(char*)*(numParole(stringa)));
	char* tmp = malloc(sizeof(char)*30);

	for(i=0; i<=strlen(stringa); i++) {
		if(stringa[i]!=' ' && stringa[i]!='\0')	{
			tmp[j] = stringa[i];
			j++;
		}
		else {
			tmp[j] = '\0';
			array[k] = strdup(tmp);
			
			free(tmp);
			tmp = malloc(sizeof(char)*30);
			j=0; k++;
		}
	}
	return array;
}

int numParole (char* stringa) {
	int i, counter=1;
	for (i=0; i<strlen(stringa); i++)
		if(stringa[i]==' ' && stringa[i-1]!=' ' && stringa[i+1]!=' ') counter+=1;
	return counter;
}

int main(void) {
	char frase[500];

	printf("Inserisci una stringa: ");
	gets(frase);
	printf("\n");

	int i;
	char** array = string_to_array(frase);

	for(i = 0; i < numParole(frase); i++){
		printf("%s\n", array[i]);
	}

	return 0;
}
