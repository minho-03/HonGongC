#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char str[80];
	int cnt = 0;
	int i;

	printf("두 문자열 입력: ");
	gets(str);
   
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a'-'A');
            cnt++;
        }
    }

	                                                         
		printf("바뀐 문장:" );
		puts(str);
		printf("바뀐 문자 수: %d", cnt);

	return 0;
}