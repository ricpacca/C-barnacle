#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
	char* parola;
	struct nodo* prossima;
} Parola;

Parola* aggiungi_in_coda (Parola* testa, char* string);
Parola* aggiungi_in_testa (Parola* testa, char* string);
Parola* aggiungi_in_ordine (Parola* testa, char* string);
Parola* aggiungi_nodo (Parola* testa, char* string, int n);	
Parola* importa_da_file (Parola* testa, char* nomeFile);

Parola* rimuovi_ultimo_elemento (Parola* testa);
Parola* rimuovi_primo_elemento (Parola* testa);
Parola* rimuovi_nodo (Parola* testa, int n);
Parola* rimuovi_dato (Parola* testa, char* string);

Parola* ordina_lista(Parola* testa);
Parola* mescola_lista(Parola* testa);
Parola* svuota (Parola* testa);
Parola* scambia_nodi(Parola* testa, int nodo1, int nodo2);
Parola* primo_in_coda (Parola* testa);
Parola* inverti_lista (Parola* testa);

void stampa (Parola *lista);
void stampa_al_contrario(Parola *lista);
void salva_su_file (Parola *lista);
int trova_dato (Parola* lista, char* string);
void stampa_nodo (Parola* testa, int n);

void scambia_parole(Parola** l1, Parola** l2);
int listlen(Parola *lista);
void menu();

void main()
{
	menu();
}

