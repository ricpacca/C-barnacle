#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*converte in maiuscolo tutte le lettere di s*/
void upper_string(char *string) {
    while(*string) {
        if ( *string >= 'a' && *string <= 'z' ) *string = *string - 32;
        string++;
    }
}

void lower_string(char *string) {
    while(*string) {
        if ( *string >= 'A' && *string <= 'Z' ) *string = *string + 32;
        string++;
    }
}

int contaParole (char* nomeFile) {
	FILE* f = fopen(nomeFile, "r");
	char tmp[30];
	int i=0;
	while(!feof(f)) {
		fscanf(f, "%s", tmp);
		i++;
	}
	fclose(f);
	return i;
}

/*trasforma tutte in maiuscolo/minuscolo le parole dell'array*/
char** UniformaArray (char** parole, int numParole) {
	int i; 
	for(i=0; i<numParole; i++) {
		lower_string(parole[i]);
	}
	return parole;
}

void ArrayToFile (char** parole, int numParole) {
	FILE* f = fopen ("output.txt", "w");
	int i;
	for (i=0; i<numParole; i++)	{
		fprintf(f, "%s ", parole[i]);
	}
	fclose(f);
}

int main() {
	char nomeFile[]="prova.txt";
	FILE* ingresso;
	int numParole=contaParole(nomeFile);
	ingresso = fopen(nomeFile, "r");
	char parola[30];
	char** parole=malloc(sizeof(char*)*numParole);
	int i=0;
	
	while(!feof(ingresso)) {
		fscanf(ingresso, "%s", parola);
		parole[i]=strdup(parola);
		i++;
	}
	
	parole=UniformaArray(parole, numParole);
	ArrayToFile(parole, numParole);
	return 0;
}
