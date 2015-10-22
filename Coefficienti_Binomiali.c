#include <stdio.h>
#include <stdlib.h>

int cobin(int n, int k);

int main(){
    
    int n,k;
	printf("Inserisci il numero di cui vuoi calcolare i coefficienti binomiali: ");
    scanf("%d",&n);
    for (k=0; k<=n; k++)
        printf("%d ",cobin(n,k));
 
	return 0;
}

/*calcola il coefficiente binomiale n su k*/
int cobin(int n, int k) {
    if ((k==0) || (k==n)) return 1;
    else return cobin(n-1,k) + cobin(n-1,k-1);
}
