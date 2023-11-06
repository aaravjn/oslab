#include "stdio.h"
#include "a.h"
#include "b.h"

int main() {
	int a = func();
	int b = calcDigits(a);
	
	printf("Total number of digits are %d \n", b);
}