void menu()
{
	puts("\n- 1 Inserire una parola in coda alla lista");
	puts("- 2 Inserire una parola in testa alla lista");
	puts("- 3 Inserire una parola gia' in ordine alfabetico all'interno della lista");
	puts("- 4 Inserire una parola in una posizione a piacere della lista");
	puts("- 5 Importare le parole da un file txt e inserirle nella lista");
	puts("\n- 6 Rimuovere l'ultimo elemento della lista");
	puts("- 7 Rimuovere il primo elemento della lista");
	puts("- 8 Rimuovere l'elemento n-esimo della lista");
	puts("- 9 Rimuovere una parola dalla lista");
	puts("\n- 10 Ordinare in ordine alfabetico la lista (a meno di maiuscole/minuscole)");
	puts("- 11 Mescolare la lista");
	puts("- 12 Invertire la lista");
	puts("- 13 Spostare il primo nodo in coda alla lista");
	puts("- 14 Scambiare due nodi della lista");
	puts("- 15 Svuotare la lista");
	puts("\n- 16 Trovare una parola all'interno della lista");
	puts("- 17 Stampare la parola contenuta in un determinato nodo della lista");
	puts("\n- 18 Stampare tutte le parole della lista");
	puts("- 19 Stampare al contrario tutte le parole della lista");
	puts("- 20 Salvare il contenuto della lista su un file txt\n");	
	
	Parola* testa = NULL;
	char string[20];
	int posizione, posizione2;
	
	int scelta=-1;
	while(scelta!=0) {
	
		printf("\n> Cosa vuoi fare (zero per terminare)? ");
		fflush(stdin);
		scanf("%d", &scelta);
		
		switch(scelta) {
			case 0:
				scelta=0;
				break;
			case 1:
				printf("Quale parola vuoi inserire? ");
				scanf("%s", string);
				testa=aggiungi_in_coda(testa, string);
				if(testa!=NULL) printf("Ho aggiunto in coda la parola %s\n", string);
				scelta=-1;
				break;
			case 2:
				printf("Quale parola vuoi inserire? ");
				scanf("%s", &string);
				testa=aggiungi_in_testa(testa, string);
				if(testa!=NULL) printf("Ho aggiunto in testa la parola %s\n", string);
				scelta=-1;
				break;
			case 3:
				printf("Quale parola vuoi inserire? ");
				scanf("%s", &string);
				testa=aggiungi_in_ordine(testa, string);
				if(testa!=NULL) printf("Ho aggiunto in testa la parola %s\n", string);
				scelta=-1;
				break;
			case 4:
				printf("Quale parola vuoi inserire? ");
				scanf("%s", &string);
				printf("In quale posizione? ");
				scanf("%d", &posizione);
				testa=aggiungi_nodo(testa, string, posizione);
				if(testa!=NULL) printf("Ho aggiunto la parola %s nella posizione %d\n", string, posizione);
				scelta=-1;
				break;
			case 5:
				printf("Inserisci il nome del file contenente le parole: ");
				scanf("%s", string);
				testa=importa_da_file(testa, string);
				if(testa!=NULL) printf("Ho importato dal file %s\n", string);
				scelta=-1;
				break;
			case 6:
				testa=rimuovi_ultimo_elemento(testa);
				printf("Ho rimosso l'ultimo elemento della lista\n");
				scelta=-1;
				break;
			case 7:
				testa=rimuovi_primo_elemento(testa);
				printf("Ho rimosso il primo elemento della lista\n");
				scelta=-1;
				break;
			case 8:
				printf("Quale nodo vuoi rimuovere (1,2,3,...)? ");
				scanf("%d", &posizione);
				testa=rimuovi_nodo(testa, posizione);
				printf("Ho rimosso l'elemento %d della lista\n", posizione);
				scelta=-1;
				break;
			case 9:
				printf("Quale parola vuoi rimuovere? ");
				scanf("%s", &string);
				testa=rimuovi_dato(testa, string);
				printf("Ho rimosso dalla lista la parola %s\n", string);
				scelta=-1;
				break;
			case 10:
				testa=ordina_lista(testa);
				if(testa!=NULL) printf("Ho ordinato la lista in ordine alfabetico\n");
				scelta=-1;
				break;
			case 11:
				testa=mescola_lista(testa);
				if(testa!=NULL) printf("Ho mescolato la lista\n");
				scelta=-1;
				break;
			case 12:
				testa=inverti_lista(testa);
				if(testa!=NULL) printf("Ho invertito la lista\n");
				scelta=-1;
				break;
			case 13:
				testa=primo_in_coda(testa);
				if(testa!=NULL) printf("Ho spostato il primo elemento in coda\n");
				scelta=-1;
				break;
			case 14:
				printf("Quali nodi vuoi scambiare tra loro (scrivi ad esempio '3 8')? ");
				scanf("%d %d", &posizione, &posizione2);
				testa=scambia_nodi(testa, posizione, posizione2);
				if(testa!=NULL) printf("Ho scambiato la parola in posizione %d con quella in posizione %d\n", posizione, posizione2);
				scelta=-1;
				break;
			case 15:
				testa=svuota(testa);
				printf("Ho svuotato la lista\n");
				scelta=-1;
				break;
			case 16:
				printf("Quale parola vuoi cercare? ");
				scanf("%s", &string);
				posizione=trova_dato(testa, string);
				if(testa!=NULL) printf("La parola %s e' l'elemento %d della lista\n", string, posizione);
				scelta=-1;
				break;
			case 17:
				printf("Quale nodo vuoi stampare? ");
				scanf("%d", &posizione);
				stampa_nodo(testa, posizione);
				printf("\n");
				scelta=-1;
				break;
			case 18:
				stampa(testa);
				printf("\n");
				scelta=-1;
				break;
			case 19:
				stampa_al_contrario(testa);
				printf("\n");
				scelta=-1;
				break;
			case 20:
				salva_su_file(testa);
				printf("Ho salvato il contenuto della lista sul file output.txt\n");
				scelta=-1;
				break;
			case 21:
				printf("Easter EGG!\n");
				scelta=-1;
				break;
			default:
				printf("Scelta non valida. Riprova\n");
				scelta=-1;
		}
	}		
}

//FUNZIONI DI AGGIUNTA NODI

Parola* aggiungi_in_coda (Parola* testa, char* string) {
	if(testa==NULL) {
		testa=malloc(sizeof(struct nodo));
		testa->prossima=NULL;
		testa->parola=strdup(string);
		return testa;
	}
	
	else testa->prossima = aggiungi_in_coda (testa->prossima, string);
	return testa;
}

Parola* aggiungi_in_testa (Parola* testa, char* string) {
	if(testa==NULL) {
		testa=malloc(sizeof(struct nodo));
		testa->prossima=NULL;
		testa->parola=strdup(string);
		return testa;
	}
	
	else {
		Parola* nuovaTesta = malloc(sizeof(struct nodo));
		nuovaTesta->prossima=testa;
		nuovaTesta->parola=strdup(string);
		return nuovaTesta;
	}
}

