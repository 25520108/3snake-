#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
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

struct Point {
    int x, y;
};

class Ran {
public:
    Point A[100];
    int DoDai;

    Ran() {
        DoDai = 3;
        A[0] = { 10, 5 };
        A[1] = { 9, 5 };
        A[2] = { 8, 5 };
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

    void Ve(Point Qua) {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "O";
        }
        gotoxy(Qua.x, Qua.y);
        cout << "@";
    }

    void DiChuyen(int Huong, Point& Qua) {
        for (int i = DoDai - 1; i > 0; i--) {
            A[i] = A[i - 1];
        }

        if (Huong == 0) A[0].y--;
        if (Huong == 1) A[0].x++;
        if (Huong == 2) A[0].y++;
        if (Huong == 3) A[0].x--;

        if (A[0].x == Qua.x && A[0].y == Qua.y) {
            DoDai++;
            Qua.x = rand() % 40 + 3;
            Qua.y = rand() % 15 + 3;
        }
    }
};

int main() {
    AnConTro();
    srand((int)time(0));

    Ran r;
    int Huong = 1;

    Point Qua;
    Qua.x = rand() % 40 + 3;
    Qua.y = rand() % 15 + 3;

    while (1) {
        if (_kbhit()) {
            char c = _getch();
            if ((c == 'w' || c == 'W') && Huong != 2) Huong = 0;
            if ((c == 'd' || c == 'D') && Huong != 3) Huong = 1;
            if ((c == 's' || c == 'S') && Huong != 0) Huong = 2;
            if ((c == 'a' || c == 'A') && Huong != 1) Huong = 3;
        }

        system("cls");
        r.Ve(Qua);
        r.DiChuyen(Huong, Qua);

        Sleep(200);
    }

    return 0;
}
