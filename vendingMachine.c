#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
    int choice;

    // 상품 정보
    char* products[] = { "콜라", "환타", "커피", "사이다", "웰치스", "박카스"};
    int prices[] = { 1200, 1000, 800, 1000, 1400, 1000 };
    int stock[] = {10, 10, 10, 10, 10, 10};

    // 메뉴 출력
    printf("========= 자판기 =========\n");
    printf("1. %s %d원 수량: %d\n", products[0], prices[0], stock[0]);
    printf("2. %s %d원 수량: %d\n", products[1], prices[1], stock[1]);
    printf("3. %s %d원  수량: %d\n", products[2], prices[2], stock[2]);
    printf("4. %s %d원 수량: %d\n", products[3], prices[3], stock[3]);
    printf("5. %s %d원 수량: %d\n", products[4], prices[4], stock[4]);
    printf("6. %s %d원 수량: %d\n", products[5], prices[5], stock[5]);
    printf("==========================\n");

    // 선택 입력
    printf("음료를 선택하세요: ");
    scanf("%d", &choice);

    // 선택 확인
    printf("\n[%s]를 선택하셨습니다. %d원입니다.\n",
        products[choice - 1], prices[choice - 1], stock[choice - 1]);


    return 0;


}
