/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..Valor da multa*/

#include <stdio.h>
#include <windows.h>
#define Max 10

void gotoxy(int x, int y);

void layout();

int main()
{
    int velocMax;
    int velocMotorista;
    int multa = 0;
    int reiniciar;

    do{
    system ("color 0c");
    layout();
    
    gotoxy(20, Max);
    printf("Insira a velocidade da via ..........");
    scanf("%d", &velocMax);
    gotoxy(20, Max + 2);
    printf("Insira a velocidade do motorista ....");
    scanf("%d", &velocMotorista);

    if (velocMotorista > velocMax)
    {
        do
        {
            multa++;
            velocMotorista--;
        } while (velocMotorista > velocMax);

        gotoxy(20, Max + 4);
        printf("A multa a ser paga e ................%d", multa * 5);
    }
    else
    {
        gotoxy(20, Max + 4);
        printf("=====O motorista nao tomou multa=====");
    }
    gotoxy (40,21);
    scanf("%d", &reiniciar);
    }while (reiniciar==1);
    gotoxy (01, 23);
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
    printf("LAYOUT PROGRAMA");
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
    printf("REINICIAR PROGRAMA? (1-SIM 2-NAO).....");
}