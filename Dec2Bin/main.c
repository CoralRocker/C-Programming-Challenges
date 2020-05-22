#include <stdio.h>
#include <stdlib.h>

void binOut(char* str, int strlen, unsigned int num){
	str[strlen-1] = 0x00;
	for(int i = strlen-2; i >= 0; i--){
		str[i] = (num % 2) + 48;
		num = num/2;
	}
}

int main(int argc, char** argv){
	int strlen = (argc > 2) ? atoi(argv[2]) + 1 : 9;
	char out[strlen];
	binOut(&out, strlen, atoi(argv[1]));
	puts(out);
}
