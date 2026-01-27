#include <stdio.h>

prime_check(int num); //함수 선언

int main(void) 
{
    int prime_number = 32767; 

    if (prime_check(prime_number) == 1) {
        printf("소수가 맞습니다.");
    }
    else {
        printf("소수가 아닙니다.");
    }

    return 0;
}

prime_check(int num)
{
    if (num <= 1)
        return 0;   // 1 이하 → 소수 아님

    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;   // 나누어떨어지면 소수 아님
    }

    return 1;   // 끝까지 안 나눠지면 소수
}



/*
문제
32767이 소수(prime number)인지 아닌지를 판단하여 출력하는 프로그램을 작성합니다.
단, 정수를 인수로 받아 소수면 1을 반환하고 소수가 아니면 0을 반환하는 함수를 만들고 main 함수에서 호출하여 작성합니다.
함수명은 prime_check로 합니다. 

#실행결과 
소수가 아닙니다. 
*/