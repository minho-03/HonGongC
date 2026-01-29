#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define MAX_LEN 200

typedef struct {
    int x;
    int y;
} Point;

Point snake[MAX_LEN];
Point food;
int length = 3;
int dir = 1; // 0:위 1:오른쪽 2:아래 3:왼쪽
int gameOver = 0;
int speed = 150; // 초기 속도 (ms)

HANDLE hConsole;

void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(hConsole, c);
}

void drawBorder() {
    setColor(8); // 회색
    for (int i = 0; i <= WIDTH; i++) {
        gotoxy(i, 0); printf("#");
        gotoxy(i, HEIGHT); printf("#");
    }
    for (int i = 0; i <= HEIGHT; i++) {
        gotoxy(0, i); printf("#");
        gotoxy(WIDTH, i); printf("#");
    }
}

void spawnFood() {
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;
}

void init() {
    system("cls");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    snake[0] = (Point){ WIDTH / 2, HEIGHT / 2 };
    snake[1] = (Point){ WIDTH / 2 - 1, HEIGHT / 2 };
    snake[2] = (Point){ WIDTH / 2 - 2, HEIGHT / 2 };

    spawnFood();
}

void input() {
    if (_kbhit()) {
        int key = _getch();
        if (key == 224) key = _getch();

        if (key == 72 && dir != 2) dir = 0;
        else if (key == 77 && dir != 3) dir = 1;
        else if (key == 80 && dir != 0) dir = 2;
        else if (key == 75 && dir != 1) dir = 3;
        else if (key == 'q' || key == 'Q') gameOver = 1;
    }
}

void logic() {
    Point next = snake[0];

    if (dir == 0) next.y--;
    else if (dir == 1) next.x++;
    else if (dir == 2) next.y++;
    else if (dir == 3) next.x--;

    // 벽 충돌
    if (next.x <= 0 || next.x >= WIDTH ||
        next.y <= 0 || next.y >= HEIGHT) {
        gameOver = 1;
        return;
    }

    // 자기 몸 충돌
    for (int i = 0; i < length; i++) {
        if (snake[i].x == next.x && snake[i].y == next.y) {
            gameOver = 1;
            return;
        }
    }

    // 몸 이동
    for (int i = length; i > 0; i--)
        snake[i] = snake[i - 1];

    snake[0] = next;

    // 먹이 먹기
    if (next.x == food.x && next.y == food.y) {
        length++;
        if (speed > 50) speed -= 10; // 속도 증가
        spawnFood();
    }
}

void draw() {
    system("cls");
    drawBorder();

    // 먹이
    setColor(12); // 빨강
    gotoxy(food.x, food.y);
    printf("@");

    // 뱀
    for (int i = 0; i < length; i++) {
        if (i == 0) setColor(10); // 머리 초록
        else setColor(2);        // 몸 연두

        gotoxy(snake[i].x, snake[i].y);
        printf("O");
    }

    setColor(15); // 흰색
    gotoxy(0, HEIGHT + 1);
    printf("Length: %d | Speed: %dms | Q: Quit", length, speed);
}

int main() {
    srand((unsigned)time(NULL));
    init();

    while (!gameOver) {
        input();
        logic();
        draw();
        Sleep(speed);
    }

    system("cls");
    setColor(12);
    printf("GAME OVER\n");
    setColor(15);
    printf("Final Length: %d\n", length);
    system("pause");

    return 0;
}
