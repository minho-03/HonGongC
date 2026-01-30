#include <stdio.h>

int main(void) {
	
	char name[] = "홍길동";
	int age = 17;
	float zl = 190.0;
	char blood[] = "AB";

	age = age + 10;
	zl = zl + 0.5;


	printf("10년 후의 프로필...\n");
	printf("이름: %s\n", name);
	printf("나이: %d\n", age);
	printf("키: %.1f\n", zl);
	printf("혈액형: %s", blood);


	return 0;
}

//이름, 나이, 키, 혈액형을 저장할 변수나 배열을 선언하고 자신의 프로필을 초기화합니다.
// 그리고 10년 후의 프로필을을 출력합니다. 이름과 혈액형은 변함이 없고 키는 0.5cm 줄어든다고 가정합니다.
// 실행결과는 이름은 홍길동, 나이는 17, 키는 190.0, 혈액형은 AB로 초기화한 경우 입니다.

//실행결과
//10년 후의 프로필...
//이름: 홍길동
//나이 : 27살
//키 : 189.5cm
//혈액형 : AB형