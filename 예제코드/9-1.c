#include <stdio.h>

int main(void) {
	int a;
	double b;
	char c;

	printf("int형 변수의 주소 : %u\n", &a);
	printf("int형 변수의 주소 : %u\n", &b);
	printf("int형 변수의 주소 : %u\n", &c);

	return 0;
}