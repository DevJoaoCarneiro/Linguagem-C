/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..CALCULO PESO IDEAL*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Col 10
#define lin 18

float calc_ideal(float alt, float sexo);
void gotoxy(int x, int y);
void layout();
void limpar(int limp);

int main()
{
    float alt;
    float sexo;
    float exec;
    int reiniciar;
    int limp = 10;

    do
    {
        layout();
        do
        {
            gotoxy(25, 5);
            printf("                         ");
            gotoxy(lin, Col);
            printf("Insira o sexo (1-Homem 2-Mulher) .... ");
            gotoxy(lin + 38, Col);
            scanf("%f", &sexo);
            if (sexo != 1 && sexo != 2)
            {
                limpar(limp);
            }
        } while (sexo != 1 && sexo != 2);

        do
        {
            gotoxy(lin, Col + 2);
            printf("Insira a altura ..................... ");
            gotoxy(lin + 38, Col + 2);
            scanf("%f", &alt);
            if (alt < 1 || alt > 2.4)
            {
                limpar(limp + 2);
            }
        } while (alt < 1 || alt > 2.4);
        exec = calc_ideal(alt, sexo);

        gotoxy(lin, Col + 4);
        printf("O seu peso ideal e .................. %.2f Kg", exec);
        gotoxy(42, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
}

float calc_ideal(float alt, float sexo)
{
    float peso_ideal;
    if (sexo == 1)
    {
        peso_ideal = 72.7 * alt - 58;
    }
    else
    {
        peso_ideal = 62.1 * alt - 44.7;

    }
    return peso_ideal;
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
    printf("*EXERCICIO 7*");
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

void limpar(int limp)
{
    gotoxy(lin + 38, limp);
    printf("       ");
    gotoxy(25, 5);
    printf("*INSIRA UM NUMERO VALIDO*");
    getch();
}