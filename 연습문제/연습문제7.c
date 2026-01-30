#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int score[5];
	int sum = 0;		//점수의 총합
	int max;			//최고점
	int min;			//최저점
	double avg;			//평균

	printf("5명 심사위원의 점수 입력: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}
	
	// 유효점수 구하기
	max = score[0];
	min = score[0];
	for (int i = 0; i < 5; i++) {
		sum += score[i];
		if (score[i] > max) {
			max = score[i];
		}
		if (score[i] < min) {
			min = score[i];
		}
	}
	
	// 유효점수 출력하기
	printf("유효점수: ");
	for (int i = 0; i < 5; i++) {
		if (score[i] == max) {		//점수가 최고점(max)이면 건너뛰기
			continue;
		}
		if (score[i] == min) {		//점수가 최고점(max)이면 건너뛰기
			continue;
		}
		printf("%d ",score[i]);		//건너뛴 값 빼고 출력
	}

	//평균 구하기
	avg = (sum - max - min) / 3.0;	//(총합-최고점-최저점) / 3.0 = 평균
	printf("평균: %.1f", avg);		//소수점 첫번째 자리까지 표시
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