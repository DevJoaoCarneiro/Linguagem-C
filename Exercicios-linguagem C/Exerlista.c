/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..PROGRAMA PARA CALCULAR MEDIA DE 3 NUMEROS*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Max 10

float calcmedia(float num[3]);
void gotoxy(int x, int y);
void layout();
void limpar();



// Programa Main
int main()
{
    float numeros[3];
    int reiniciar;
    int i;

    do
    {
        layout();

        for (i = 0; i < 3; i++)
        {
            do
            {
                gotoxy(25, Max - 5);
                printf("                         ");
                gotoxy(20, Max + i);
                printf("Insira o %d numero..................", i + 1);
                gotoxy(55, Max + i);
                scanf("%f", &numeros[i]);
                if (numeros[i] < 0)
                {   
                    gotoxy(55, Max+i);
                    limpar();
                }
            } while (numeros[i] < 0);
        }
        gotoxy(20, Max + 4);
        printf("A media dos numeros e ......... %.2f", calcmedia(numeros));
        gotoxy(43, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
}

// Declaraçoes funçoes
float calcmedia(float num[3])
{
    int i;
    float media = 0;

    for (i = 0; i < 3; i++)
    {
        media = media + num[i];
    }
    return media / 3;
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
    printf("*EXERCICIO 1*");
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
void limpar()
{  
    printf("       ");
    gotoxy(25, Max - 5);
    printf("*INSIRA UM NUMERO VALIDO*");
    getch();
}