#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int num = 0;
	int result = 0;
	
	while (1) {
		printf("양수 입력: ");
		scanf("%d", &num);				//양수만 입력

		if (num <= 0)					//음수이거나 0이면 종료
			break;
		
		result = result + num;			//입력받은 누적결과 덧셈
		
	}
		printf("누적된 값: %d", result); //누적값 출력
}

/*
#### 문제
반복적으로 양수를 입력받아 총합을 구하는 프로그램을 작성합니다.
0이나 음수를 입력하면 반복을 끝내고 그 동안 누적한 합을 출력합니다.
처음부터 0이나 음수가 입력되면 바로 반복을 끝내고 0을 출력합니다.

#### 실행결과
양수 입력 : 5 (Enter)
양수 입력 : 10 (Enter)
양수 입력 : -1 (Enter)
누적된 값 : 15
*/