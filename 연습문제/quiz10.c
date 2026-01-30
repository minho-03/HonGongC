#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void rotate(int* pa, int* pb, int* pc);
int main(void) {

	int a = 1, b = 2, c = 3;
	char ch;

	while (1)
	{
		printf("%d:%d:%d",a,b,c);
		
		ch = getchar();

		if (ch != '\n')
			break;
		rotate(&a, &b, &c);
	}

	return 0;
}
void rotate(int* pa, int* pb, int* pc) {
	int num;
	num = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = num;
}

/*
#### 문제
숫자 이동프로그램
1,2,3으로 초기화된 세 변수의 값을 하나씩 왼쪽으로 이동하여 출력합니다.
가장 왼쪽의 값은 가장 오른쪽으로 이동합니다.
키보드로 엔터를 입력할 때 마다 값을 이동하며, 엔터 이외의 키를 입력하면 종료합니다.
세변수의 값을 동시에 바꾸는 함수를 만들어 사용하여, 함수 원형은 다음과 같이 작성합니다.

void rotate(int *pa, int *pb, int *pc);

실행결과
1:2:3 (Enter) // 최초 세 변수의 값 1, 2, 3 출력
2:3:1 (Enter) // 각 값을 왼쪽으로 이동, 가장 왼쪽의 값은 가장 오른쪽으로 이동
3:1:2 (Enter)
1:2:3 (Enter)
2:3:1x (Enter) // 다른 문자와 함께 엔터 입력하면 반복 종료
*/