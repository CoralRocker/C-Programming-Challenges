#include <stdio.h>
#include <stdlib.h>

void print(long n)
{
	char tmp = 0, i = 0;
	char tmparr[256];
	while(n)
	{
		tmp = n % 10;
		tmp+=48;
		tmparr[i] = tmp;
		i++;
		n/=10;
	}
	i--;
	for(; i >= 0; i--)
		putchar(tmparr[i]);
	putchar(0xA);
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	long num = rand();
	printf("Number: %ld\n", num);
	print(num);
}
