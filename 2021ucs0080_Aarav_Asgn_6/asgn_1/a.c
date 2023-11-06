#include <stdio.h>

int func() {
	printf("Please enter a number: ");
	int a;
	scanf("%d", &a);
	int b = 1;

	for(int i = 1;i <= a;i++) {
		b *= i;
	}
	return b;
}
