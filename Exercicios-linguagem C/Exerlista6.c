/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..Verificar medidas triangulo*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define col 8
#define lin 22

void gotoxy(int x, int y);
void layout();
int verif_triangulo(int x, int y, int z);
int ver_triangulo(int x, int y, int z);
void limpar(int limp);

// PROGRAMA PRINCIPAL
int main()
{
    int x;
    int y;
    int z;
    int result;
    int reiniciar;
    int limp = 8;

    do
    {
        layout();
        do
        {
            gotoxy(25, 5);
            printf("                         ");
            gotoxy(lin, col);
            printf("Insira o valor de X .......");
            gotoxy(lin + 28, col);
            scanf("%d", &x);
            if (x <= 0)
            {
                limpar(limp);
            }
        } while (x <= 0);
        do
        {
            gotoxy(25, 5);
            printf("                         ");
            gotoxy(lin, col + 2);
            printf("Insira o valor de Y ....... ");
            scanf("%d", &y);
            if (y <= 0)
            {
                limpar(limp + 2);
            }
        } while (y <= 0);
        do
        {
            gotoxy(25, 5);
            printf("                         ");
            gotoxy(lin, col + 4);
            printf("Insira o valor de Z ....... ");
            scanf("%d", &z);
            if (z <= 0)
            {
                limpar(limp + 4);
            }

        } while (z <= 0);
        result = verif_triangulo(x, y, z);

        if (result == 1)
        {
            gotoxy(lin - 6, col + 6);
            printf("===SUAS MEDIDAS FORMAM UM TRIANGULO=== \n");
            result = ver_triangulo(x, y, z);
            switch (result)
            {
            case 1:
                gotoxy(lin + 5, col + 8);
                printf("===EQUILATERO===");
                break;
            case 2:
                gotoxy(lin + 5, col + 8);
                printf("===ISOCELES===");
                break;
            case 3:
                gotoxy(lin + 5, col + 8);
                printf("===ESCALENO===");
                break;
            }
        }
        else
        {
            gotoxy(lin - 6, col + 6);
            printf("===SUAS MEDIDAS NAO FORMAM UM TRIANGULO=== \n");
        }
        gotoxy(42, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);

    gotoxy(01, 24);
    return 0;
}

// DECLARAÇÃO DAS FUNÇOES
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
    printf("*EXERCICIO 6*");
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

int verif_triangulo(int x, int y, int z)
{
    if (x < y + z && y < x + z && z < y + x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ver_triangulo(int x, int y, int z)
{
    if (x == y || x == z)
    {
        if (y == z)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if (y == z)
        {
            return 2;
        }
        return 3;
    }
}

void limpar(int limp)
{
    gotoxy(50, limp);
    printf("       ");
    gotoxy(25, 5);
    printf("*INSIRA UM NUMERO VALIDO*");
    getch();
}