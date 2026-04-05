#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void AnConTro() {
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

#define MINX 2
#define MINY 1
#define MAXX 50
#define MAXY 20

void VeKhung() {
    for (int i = MINX; i <= MAXX; i++) {
        for (int j = MINY; j <= MAXY; j++) {
            if (i == MINX || i == MAXX || j == MINY || j == MAXY) {
                gotoxy(i, j);
                cout << "*";
            }
        }
    }
}

struct Point {
    int x, y;
};

class Ran {
public:
    Point A[100];
    int DoDai;

    Ran() {
        DoDai = 3;
        A[0] = {10, 5};
        A[1] = {9, 5};
        A[2] = {8, 5};
    }

    void Ve() {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "O";
        }
    }

    void Xoa() {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << " ";
        }
    }

    void DiChuyen(int Huong) {
        for (int i = DoDai - 1; i > 0; i--) {
            A[i] = A[i - 1];
        }

        if (Huong == 0) A[0].y--;
        if (Huong == 1) A[0].x++;
        if (Huong == 2) A[0].y++;
        if (Huong == 3) A[0].x--;
    }
};

int main() {
    AnConTro();

    Ran r;
    int Huong = 1;

    while (1) {
        if (_kbhit()) {
            char c = _getch();
            if ((c == 'w' || c == 'W') && Huong != 2) Huong = 0;
            if ((c == 'd' || c == 'D') && Huong != 3) Huong = 1;
            if ((c == 's' || c == 'S') && Huong != 0) Huong = 2;
            if ((c == 'a' || c == 'A') && Huong != 1) Huong = 3;
        }

        system("cls");
        VeKhung();
        r.DiChuyen(Huong);
        r.Ve();

        Sleep(200);
    }

    return 0;
}
