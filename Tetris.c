#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   // _getch()
#include <windows.h> // Sleep()

#define WIDTH 10
#define HEIGHT 15

int board[HEIGHT][WIDTH] = { 0 };

/* 테트리스 블록 7종 (4x4) */
int blocks[7][4][4] = {
    // O
    {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
    // I
    {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
    // L
    {{0,0,0,0},{1,1,1,0},{1,0,0,0},{0,0,0,0}},
    // J
    {{0,0,0,0},{1,1,1,0},{0,0,1,0},{0,0,0,0}},
    // T
    {{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
    // S
    {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
    // Z
    {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}}
};

int curBlock[4][4];
int bx = 3, by = 0;

void copyBlock(int dst[4][4], int src[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            dst[i][j] = src[i][j];
}

void newBlock() {
    int r = rand() % 7;
    copyBlock(curBlock, blocks[r]);
    bx = 3;
    by = 0;
}

int canMove(int nx, int ny, int block[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block[i][j]) {
                int y = ny + i;
                int x = nx + j;
                if (x < 0 || x >= WIDTH || y >= HEIGHT)
                    return 0;
                if (y >= 0 && board[y][x])
                    return 0;
            }
        }
    }
    return 1;
}

void fixBlock() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (curBlock[i][j])
                board[by + i][bx + j] = 1;
}

void clearLine() {
    for (int i = HEIGHT - 1; i >= 0; i--) {
        int full = 1;
        for (int j = 0; j < WIDTH; j++)
            if (!board[i][j]) full = 0;

        if (full) {
            for (int k = i; k > 0; k--)
                for (int j = 0; j < WIDTH; j++)
                    board[k][j] = board[k - 1][j];
            for (int j = 0; j < WIDTH; j++)
                board[0][j] = 0;
            i++;
        }
    }
}

void rotateBlock() {
    int tmp[4][4] = { 0 };
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[j][3 - i] = curBlock[i][j];

    if (canMove(bx, by, tmp))
        copyBlock(curBlock, tmp);
}

void draw() {
    system("cls");

    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            int printed = 0;
            for (int y = 0; y < 4; y++) {
                for (int x = 0; x < 4; x++) {
                    if (curBlock[y][x] &&
                        i == by + y && j == bx + x) {
                        printf("#");
                        printed = 1;
                    }
                }
            }
            if (!printed) {
                if (board[i][j]) printf("#");
                else printf(" ");
            }
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
}

int main(void) {
    srand(time(NULL));
    newBlock();

    while (1) {
        draw();

        if (_kbhit()) {
            int key = _getch();

            if (key == 224) key = _getch(); // 방향키 처리

            if (key == 75 && canMove(bx - 1, by, curBlock))       // ←
                bx--;
            else if (key == 77 && canMove(bx + 1, by, curBlock)) // →
                bx++;
            else if (key == 80) {                               // ↓
                if (canMove(bx, by + 1, curBlock))
                    by++;
                else {
                    fixBlock();
                    clearLine();
                    newBlock();
                    if (!canMove(bx, by, curBlock)) {
                        draw();
                        printf("GAME OVER\n");
                        break;
                    }
                }
            }
            else if (key == 72)                                 // ↑
                rotateBlock();
            else if (key == 'q' || key == 'Q')
                break;
        }

        Sleep(50); // CPU 사용률 낮추기
    }

    return 0;
}
