/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..Segundos para minutos e horas*/

#include <stdio.h>
#include <windows.h>
#define Cord 8

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    int seg;
    int min;
    int hora = 0;
    int i;
    int reiniciar;

    //layout
    do{
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

    gotoxy(01, 24);
    //layout

    gotoxy (20,Cord);
    printf("Digite o tempo em segundos........");
    scanf("%d", &seg);

        min = seg / 60;
        hora= min/60;

    gotoxy (20,Cord+2);
    printf("Seu tempo em segundos ........ %d \n", seg);
    gotoxy (20,Cord+4);
    printf("Seu tempo em minutos ......... %d \n", min);
    gotoxy (20,Cord+6);
    printf("Seu tempo em horas ........... %d \n", hora);

    if (seg>=60){
        do{
            seg=seg-60;

        }while(seg>=60);
    }

    if (min>=60){
        do{
            min=min-60;

        }while(min>=60);
    }

    gotoxy (20,Cord+8);
    printf("%d Hora %d Minutos %d Segundos", hora, min, seg);

    gotoxy(40, 21);
    scanf("%d", &reiniciar);

    gotoxy(01, 24);
    }while (reiniciar==1);
    return 0;
}