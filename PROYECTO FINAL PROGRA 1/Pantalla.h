#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Pantalla
{
public:
	Pantalla() {
	}
    void gotoxy(int x, int y)
    {
        HANDLE Pantalla;
        Pantalla = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordenadas;
        coordenadas.X = x;
        coordenadas.Y = y;
        SetConsoleCursorPosition(Pantalla, coordenadas);
    }

    void dibujarCuadro(int x1, int y1, int x2, int y2) {
        int i;
        char a;
        for (i = x1; i < x2; i++) {
            a = 205;
            gotoxy(i, y1); cout << a; //linea horizontal superior
            gotoxy(i, y2); cout << a; //linea horizontal inferior
        }

        for (i = y1; i < y2; i++) {
            a = 186;
            gotoxy(x1, i); cout << a; //linea vertical izquierda
            gotoxy(x2, i); cout << a; //linea vertical derecha
        }
        a = 201;
        gotoxy(x1, y1); cout << a;
        a = 200;
        gotoxy(x1, y2); cout << a;
        a = 187;
        gotoxy(x2, y1); cout << a;
        a = 188;
        gotoxy(x2, y2); cout << a;
    }

    void color(int c) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, c);
    }
};

