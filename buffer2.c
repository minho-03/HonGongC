/*
 * [중간] 버퍼 연습 문제 2
 *
 * 문제: 학생 정보를 입력받아 출력하세요.
 *       - 학번 (숫자)
 *       - 이름 첫 글자 (문자)
 *       - 학점 (문자: A, B, C, D, F)
 *
 * 예상 출력:
 * ---------------------
 * 학번 입력 : 20240001
 * 이름 첫 글자 입력 : K
 * 학점 입력 : A
 *
 * === 학생 정보 ===
 * 학번: 20240001
 * 이름: K
 * 학점: A
 * ---------------------
 *
 * 조건:
 * - 적절한 곳에 버퍼 비우기 사용
 * - getchar() 사용
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int studentId;    // 학번
    int name;         // 이름 첫 글자
    int grade;        // 학점

    // 학번 입력
    printf("학번 입력 : ");
    scanf("%d", &studentId);

    getchar();

    // 이름 입력
    printf("이름 첫 글자 입력 : ");
    name = getchar();

    getchar();

    // 학점 입력
    printf("학점 입력 : ");
    grade = getchar();

    // 결과 출력
    printf("\n=== 학생 정보 ===\n");
    printf("학번: %d\n", studentId);
    printf("이름: %c\n", name);
    printf("학점: %c\n", grade);

    return 0;
}

