/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..MAIOR NUMERO DENTRO DO VETOR*/

#include <stdio.h>
#include <windows.h>
#define Max 8

void gotoxy(int x, int y);
void layout();
int EncontraMax(int x[], int n);

int main()
{
    int numvet[5];
    int i;
    int reiniciar;

    do
    {
        layout();
        for (i = 0; i < 5; i++)
        {
            gotoxy(24, Max + i);
            printf("Insira o %d numero ....... ", i + 1);
            scanf("%d", &numvet[i]);
        }

        gotoxy(24, 14);
        printf("O maior vetor e ......... %d", EncontraMax(numvet, 5));
        gotoxy(43, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
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
    printf("*EXERCICIO 4*");
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

int EncontraMax(int x[], int n)
{
    int i;
    int maior = 0;


    for (i = 0; i < n; i++)
    {
        if (x[i] > maior)
        {
            maior = x[i];
        }
    }
    return maior;
}