Parola* aggiungi_in_ordine (Parola* testa, char* string) {
	if(testa==NULL) {
		testa=malloc(sizeof(struct nodo));
		testa->prossima=NULL;
		testa->parola=strdup(string);
		return testa;
	}
	
	else {
		if(strcmp(testa->parola, string)>0) {testa=aggiungi_in_testa(testa, string); return testa;}
		
		Parola* temp=testa, *prec;
		while(strcmp(temp->parola, string)<0) {prec=temp; temp=temp->prossima;}
		
		Parola* nuovoNodo = malloc(sizeof(struct nodo));
		nuovoNodo->prossima=temp;
		nuovoNodo->parola=strdup(string);
		prec->prossima=nuovoNodo;
		return testa;
	}
}

Parola* aggiungi_nodo (Parola* testa, char* string, int n) {
	if(n>listlen(testa) || n<1) {
		printf("La posizione non esiste\n");
		return testa;
	}
	if(n==1) {
		testa=aggiungi_in_testa (testa, string);
		return testa;
	}
	else {
		testa->prossima=aggiungi_nodo(testa->prossima, string, n-1);
		return testa;
	}
}

//FUNZIONI DI RIMOZIONE NODI

Parola* rimuovi_nodo(Parola * testa, int n) {
	if(testa==NULL) {
		printf("Non posso togliere l'elemento");
		return testa;}
	if(n==1) {
		testa=rimuovi_primo_elemento (testa);
		return testa;
	}
	else {
		testa->prossima=rimuovi_nodo(testa->prossima, n-1);
		return testa;
	}
}

Parola* rimuovi_dato (Parola* testa, char* string) {
	Parola *temp;
	
	if(testa==NULL) {
		printf("La lista e' vuota\n");
		return testa;}
	if(strcmp(string, testa->parola)==0)
	{
		testa=rimuovi_primo_elemento (testa);
		return testa;
	}
	else
	{
		if (testa->prossima==NULL) printf("La parola non e' presente all'interno della lista\n");
		else testa->prossima=rimuovi_dato (testa->prossima, string);
		return testa;
	}
}

Parola* rimuovi_primo_elemento (Parola* testa) {
	if(testa==NULL) {
		printf("La lista e' vuota\n");
		return testa;}
		
	Parola* temp = testa->prossima;
	free(testa);
	return temp;
}

Parola* rimuovi_ultimo_elemento (Parola* testa) {
	if(testa==NULL) {
		printf("La lista e' vuota\n");
		return testa;}
	
	if(testa->prossima==NULL) {
		free(testa);
		return NULL;
	}
	
	else testa->prossima = rimuovi_ultimo_elemento (testa->prossima);
	return testa;
}

//FUNZIONI DI RIORDINAMENTO DI UNA LISTA

Parola* ordina_lista(Parola* testa) 
{
	if(testa==NULL) {
		printf("La lista e' vuota\n");
		return testa;}
  
	Parola* temp;
	int scambiato = 1;
	char* swap;
  
	while (scambiato) {
    	temp = testa; 															//così posso scorrere temp anziché il puntatore alla testa che mi serve dopo
   		scambiato = 0; 															//per ora non ho fatto ancora alcuno scambio (se non ci sarà alcuno scambio vorrà dire che la lista è già ordinata
    
		while (temp->prossima != NULL) {										//partendo dal primo nodo, finchè non arrivo alla fine della lista
      		if (strcmp(temp->parola, (temp->prossima)->parola)>0) {				//quando verifico che la parola contenuta nel nodo che sto puntando dovrebbe trovarsi dopo quella del nodo successivo
	        	scambia_parole(&temp, &(temp->prossima));						//allora scambio la parola di quel nodo con quella del nodo successivo
	        	scambiato = 1;													//mi segno che c'è stato almeno uno scambio
	      	}
	      	temp = temp->prossima;												//passo al nodo successivo (in sostanza il while sposta la nod-esima parola fino a dove deve stare)
	    }
  	}
  	return testa;
}

Parola* inverti_lista (Parola* testa) {
	Parola* nuova=NULL, *temp;
	
	while(testa!=NULL) {
		nuova=aggiungi_in_testa (nuova, testa->parola);
		temp=testa;
		testa=testa->prossima;
		free(temp);
	}
	
	return nuova;
}

