/*
 * [쉬움] 버퍼 연습 문제 1
 *
 * 문제: 이름(문자 1개)과 나이(숫자)를 입력받아 출력하세요.
 *
 * 예상 출력:
 * ---------------------
 * 이름 첫 글자 입력 : K
 * 나이 입력 : 25
 * 이름: K, 나이: 25
 * ---------------------
 *
 * 조건:
 * - 이름은 getchar()로 입력
 * - 나이는 scanf()로 입력
 * - 입력 순서: 이름 먼저, 나이 나중
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int name;   // 이름 첫 글자
    int age;    // 나이

    
    printf("이름 첫 글자 입력 : ");

    name = getchar();


    printf("나이 입력 : ");

    scanf("%d", &age);

    printf("이름: %c, 나이: %d\n", name, age);

    return 0;
}