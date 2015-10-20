#include <stdio.h>
#include <string.h>

// returns 1 if the string str is palindrome
int palindrome_string(char str[]) {
	if (strlen(str) == 1) return 1;
	
	int j;
	for (j = 0; j<strlen(str); j++)
		if (str[strlen(str) - 1 - j] != str[j])
			return 0;
	
	return 1;
}

// returns 1 if the number n is palindrome
int palindrome_int(int n) {
	int mirror = 0;
	int temp=n;
	
	while(temp != 0) {
		mirror = mirror*10 + temp%10;
		temp = temp/10;
	}
	
	if (mirror==n) return 1;
	else return 0;
}

void main(int argc, char *argv[]) {
	if(argc == 1) printf("No arguments passed.\n");
	
	while (--argc) {
		if(palindrome_string(*++argv) == 1)
			printf("%s is a palindrome\n", *argv);
		else
			printf("%s is not a palindrome\n", *argv);
	}
}
