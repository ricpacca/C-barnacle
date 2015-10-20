#include <stdio.h>

//restituisce 1 se il giocatore 1 ha vinto; 2 se il giocatore 2 ha vinto
int controllo (int x[3][3]) {
    int r, c;
    int counter1, counter2, counter3, counter4;

	// controllo righe e colonne
    for(r=0; r<3; r++) {
       counter1=0; counter2=0; counter3=0; counter4=0;

       for (c=0; c<3; c++) {
           if (x[r][c]==1)	counter1 += 1;
           if (x[r][c]==2)	counter2 += 1;
           if (x[c][r]==1)	counter3 += 1;
           if (x[c][r]==2)	counter4 += 1;
       }

       if (counter1==3 || counter3==3)	return 1;
       if (counter2==3 || counter4==3)	return 2;
    }

	// controllo diagonali
    counter1=0; counter2=0; counter3=0; counter4=0;
    
    for(r=0; r<3; r++) {
        if (x[r][r]==1)	counter1 += 1;
        if (x[r][r]==2)	counter2 += 1;
		if (x[r][2-r]==1)	counter3 += 1;
        if (x[r][2-r]==2)	counter4 += 1;
    }

    if (counter1==3 || counter3==3)	return 1;
    if (counter2==3 || counter4==3)	return 2;
    
    //se nessuno vince in nessuna riga, colonna o diagonale, ma ci sono ancora caselle vuote, restituisce -1 
    for(r=0;r<3;r++)
        for(c=0;c<3;c++)
            if(x[r][c]==0)
                return -1;
    
    //se tutte le caselle sono piene (gioco pari), ritorna 0
    return 0;
}

/* prende la casella m[a][b]: 
 se la casella è occupata restituisce -2, 
 se in quella casella "giocatore" può vincere restituisce 1, 
 se facendo quella mossa il gioco finirebbe in parità, restituisce 0
 se facendo quella mossa non cambia niente, ma nella mossa successiva il l'altro giocatore potrebbe vincere, restituisce -1
 se facendo quella mossa non cambia niente, ma nella mossa successiva il gioco finirebbe comunque in parità, restituisce 0
 se facendo quella mossa non cambia niente, e nella mossa successiva comunque non cambierebbe niente, restituisce 1 */

int prova_mossa(int m[3][3], int giocatore, int a, int b) {
     int risultato,i,j,m_temp[3][3];
     
     if(m[a][b]!=0)	return -2;
     
     for(i=0;i<3;i++)
         for(j=0;j<3;j++)
             m_temp[i][j]=m[i][j];
     
     m_temp[a][b]=giocatore;
     risultato=controllo(m_temp);
     
     if(risultato==giocatore)	return 1;
     if(risultato==0)	return 0;
     
     for(i=0;i<3;i++)
         for(j=0;j<3;j++)
             if(prova_mossa(m_temp,3-giocatore,i,j)==1)	return -1;
     
     for(i=0;i<3;i++)
         for(j=0;j<3;j++)
             if(prova_mossa(m_temp,3-giocatore,i,j)==0)	return 0;
             
     return 1;
}

void mossa(int m[3][3], int giocatore) {
     int i,j;
     
     for(i=0;i<3;i++)
         for(j=0;j<3;j++)
             if(prova_mossa(m,giocatore,i,j)==1) {
                 m[i][j]=giocatore;
                 return;
             }
             
     for(i=0;i<3;i++)
         for(j=0;j<3;j++)
             if(prova_mossa(m,giocatore,i,j)==0) {
                 m[i][j]=giocatore;
                 return;
             }
             
     for(i=0;i<3;i++)
         for(j=0;j<3;j++)
             if(m[i][j]==0) {
                 m[i][j]=giocatore;
                 return;
             }
}

int main() {
    int u[3][3];  //inizializza l'array
    int i = 0, j = 0;  //assegna 0 a tutte le caselle il valore 0
    
	printf("Benvenuto nel gioco del tris!\nNB: Tu sei la crocetta, il computer il cerchietto. Se vuoi arrenderti durante una partita, digita -1 come mossa.\nDigita 1 se vuoi iniziare tu, 2 se preferisci che cominci il computer: ");
	
	for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            u[i][j]=0;
        }
    }
	
    int player;
	scanf("%d", &player);  //fa cominciare il giocatore scelto dall'utente
	
	//esegue la mossa finchè non sono state riempite tutte le caselle e controlla se ci sono vincitori
	while(controllo(u)==-1) {   
		if (player==1) {
			printf("\nTocca a te: inserisci le coordinate della mossa: ");
			
			do { 
				printf("\n Riga (1, 2 o 3): ");
           		scanf("%d",&i);
           		
           		if(i != -1) {
           			printf(" Colonna (1, 2 o 3): ");
           			scanf("%d",&j);
           		}
				
				if(j!=-1 && i!=-1 && i<4 && j<4 && i>0 && j>0)
					if(u[i-1][j-1]!=0) 
						printf("Casella gia' occupata. Riprova: ");
				
				if(j!=-1 && i!=-1 && (i>3 || j>3 || i<1 || j<1)) printf("Casella non disponibile. Riprova: ");
			} while((j!=-1 && i!=-1 && u[i-1][j-1]!=0) || (j!=-1 && (j>3 || j<1)) || (i!=-1 && (i>3 || i<1)));
			
			if (j==-1 || i==-1) break;
			u[i-1][j-1]=player;
    	}
    	
		else {
			printf("\nTocca al computer:  \n");
			sleep(1,7);
           	mossa(u, player);
		}
		
		printf("\n ");
		
		//stampa lo schema del turno
		for(i=0; i<3; i++) {
        	for(j=0; j<3; j++) {
        		if (u[i][j]==1) printf(" X");
				else if (u[i][j]==2) printf(" O");
				else printf(" -");
			}
			
            printf("\n ");
    	}
    	
		player=player%2+1; //cambia giocatore
	}
	
	printf("\n--> ");
	int vince = controllo (u); //controlla se ci sono vincitori
    
	if (vince==1) {printf("HAI VINTO!\n");}
	else if(vince==2) {printf("Vince il computer\n");}
    else if(vince==0) {printf("Il gioco finisce in parita'\n");}
    else printf("Ti sei arreso...\n");

    return 0;
}
