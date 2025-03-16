/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..INVERTER UMA STRING*/

#include <stdio.h>
#include <windows.h>
#define Max 10
#define coluna 18
void layout();
void gotoxy(int x, int y);
void invertestring(char nome[], int n);

//==========FUNÇÃO PRINCIPAL=============//
int main()
{
    char nome[50];
    int n;
    int reiniciar;

    do
    {
        layout();
        gotoxy(coluna, Max);
        printf("Insira um nome ..............");
        fflush(stdin);
        fgets(nome, 50, stdin);

        n = strlen(nome);
        gotoxy(coluna, Max + 2);
        printf("***O tamanho do texto digitado foi %d *** \n", n);

        invertestring(nome, n);

        gotoxy(43, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);

    return 0;
}

//===========DECLARAÇÃO DE FUNÇÃO===========//
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
    printf("*EXERCICIO 5*");
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

void invertestring(char nome[], int n)
{
    int i;
    int j = n - 1;

    gotoxy(coluna, Max + 4);
    printf("A string invertida e ........");
    for (i = 0; i < n; i++)
    {
        gotoxy(47 + i, Max + 4);
        printf("%c", nome[j]);
        j--;
    }
}