/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..NOTA DO ALUNO*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define test "**PESSIMO!! SUA NOTA FOI D**"
#define test2 "**MEDIANO!! SUA NOTA FOI C**"
#define test3 "****BOM!! SUA NOTA FOI B****"
#define test4 "*EXCELENTE!! SUA NOTA FOI A*"
#define Max 4
#define col 10

const char *conceito(float notas[], int n);
void layout();
void gotoxy(int x, int y);
void limpar(int limp);

int main()
{
    int i;
    int reiniciar;
    int limp = 10;
    float notas[Max];

    do
    {
        layout();
        for (i = 0; i < Max; i++)
        {
            do
            {
                gotoxy(25, 5);
                printf("                         ");
                gotoxy(22, col + i);
                printf("Insira sua %d nota ......", i + 1);
                gotoxy(47, col + i);
                scanf("%f", &notas[i]);
                if (notas[i] < 0)
                {
                    limpar(limp + i);
                }
            } while (notas[i] < 0);
        }
        gotoxy(21, col + Max);
        printf("%s", conceito(notas, Max));
        gotoxy(43, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
}

const char *conceito(float notas[], int n)
{
    int i;
    float media = 0;
    for (i = 0; i < n; i++)
    {
        media = media + notas[i];
    }
    media = media / n;
    if (media > 0 && media < 4.9)
    {
        return test;
    }
    else if (media < 6.9)
    {
        return test2;
    }
    else if (media < 8.9)
    {
        return test3;
    }
    else
    {
        return test4;
    }
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
    printf("*EXERCICIO 8*");
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
    gotoxy(47, limp);
    printf("       ");
    gotoxy(25, 5);
    printf("*INSIRA UM NUMERO VALIDO*");
    getch();
}