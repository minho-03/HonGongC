#include <stdio.h>

int rec_func(int n);

int main(void) {

	int sum = 0;
	sum = rec_func(10);

	printf("%d", sum);

}

int rec_func(int n)
{
	if (n == 0) {
		return 0;
	}
	else {
		return n + rec_func(n - 1);
	}
}