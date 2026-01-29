/*
 * [어려움] 버퍼 연습 문제 3
 *
 * 문제: 여러 학생의 정보를 반복해서 입력받으세요.
 *       - 몇 명? (숫자)
 *       - 각 학생마다: 학점(문자), 점수(숫자)
 *
 * 예상 출력:
 * ---------------------
 * 학생 수 입력 : 2
 *
 * [1번 학생]
 * 학점 입력 (A-F) : A
 * 점수 입력 : 95
 *
 * [2번 학생]
 * 학점 입력 (A-F) : B
 * 점수 입력 : 85
 *
 * === 결과 ===
 * 1번: A (95점)
 * 2번: B (85점)
 * ---------------------
 *
 * 조건:
 * - 최대 5명까지 입력 가능
 * - 배열 사용
 * - 적절한 곳에 버퍼 비우기
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int count;           // 학생 수
    char grades[5];      // 학점 배열
    int scores[5];       // 점수 배열
    int i;               // 반복 변수

    // 학생 수 입력
    printf("학생 수 입력 : ");
    scanf("%d", &count);

    getchar();

    // 각 학생 정보 입력
    for (i = 0; i < count; i++)
    {
        printf("\n[%d번 학생]\n", i + 1);

        printf("학점 입력 (A-F) : ");
        grades[i] = getchar();

        getchar();

        printf("점수 입력 : ");
        scanf("%d", &scores[i]);
        
        getchar();
    }

    // 결과 출력
    printf("\n=== 결과 ===\n");
    for (i = 0; i < count; i++)
    {
        printf("%d번: %c (%d점)\n", i + 1, grades[i], scores[i]);
    }

    return 0;
}

