#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int score[5];
	int sum = 0;
	int max, min;		//최고점, 최저점
	double avg;			//평균

	printf("5명 심사위원의 점수 입력: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}




	//평균 구하기
	avg = (sum - max - min) / 3.0;

	printf("유효점수: ");
	printf("평균: %.1f", avg);
	return 0;
}

/*
#### 문제
다섯 명의 심사위원 점수를 입력하여 유효점수와 평균을 출력하는 프로그램을 작성합니다.
유효점수는 최고점과 최저점을 제외한 점수 이며 평균은 유효점수로 계산합니다.

#### 실행결과
5명 심사위원의 점수 입력 : 7 9 4 8 5
유효점수: 7 8 5
평균 : 6.7
*/