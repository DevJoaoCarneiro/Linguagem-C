/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..DESCOBRIR DE O NUMERO E PRIMO*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Max 10

void gotoxy(int x, int y);
void layout();
int ehprimo(int x, int i);

int main()
{
    int num;
    int i = 2;
    int test;
    int reiniciar;

    do
    {
        system("color 0f");
        layout();
        do
        {
            gotoxy(25, Max - 5);
            printf("                         ");
            gotoxy(20, Max);
            printf("Insira um numero inteiro ...... ");
            gotoxy(52, Max);
            scanf("%d", &num);
            if (num < 0)
            {
                gotoxy(52, Max);
                printf("       ");
                gotoxy(25, Max - 5);
                printf("*INSIRA UM NUMERO VALIDO*");
                getch();
            }
        } while (num < 0);
        test = ehprimo(num, i);
        if (test != num)
        {
            system("color 0a");
            gotoxy(20, Max + 2);
            printf("=======  O numero %d primo  =======", num);
        }
        else
        {
            system("color 0c");
            gotoxy(20, Max + 2);
            printf("===== O numero %d nao e primo =====", num);
        }
        gotoxy(43, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
}

// DECLARAÇOES DE FUNÇÃO
int ehprimo(int x, int i)
{
    for (i = 2; i < x - 1; i++)
    {
        if (x % i == 0)
        {
            return x;
        }
    }
    return 1;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void layout()
{
    int i;
    system("cls");
    printf("===============================================================================\n");
    for (i = 0; i < 22; i++)
    {
        printf("|                                                                             |\n");
    }
    printf("===============================================================================\n");
    gotoxy(30, 02);
    printf("*EXERCICIO 2*");
    gotoxy(01, 01);
    printf("Autor.......Joao Carneiro");
    gotoxy(01, 02);
    printf("Faculdade...UNICV");
    gotoxy(01, 03);
    printf("Ano.........2024");
    gotoxy(00, 04);
    printf("===============================================================================\n");
    gotoxy(00, 20);
    printf("===============================================================================\n");
    gotoxy(01, 21);
    printf("Reiniciar o programa (1-Sim 2-Nao).......");
}