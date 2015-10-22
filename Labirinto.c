#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int anagramma (char *str1, char *str2);
int cambioCarattere (char *str1, char *str2);
int pm_Carattere (char *str1, char *str2);
void upper_string(char *string);
int lista_giusta (char **parole, int numParole);
void ordinaParole (char** parole, int numParole, int start);
int contaParole (char* nomeFile);
void scambia(char** s, int a, int b);
char *strdup2(char *str);

int main (int argc,char *argv[]) {
	char nomeFile[50];
    char parola[30]; /*stringa indicante una singola parola*/
	int i=0;
	char** parole; /*array di puntatori a stringhe in memoria*/
	int numParole;

	FILE* ingresso;
	scanf ("%s", nomeFile);
	numParole=contaParole(nomeFile);
	ingresso = fopen(nomeFile, "r"); /*legge il file di ingresso*/
	
	parole=malloc(sizeof(char*)*numParole);
	
	while(!feof(ingresso)) {
		fscanf(ingresso, "%s", parola); /*prende ogni parola del testo*/
		parole[i]=strdup(parola); /*copia la parola in memoria e salva la posizione nell'array parole*/
		i++; /*continua a copiare tutte le parole del testo in memoria fino a quando finisce*/
	}	/*ora le parole del file sono raggiungibili nell'array parole[i]*/

	ordinaParole(parole, numParole, 1);
	system("PAUSE");
    return 0;
}

int contaParole (char* nomeFile) {
	FILE* f = fopen(nomeFile, "r");
	char tmp[30];
	int i=0;
	while(!feof(f)) {
		fscanf(f, "%s", tmp); /*prende ogni parola del testo*/
		i++; /*continua a copiare tutte le parole del testo in memoria fino a quando finisce*/
	}
	fclose(f);
	return i;
}

void ordinaParole (char **parole, int numParole, int start) {
    int i, k;
    
    if ((lista_giusta(parole, start))==0) start=numParole-1;
    
	if (numParole - start > 1) {
		for (i=start; i<numParole-1; i++) {
			scambia(parole,start,i);
			ordinaParole(parole, numParole, start+1);
			scambia(parole,start,i);
		}
	}

	else {
		if(lista_giusta(parole, numParole)==1) {
			for(k=0; k<numParole-1; k++)
				if (k!=numParole-2) printf("%s ", parole[k]);  /*stampa tutte le parole*/
				else printf("%s", parole[k]);
			printf("\n");
		}
	}
}

int lista_giusta (char **parole, int numParole) {
    int i;
    
    if(numParole==1 || numParole==0) return 1;
    
    for (i=1; i<numParole; i++) {
        if((anagramma(parole[i], parole[i-1])==0) && (cambioCarattere(parole[i], parole[i-1])==0) && ((pm_Carattere(parole[i], parole[i-1])==0)) && (pm_Carattere(parole[i-1], parole[i]))==0)
            return 0;
    }
    
    return 1;
}

int anagramma (char *tmp1, char *tmp2) {
    char *str1, *str2;
	int j;
	if (strlen(tmp1)!=strlen(tmp2))
        return 0;
        
	str1 = malloc(sizeof(char)*30);
	str2 = malloc(sizeof(char)*30);
    strcpy(str1, tmp1);
    strcpy(str2, tmp2);
    upper_string (str1);
    upper_string (str2);
    
    for (; *str1 != '\0'; str1++) {
        j=0;
        while (*(str2+j)!=*str1) {
            j++;
            if (*(str2+j)=='\0')
                return 0;
        }
        *(str2+j)=' ';
    }
    return 1; /*una anagramma altra*/
}

int cambioCarattere (char *tmp1, char *tmp2) {
    int contaDifferenze = 0, i;	
    char *str1, *str2;
	
	if (strlen(tmp1)!=strlen(tmp2))
        return 0;
	
	str1=malloc(sizeof(char)*30); 
	str2=malloc(sizeof(char)*30);
	strcpy(str1, tmp1);
    strcpy(str2, tmp2);
    upper_string (str1);
    upper_string (str2);
    
    for(i=0; str1[i]!=0; i++)
    	if(str1[i]!=str2[i]) contaDifferenze+=1;
    
	return ((contaDifferenze==1)? 1 : 0);
}

int pm_Carattere(char *tmp1, char *tmp2) {
    char *str1, *str2;
    int i, j;

	str1=malloc(sizeof(char)*30); 
	str2=malloc(sizeof(char)*30);
    strcpy(str1, tmp1);
    strcpy(str2, tmp2);
    upper_string (str1);
    upper_string (str2);

    if ((strlen(str1)-strlen(str2))!=1) return 0;

    for (i=0,j=0;str1[i]!='\0';i++,j++)
        if (str1[i]!=str2[j]) j--;
    
    if ((i-j)==1) return 1;
    return 0;
}

void scambia(char** s, int a, int b) {
    char* temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void upper_string(char *string) {
    while(*string) {
        if ( *string >= 'a' && *string <= 'z' ) *string = *string - 32;
        string++;
    }
}
