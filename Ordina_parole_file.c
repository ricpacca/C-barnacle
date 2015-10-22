#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 50

void ordinaParole (char** parole, int numParole);

int main () {
	FILE* ingresso;
	ingresso = fopen("testo.txt", "r"); //legge il file di ingresso
	if(ingresso==NULL) {printf("Errore nell'apertura del file"); return 2;}
	
	char parola[MAXLEN]; //stringa indicante una singola parola
	
	char** parole; //array di puntatori a stringhe in memoria
	char** parole_ordinate;
	
	int numeroParole=contaParole("testo.txt");
	parole=malloc(sizeof(char*)*numeroParole);
	parole_ordinate=malloc(sizeof(char*)*numeroParole);
	
	char *strtmp;
	int tmp;
	int i=0, j, k; //contatore
	
	while(!feof(ingresso)) 	{
		fscanf(ingresso, "%s", parola); //prende ogni parola del testo
		printf("parola letta: %s\n", parola);
		parole[i]=strdup(parola); //copia la parola in memoria e salva la posizione nell'array parole
		i++; //continua a copiare tutte le parole del testo in memoria fino a quando finisce
	}	//ora le parole del file sono raggiungibili nell'array parole[i]
	
	ordinaParole(parole, numeroParole);
	
	FILE* risultato = fopen("risultato.txt", "w");  //apre il file su cui scrivere il risultato
	for(i=0; i<numeroParole; i++) {
		fprintf(risultato, "%s ", parole[i]);  //salva nel file tutte le parole
		/*if(!((i+1)%2)) fprintf(risultato, "\n"); //mettendo nella stessa riga le coppie */
	}
	
	fclose(risultato);
	
	return 0;
}

int contaParole (char* nomeFile) {
	FILE* f = fopen("testo.txt", "r");
	char tmp[MAXLEN];
	int i=0;
	
	while(!feof(f)) {
		fscanf(f, "%s", tmp); //prende ogni parola del testo
		i++; //continua a copiare tutte le parole del testo in memoria fino a quando finisce
	}
	
	return i;
}

void ordinaParole (char** parole, int numParole) {
	int i, k, tmp;
	char* strtmp;
	for(i=0; i<numParole; i++) {
		tmp=i;
		for(k=i+1;k<numParole;k++)
			if(strcmp(parole[tmp], parole[k]) > 0)
				tmp=k;
				
		strtmp=parole[i];
		parole[i]=parole[tmp];
		parole[tmp]=strtmp;
	}
}
