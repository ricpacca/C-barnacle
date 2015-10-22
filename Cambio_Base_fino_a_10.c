#include <stdio.h>
#include <math.h>

/*cambio basi per basi fino a 10*/
int FromTen (int num, int base) {
	int r[100], i=0, nuovo=0;
		
	while(num) {
		r[i]=num%base;
		num=num/base;
		i++;
	}
	
	for(i=i-1; i>=0; i--)
		nuovo = nuovo*10 + r[i];
	
	return nuovo;}
	
int ToTen (int num, int base) {
	int i=0, nuovo=0;
		
	for (i=0; num; i++)
	{
		nuovo = nuovo + num%10*pow(base, i);
		num=num/10;
	}
	
	return nuovo;}

int main()
{
	int n = 54; /*non più di 7 cifre!*/
	int base = 3; /*dev'essere minore di 10!*/
	int nuovo = FromTen(n, base);
	printf("Base 10: \t%d\nBase %d: \t%d\nBase 10: \t%d\n", n, base, nuovo, ToTen(nuovo, base));
}
