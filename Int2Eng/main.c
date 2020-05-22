#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* lookUpTable[] = {"zero",
	"one", "two", "three", "four",
	"five", "six", "seven", "eight",
	"nine", "ten", "eleven", "twelve",
	"thirteen", "fourteen", "fifteen", "sixteen",
	"seventeen", "eighteen", "nineteen"};
const char* tensLookUp[] = {"zero", "ten",
	"twenty", "thirty", "fourty",
	"fifty", "sixty", "seventy",
	"eighty", "ninety"};

const char* secNames[] = {"","thousand", "million","billion"};

char* int2eng(int inChar){
	printf("Input: %d\n", inChar);
	int *sections = (int*)malloc(sizeof(int)*4);
	char *outSections = (char*)malloc(sizeof(char)*512);
	if(inChar < 0){
		sprintf(outSections, "negative ");
		inChar = inChar * -1;
	}
	for(int i = 0; i < 4; i++){
		sections[i] = inChar % 1000;
		inChar = inChar/1000;
		if(sections[i] == 0)
			continue;
	}
	for(int i = 3; i >= 0; i--){
		int hundreds, tens, ones;
		hundreds = sections[i]/100;
		tens = (sections[i]/10) % 10;
		ones = sections[i] % 10;
		if(tens == 1)
			ones = sections[i]%100;
		//printf("N: %d, H: %d, T: %d, O: %d\n", sections[i], hundreds, tens, ones);
		if(hundreds != 0)
			sprintf(outSections+strlen(outSections), "%s Hundred ", lookUpTable[hundreds]);
		if(tens != 0 && tens > 1)
			sprintf(outSections+strlen(outSections),"%s ", tensLookUp[tens]);
		else if (tens != 0)
			sprintf(outSections+strlen(outSections),"%s ", lookUpTable[ones]);
		if(tens != 1 && ones != 0)
			sprintf(outSections+strlen(outSections),"%s ", lookUpTable[ones]);
		if(sections[i] != 0)
			sprintf(outSections+strlen(outSections),"%s ", secNames[i]);	
		if(i == 0)
			sprintf(outSections+strlen(outSections),"\n");
	}
	puts(outSections);
	return NULL;
}

int main(int argc, char** argv){
	if(argc < 2){
		perror("NEED A NUMBER");
		return -1;
	}

	int2eng(atoi(argv[1]));	
}
