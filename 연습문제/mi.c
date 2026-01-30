#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char map[5][5] = {
        {'■','■','■','■','■'},
        {'■','P',' ',' ','■'},
        {'■','■','■',' ','■'},
        {'■',' ',' ','E','■'},
        {'■','■','■','■','■'}
    };

    int px = 1, py = 1;   // 플레이어 위치
    char input;

    while (1) {
        // 화면 출력
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        printf("이동 (w/a/s/d): ");
        scanf(" %c", &input);

        int nx = px;
        int ny = py;

        // 이동 방향 계산
        if (input == 'w') nx--;
        else if (input == 's') nx++;
        else if (input == 'a') ny--;
        else if (input == 'd') ny++;
        else {
            printf("잘못된 입력입니다.\n\n");
            continue;
        }

        // 벽이면 이동 불가
        if (map[nx][ny] == '■') {
            printf("벽입니다! 이동 불가\n\n");
            continue;
        }

        // 출구 도착
        if (map[nx][ny] == 'E') {
            printf("\n🎉 탈출 성공! 🎉\n");
            break;
        }

        // 이동 처리
        map[px][py] = ' ';
        px = nx;
        py = ny;
        map[px][py] = 'P';

        printf("\n");
    }

    return 0;
}

