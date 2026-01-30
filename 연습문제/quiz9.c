#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void func(int num,int *mod,int *rem);   //함수 선언
int main(void)
{
    int mod, rem;                       //몫과 나머지 변수 선언
    int num;                            //입력받을 양수 변수 선언
    printf("양수입력: ");                //출력
    scanf("%d", &num);                  //키보드로 입력 받는 값 저장

    func(num, &mod, &rem);              //함수 호출 

    printf("몫 : % d, 나머지 : % d", mod, rem); //값 출력

    return 0;
}
void func(int num, int *mod, int *rem) {       //몫과 나머지 구하는 함수
    *mod = num / 4;                            //몫 구하기
    *rem = num % 4;                            //나머지 구하기
}
/*
#### 문제
몫과 나머지 입력 프로그램
키보드로 입력한 양수를 4로 나누어 몫과 나머지를 변수에 저장하는 함수를 만듭니다.
다음 main 함수와 실행결과를 참고하여 작성합니다.

#### main함수
int main(void)
{
     int mod, rem;
     func(&mod, &rem);
     printf(""몫 : %d, 나머지 : %d"", mod, rem);

     return 0;
}

#### 실행결과
양수 입력 : 9
몫: 2, 나머지 : 1
*/