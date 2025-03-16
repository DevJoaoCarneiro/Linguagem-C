/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..Joguinho de opçoes*/

#include <stdio.h>
#include <windows.h>
#define Max 5

//DECLARAÇÕES
void quest1();
void quest2();
void quest3();
void quest4();
void quest5();
void lose();

void gotoxy(int x, int y);

void layout();

//PROGRAMA PRINCIPAL
int main()
{
    int i;
    int resposta[Max];
    int usuario = 0;
    int reiniciar;
    int flecha = 0;

    do
    {
        usuario = 0;
        system("color 0f");
        for (i = 0; i < Max; i++)
        {
            system("cls");
            layout();
            switch (i)
            {
            case 0:
                quest1();
                break;

            case 1:
                quest2();
                break;

            case 2:
                quest3();
                break;

            case 3:
                quest4();
                break;

            case 4:
                quest5();
                break;
            }
            gotoxy(32, 21);
            scanf("%d", &resposta[i]);

            switch (i)
            {
            case 0:
                if (resposta[i] != 1)
                {
                    lose();
                    flecha=1;
                    break;
                }
                else
                {
                    usuario++;
                    continue;
                }
            case 1:
                if (resposta[i] != 4)
                {
                    lose();
                    flecha=1;
                    break;
                }
                else
                {
                    usuario++;
                    continue;
                }
            case 2:
                if (resposta[i] != 3)
                {
                    lose();
                    flecha=1;
                    break;
                }
                else
                {
                    usuario++;
                    continue;
                }
            case 3:
                if (resposta[i] != 1)
                {
                    lose();
                    flecha=1;
                    break;
                }
                else
                {
                    usuario++;
                    continue;
                }
            case 4:
                if (resposta[i] != 2)
                {
                    lose();
                    flecha=1;
                    break;
                }
                else
                {
                    usuario++;
                    break;
                }
            }
            if (flecha == 1)
            {
                break;
            }
        }
        if (usuario == 5)
        {
            system("cls");
            system("color 0a");
            layout();
            gotoxy(24, 12);
            printf("=========PARABENS==========");
            gotoxy(24, 14);
            printf("=======VOCE GABARITOU======");
            gotoxy(01, 21);
            printf("Voce deseja reiniciar o programa ?......");
        }

        gotoxy(42, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
}

// Fim do programa

//**ABAIXO ESTA AS DECLARAÇOES DAS FUNÇOES VOID E AS PERGUNTAS**//

// FUNÇOES VOID//

void quest1()
{
    gotoxy(13, 06);
    printf("Qual e o campo harmonico da tonalidade de Do maior?");
    gotoxy(02, 10);
    printf("1) Do, Re, Mi Fa");
    gotoxy(05, 11);
    printf("Sol, La, Si");
    gotoxy(02, 16);
    printf("2) Do, Re, Mi");
    gotoxy(05, 17);
    printf("Fa#, Sol, La, Si");
    gotoxy(52, 10);
    printf("3) Do, Re, Mi");
    gotoxy(55, 11);
    printf("Fa, Sol#, La, Si");
    gotoxy(52, 16);
    printf("4) Do, Re, Mi bemol");
    gotoxy(55, 17);
    printf("Fa, Sol, La, Si bemol");
}

void quest2()
{
    gotoxy(13, 06);
    printf("Qual nota esta uma quarta justa acima de Re?");
    gotoxy(02, 10);
    printf("1) Mi");
    gotoxy(02, 16);
    printf("2) Fa#");
    gotoxy(52, 10);
    printf("3) Sol");
    gotoxy(52, 16);
    printf("4) La");
}

void quest3()
{
    gotoxy(05, 06);
    printf("Na partitura, qual simbolo indica um aumento na duracao da nota?");
    gotoxy(02, 10);
    printf("1) Pontuacao");
    gotoxy(02, 16);
    printf("2) Ligadura");
    gotoxy(52, 10);
    printf("3) Fermata");
    gotoxy(52, 16);
    printf("4) Sustenido");
}

void quest4()
{
    gotoxy(15, 06);
    printf("Qual acorde e formado pelas notas Do, Mi e Sol?");
    gotoxy(02, 10);
    printf("1) Acorde maior");
    gotoxy(02, 16);
    printf("2) Acorde menor");
    gotoxy(52, 10);
    printf("3) Acorde diminuto");
    gotoxy(52, 16);
    printf("4) Acorde aumentado");
}

void quest5()
{
    gotoxy(13, 06);
    printf("Qual e a armadura de clave para a tonalidade de Fa maior?");
    gotoxy(02, 10);
    printf("1) Nenhuma alteracao");
    gotoxy(02, 16);
    printf("2) Um bemol (Si bemol)");
    gotoxy(47, 10);
    printf("3) Dois bemois (Si e Mi bemois)");
    gotoxy(47, 16);
    printf("4) Um sustenido (Fa sustenido)");
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
    gotoxy(32, 02);
    printf("MUSIC GAME");
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
    printf("Insira aqui sua resposta .....");
}

void lose()
{
    system("cls");
    layout();
    system("color 0c");
    gotoxy(32, 12);
    printf("VOCE PERDEU!!");
    gotoxy(01, 21);
    printf("Voce deseja reiniciar o programa ?......");
    gotoxy(01, 24);

}