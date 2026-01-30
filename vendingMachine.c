#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char again;
int main(void)

{
    do {
        // 구매자의 선택
        int choice;

        // 상품 정보
        char* products[] = { "콜라", "환타", "커피", "사이다", "웰치스", "박카스" };
        int prices[] = { 1200, 1000, 800, 1000, 1400, 1000 };
        int stock[] = { 10, 10, 10, 10, 10, 0 };

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

        if (stock[choice - 1] == 0) {
            printf("품절입니다ㅠㅠ\n");
        }
        else {
            // 선택 확인
            printf("\n[%s]은 %d원입니다.\n",
                products[choice - 1], prices[choice - 1], stock[choice - 1]);

            // 돈을 넣은 누적 금액
            int money = 0;

            // 선택한 상품의 가격 
            int price = prices[choice - 1];

            // 금액 입력 + 잔액 표시 하는 과정
            printf("\n돈을 넣어주세요.\n");
            while (money < price) {
                int input;

                printf("투입 (현재: %d원, 필요: %d원): ", money, price);
                scanf("%d", &input);
                money += input;                         // 투입한 돈 누적으로 계산

                if (money < price) {
                    printf("→ %d원 부족합니다.\n", price - money);
                }
            }
            printf("\n금액이 충분합니다!\n");

            // 잔돈 = 투입 금액 - 상품 가격
            int change = (money - price);

            printf("\n====== 구매 완료 ======\n");
            printf("[%s]를 가져가세요.\n", products[choice - 1]);
            stock[choice - 1]--;            // 재고 감소

            if (change > 0) {
                printf("거스름돈: %d원\n", change);
            }
        }
            printf("재구매 하시겠습니까? (y/n)\n");
            getchar();                      // 버퍼 지우기
            again = getchar();              // y,n 입력 받기

    } while (again == 'y' || again == 'Y'); //y,Y이면 다시 반복 구매
    printf("이용해주셔서 감사합니다!\n");
    return 0;
}
