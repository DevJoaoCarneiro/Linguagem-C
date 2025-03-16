/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..FATORIAL DE UM NUMERO INTEIRO*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>

int calculafatorial(int num);
void gotoxy(int x, int y);
void layout();

int main()
{
    int num_user;
    int reinciar;

    do
    {
        layout();
        do
        {
            gotoxy(25, 5);
            printf("                         ");
            gotoxy(25, 10);
            printf("Insira um numero............");
            gotoxy(53, 10);
            scanf("%d", &num_user);
            if (num_user <= 0)
            {
                gotoxy(53, 10);
                printf("       ");
                gotoxy(25, 5);
                printf("*INSIRA UM NUMERO VALIDO*");
                getch();
            }
        } while (num_user <= 0);
        gotoxy(25, 12);
        printf("O fatorial de %d e ........ %d", num_user, calculafatorial(num_user));
        gotoxy(43, 21);
        scanf("%d", &reinciar);
    } while (reinciar == 1);
    gotoxy(01, 24);
    return 0;
}

// Declaraçoes funçoes//

int calculafatorial(int num)
{
    int i;
    int calc = num;
    int j = num - 1;

    for (i = 0; i < num; i++)
    {

        if (j > 0)
        {
            calc = calc * j;

            j--;
        }
    }
    return calc;
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
    printf("*EXERCICIO 3*");
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