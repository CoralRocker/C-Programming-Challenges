#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int bin2dec(char* bin){
	int slen = strlen(bin);
	unsigned long counter;
	for(int i = slen - 1; i >=0; i--){
		if(bin[i] == '1'){
			counter += pow(2,slen - i - 1);
		}
	}
	printf("Num: %lu\n", counter);
	return counter;
}

int main(int argc, char** argv){
	if(argc > 1)
		bin2dec(argv[1]);
}
