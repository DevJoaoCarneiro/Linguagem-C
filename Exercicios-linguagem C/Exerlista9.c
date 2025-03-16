/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..INFORMA CLASSE*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define test "==Infantil A=="
#define test2 "==Infantil B=="
#define test3 "==Juvenil A=="
#define test4 "==Juvenil B=="
#define test5 "===Adulto===="

const char *nome(int idade);
void gotoxy(int x, int y);
void layout();
void limpar(int limp);

int main()
{
    int id;
    int reiniciar;
    int limp = 12;

    do
    {
        layout();
        do
        {
            gotoxy(22, 12);
            printf("Insira sua idade ....... ");
            gotoxy(48, 12);
            scanf("%d", &id);
            if (id < 0)
            {
                limpar(limp);
            }

        } while (id < 0);
        gotoxy(28, 14);
        printf("%s", nome(id));
        gotoxy(43, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    return 0;
}

const char *nome(int idade)
{
    if (idade > 0 && idade < 7)
        return test;
    else if (idade < 10)
        return test2;
    else if (idade < 13)
        return test3;
    else if (idade < 17)
        return test4;
    else
        return test5;
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