Parola* mescola_lista(Parola* testa) {
	if(testa==NULL) {
		printf("La lista e' vuota\n");
		return testa;}
		
	int i, r1, r2, len;
	srand(time(NULL));
	len=listlen(testa);
	
	for (i=0; i<len; i++) {
		r1 = rand() % len + 1;
		r2 = rand() % len + 1;
		testa=scambia_nodi(testa, r1, r2);
	}
	return testa;
}

void scambia_parole(Parola** l1, Parola** l2) {
	char* swap = (*l1)->parola;
    (*l1)->parola = (*l2)->parola;
    (*l2)->parola = swap;
}

Parola* scambia_nodi(Parola* testa, int nodo1, int nodo2) {
	Parola *temp=testa, *n1=NULL, *n2=NULL;
	int i=0, l = listlen(testa);
	
	if(testa==NULL) {printf("La lista e' vuota\n");	return testa;}
	if(nodo2>l || nodo1>l) {printf("Almeno uno dei due nodi che hai scelto non esiste nella lista\n"); return testa;}
	
	if(nodo1==nodo2) return testa;
	if(nodo1>nodo2) {
		i=nodo1; nodo1=nodo2; nodo2=i;}
	
	for (i=1; i<nodo2, temp!=NULL; temp=temp->prossima, i++) {
		if(i==nodo1) n1=temp;
		n2=temp;
	}
	
	scambia_parole(&n1, &n2);
	return testa;
}

Parola* primo_in_coda (Parola* testa) {
	Parola *ultimo=testa;
	
	if(testa==NULL) {
		printf("La lista e' vuota\n");
		return testa;}
		
	if(testa->prossima==NULL) return testa;
	
	while (ultimo->prossima!=NULL) ultimo=ultimo->prossima;
		
	ultimo->prossima=testa;
	testa=testa->prossima;
	(ultimo->prossima)->prossima=NULL;
	
	return testa;
}

//FUNZIONI DI STAMPA/SALVATAGGIO LISTA

void stampa (Parola *lista) {
	if (lista==NULL) printf("La lista e' vuota");
	
	while (lista != NULL) {
		printf("%s ", lista->parola);
		lista = lista->prossima;
	}
}

void stampa_nodo (Parola* lista, int n) {
	if (lista==NULL) {printf("La lista e' vuota"); return;}
	if (n>listlen(lista)) {printf("La lista non arriva a %d elementi", n); return;}
	int i;
	for (i=1; i<n; i++) lista=lista->prossima;
	printf("L'elemento %d della lista e' %s", n, lista->parola);
}

int trova_dato (Parola* lista, char* string) {
	int i;
	for (i=1; lista!=NULL; i++) 
	{
		if (strcmp(lista->parola, string)==0) return i;
		lista=lista->prossima;
	}
	if (lista==NULL) {printf("La lista e' vuota\n"); return 0;}
}

void salva_su_file (Parola *lista) {
	if (lista==NULL) printf("La lista e' vuota\n");
	FILE* f= fopen("output.txt", "w");
	
	while (lista != NULL) {
		fprintf(f, "%s ", lista->parola);
		lista = lista->prossima;
	}
	fclose(f);
}

void stampa_al_contrario(Parola *lista) {
    if (lista==NULL) return;
    stampa_al_contrario(lista->prossima);
    printf ("%s ",lista->parola);
}

//ALTRE FUNZIONI UTILI PER LISTE

int listlen(Parola *lista) {
    if (lista==NULL) return 0;
    return 1+listlen(lista->prossima);
}

Parola* svuota (Parola* testa) {
	Parola* tmp;
	while(testa!=NULL)
	{
		tmp=testa->prossima;
		free(testa);
		testa=tmp;
	}
	return testa;
}

Parola* importa_da_file (Parola* testa, char* nomeFile) {
	FILE* f = fopen(nomeFile, "r");	
	if (f==NULL) {printf("Errore nell'apertura del file\n"); return;}
	
	char string[20];
	
	while (!feof(f)) {
		fscanf(f, "%s", string);
		testa=aggiungi_in_coda(testa, string);
	}
	return testa;
}
