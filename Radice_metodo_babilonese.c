#include <stdio.h>
#include <stdlib.h>

#define PREC 0.0001

/*calcola la radice quadrata 
approssimata con il metodo babilonese*/
float BabMethod(float numero) {
	float xn;
	xn=numero;
	while (xn*xn-numero >= PREC)
	      xn=0.5*(xn+numero/xn);
	return xn;
}

int main() {
	    
	float n=101;
	printf("Inserisci il numero di cui vuoi calcolare la radice: ");
    scanf("%f",&n);
    
	printf("La radice cercata e': %2.4f ", BabMethod(n));
	    
	return 0;
}





