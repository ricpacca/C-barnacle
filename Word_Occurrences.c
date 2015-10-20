#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns the number of occurrences of the words included in the string words (separated by commas), in the sentence 
NB: the commented lines can be uncommented to avoid counting occurrences of the words if present inside other words (e.g. "test" in "testing")*/

int wordsOccurrences(char words[], char sentence[]) {
	int i, j, k, counter = 0;
	for (i = 0; i < strlen(words); i++) {
		for(j = 0; j < strlen(sentence); j++) {
			if ((words[i-1] == ',' || i == 0) && words[i] == sentence[j]) {
				for (k=0; words[i+k] != ',', words[i+k] != '\0'; k++)
					if (words[i+k] != sentence[j+k])
						break;
				
				/* if (j==0)
					if ((words[i+k] == '\0' || words[i+k] == ',') && (sentence[j+k] == ' ' || sentence[j+k] == '\0' || sentence[j+k] == ','))
						counter++; */
				
				if ((words[i+k] == '\0' || words[i+k] == ',') /* && sentence[j-1] == ' ' && (sentence[j+k] == ' ' || sentence[j+k] == '\0' || sentence[j+k] == ',')*/) 
					counter++;
			}
		}
	}
	
	return counter;
}

/* Returns the number of occurrences of the word in the sentence 
NB: the commented lines can be uncommented to avoid counting occurrences of the word if present inside other words (e.g. "test" in "testing")*/

int wordOccurrences(char word[], char sentence[]) {
	int j, k, counter = 0;
	
	for(j=0; j < strlen(sentence); j++)
		if (word[0]==sentence[j]) {
			for (k=0; k < strlen(word); k++)
				if (word[k] != sentence[j+k])
					break;
			
			/*if(j==0) 
				if (k==(strlen(word)) && (sentence[j+k] == ' ' || sentence[j+k] == '\0' || sentence[j+k] == ','))
					counter+=1;*/
			
			if (k==(strlen(word)) /*&& sentence[j-1]==' ' && (sentence[j+k] == ' ' || sentence[j+k] == '\0' || sentence[j+k] == ',')*/) 
				counter+=1;
		}
		
	return counter;
}

void main() {
	char sentence[]="This string is a test string which should return 6 occurrences of the words string and test and 3 occurrences of the word test!";
	char words[]="string,test";
	char word[]="test";
	printf ("wordsOccurrences: %i\n", wordsOccurrences(words, sentence));
	printf ("wordOccurrences: %i\n", wordOccurrences(word, sentence));
}
