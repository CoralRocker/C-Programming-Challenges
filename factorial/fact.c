#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t factorial(unsigned long long n){
	return (n == 1) ? (uint64_t)1 : n * factorial(n-1LL);
}

int main(int argc, char** argv){
	if(argc < 2){
		perror("ERROR: NEED ARG");
	}
	uint64_t num = factorial(atoi(argv[1])), n = num;
	int trailing = 0;
	printf("ULL: %d, UL: %d, UINT64_T: %d\n",
			sizeof(unsigned long long),
			sizeof(unsigned long),
			sizeof(uint64_t));
	while((num - (10ULL*(num - 10ULL))) == 0ULL){
		trailing++;
		printf("N: %llu, %d, %d\n", num, num % (uint64_t)10, trailing);
		num = num / (uint64_t)10;
	}
	printf("Num: %s, Factorial: %llu, Trailing Zeroes: %d\n", argv[1], n, trailing);

}
