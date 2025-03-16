/*Autor.... Joao Victor
  Data..... 18/11/24
  Objetivo. Exec sala*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define Max 30
#define tam 5

// Estrutura de variaveis do usuario
typedef struct
{
    char nome[Max];
    char sobrenome[Max];
    char endereco[Max];
    int num_endereco;
    float cpf;
} reg_cadastro;

// Função para manipular coordenadas

void gotoxy(int x, int y)

{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Funcao para limpar tela
void limpar()
{
    int i;
    for (i = 0; i < 15; i++)
    {
        gotoxy(1, 05 + i);
        printf("                                                                          ");
    }
}
// Funcao para cadastrar usuario
int cadastro_usu(reg_cadastro *usuarios, int *num)
{
    int i;
    int confirma;
    int reinicio;
    int menu;

    for (i = *num; i < tam; i++)
    {
        *num = *num + 1;
        do
        {
            limpar();

            gotoxy(20, 8);
            printf("Insira seu nome ...........");
            gotoxy(20, 10);
            printf("Insira seu sobrenome ......");
            gotoxy(20, 12);
            printf("Insira seu endereco .......");
            gotoxy(20, 14);
            printf("Insira o numero ...........");
            gotoxy(20, 16);
            printf("Insira o cpf  .............");

            gotoxy(48, 8);
            fflush(stdin);
            fgets(usuarios[i].nome, Max, stdin);

            gotoxy(48, 10);
            fflush(stdin);
            fgets(usuarios[i].sobrenome, Max, stdin);

            gotoxy(48, 12);
            fflush(stdin);
            fgets(usuarios[i].endereco, Max, stdin);

            gotoxy(48, 14);
            scanf("%d", &usuarios[i].num_endereco);

            gotoxy(48, 16);
            scanf("%f", &usuarios[i].cpf);

            gotoxy(01, 21);
            printf("                                                      ");
            gotoxy(01, 21);
            printf("Confirmar cadastro (1-Sim 2-Nao)............");
            gotoxy(46, 21);
            scanf("%d", &confirma);
            gotoxy(01, 21);
            printf("                                                      ");

            if (confirma != 1)
            {
                limpar();
                gotoxy(20, 12);
                printf("***** O Usuario nao foi cadastrado*****\n");
                gotoxy(20, 14);
                printf("===PRESSIONE UMA TECLA PARA CONTINUAR===\n");
                getch();
                limpar();
            }
        } while (confirma != 1);

        gotoxy(01, 21);
        printf("                                                      ");
        gotoxy(01, 21);
        printf("Cadastrar outro usuario? (1-Sim 2-Nao) .....");
        gotoxy(46, 21);
        scanf("%d", &reinicio);
        gotoxy(01, 21);
        printf("                                                      ");

        if (reinicio == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    gotoxy(01, 21);
    printf("                                                      ");
    gotoxy(01, 21);
    printf("Voltar ao menu ? (1-Sim 2-Nao)....");
    gotoxy(36, 21);
    scanf("%d", &menu);

    return menu;
}

// Função para editar usuario cadastrado
int editar_usuarios(reg_cadastro *usuarios, int *num2)
{
    int i;
    int menu;
    int edit;
    int edituser;
    int att;

    for (i = 0; i < *num2; i++)
    {
        gotoxy(01, 05 + i);
        printf("%d - %s", i + 1, usuarios[i].nome);
    }
    gotoxy(01, 21);
    printf("Qual usario voce deseja editar.....");
    gotoxy(38, 21);
    scanf("%d", &edit);

    if(edit<=*num2 && edit>0){
    limpar();
    gotoxy(25, 9);
    printf("==== USUARIO %d ====", edit);
    gotoxy(25, 11);
    printf("1-Nome .......... %s", usuarios[edit - 1].nome);
    gotoxy(25, 12);
    printf("2-Sobrenome ..... %s", usuarios[edit - 1].sobrenome);
    gotoxy(25, 13);
    printf("3-Endereco ...... %s", usuarios[edit - 1].endereco);
    gotoxy(25, 14);
    printf("4-Cpf ........... %.2f", usuarios[edit - 1].cpf);
    

    gotoxy(01, 21);
    printf("                                                      ");
    gotoxy(01, 21);
    printf("Qual dado voce quer editar? .......");
    gotoxy(38, 21);
    scanf("%d", &edituser);

    switch (edituser)
    {
    case 1:
        do
        {
            limpar();
            gotoxy(25, 11);
            printf("1-Nome ..................... ");
            fflush(stdin);
            gotoxy(55, 11);
            fgets(usuarios[edit - 1].nome, Max, stdin);
            gotoxy(01, 21);
            printf("                                                      ");
            gotoxy(01, 21);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            gotoxy(35, 21);
            scanf("%d", &att);
        } while (att != 1);

        break;
    case 2:
        do
        {
            limpar();
            gotoxy(25, 11);
            printf("2-Sobrenome ................ ");
            fflush(stdin);
            gotoxy(55, 11);
            fgets(usuarios[edit - 1].sobrenome, Max, stdin);
            gotoxy(01, 21);
            printf("                                                      ");
            gotoxy(01, 21);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            gotoxy(35, 21);
            scanf("%d", &att);
        } while (att != 1);

        break;
    case 3:
        do
        {
            limpar();
            gotoxy(25, 11);
            printf("3-Endereco ................. ");
            fflush(stdin);
            gotoxy(55, 11);
            fgets(usuarios[edit - 1].endereco, Max, stdin);
            gotoxy(01, 21);
            printf("                                                      ");
            gotoxy(01, 21);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            gotoxy(35, 21);
            scanf("%d", &att);
        } while (att != 1);

        break;
    case 4:
        do
        {
            limpar();
            gotoxy(25, 11);
            printf("4-Numero endereco .......... ");
            gotoxy(55, 11);
            scanf("%d", &usuarios[edit - 1].num_endereco);
            gotoxy(01, 21);
            printf("                                                      ");
            gotoxy(01, 21);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            gotoxy(35, 21);
            scanf("%d", &att);
        } while (att != 1);

        break;
    case 5:
        do
        {
            limpar();
            gotoxy(25, 11);
            printf("5-Cpf ..................... ");
            gotoxy(55, 11);
            scanf("%f", &usuarios[edit - 1].cpf);
            gotoxy(01, 21);
            printf("                                                      ");
            gotoxy(01, 21);
            printf("Atualizar dado? (1-Sim 2-Nao)... ");
            gotoxy(35, 21);
            scanf("%d", &att);
        } while (att != 1);

        break;
    default:
        gotoxy(20, 19);
        printf("**Insira um numero valido**\n");
        getch();
        gotoxy(20, 19);
        printf("                                              ");
    }

    limpar();

    gotoxy(25, 6);
    printf("*USUARIO ATUALIZADO*");
    gotoxy(25, 9);
    printf("==== USUARIO %d ====\n", edit);
    gotoxy(20, 11);
    printf("Nome .......... %s\n", usuarios[edit - 1].nome);
    gotoxy(20, 12);
    printf("Sobrenome ..... %s\n", usuarios[edit - 1].sobrenome);
    gotoxy(20, 13);
    printf("Endereco ...... %s", usuarios[edit - 1].endereco);
    gotoxy(20, 14);
    printf("Cpf ........... %.2f\n", usuarios[edit - 1].cpf);
    }else{
        gotoxy(24,19);
        printf("*USUARIO NAO CADASTRADO*");
    }
    gotoxy(01, 21);
    printf("                                                      ");
    gotoxy(01, 21);
    printf("Voltar ao menu ? (1-Sim 2-Nao)....");
    gotoxy(36, 21);
    scanf("%d", &menu);
    return menu;
}

// Funcao que le usarios cadastrados
int ler_usuarios(reg_cadastro *usuarios, int *num2)
{
    int i;
    int menu;
    int consultar;
    int user;

    for (i = 0; i < *num2; i++)
    {
        gotoxy(01, 05 + i);
        printf("%d - %s", i + 1, usuarios[i].nome);
    }
    gotoxy(01, 21);
    printf("Quer consultar algum cadastro (1-Sim 2-Nao).....");
    gotoxy(50, 21);
    scanf("%d", &consultar);
    gotoxy(01, 21);
    printf("                                                    ");
    if (consultar == 1)
    {
        do
        {
            gotoxy(01, 21);
            printf("Qual usuario voce deseja consultar ? ....");
            gotoxy(43, 21);
            scanf("%d", &user);
            gotoxy(01, 21);
            printf("                                              ");
            if (user - 1 > *num2)
            {
                gotoxy(20, 19);
                printf("*Insira um numero de usuario ja cadastrado*");
                getch();
                gotoxy(20, 19);
                printf("                                              ");
            }
        } while (user - 1 > *num2);
        gotoxy(01, 21);
        printf("                                                    ");

        limpar();
        gotoxy(25, 9);
        printf("===== Usuario %d =====", user);
        gotoxy(25, 11);
        printf("Nome........ %s", usuarios[user - 1].nome);
        gotoxy(25, 12);
        printf("Sobrenome... %s", usuarios[user - 1].sobrenome);
        gotoxy(25, 13);
        printf("Endereco.... %s", usuarios[user - 1].endereco);
        gotoxy(25, 14);
        printf("Numero...... %d", usuarios[user - 1].num_endereco);
        gotoxy(25, 15);
        printf("Cpf......... %.2f", usuarios[user - 1].cpf);
    }

    gotoxy(01, 21);
    printf("Voltar ao menu ? (1-Sim 2-Nao)....");
    gotoxy(36, 21);
    scanf("%d", &menu);
    return menu;
}

// Funcao com menu principal
int layout()
{
    int escolha;

    gotoxy(25, 06);
    printf("=== MENU DE OPCAO ===\n");
    gotoxy(25, 10);
    printf("1- Cadastrar usuario\n");
    gotoxy(25, 11);
    printf("2- Consultar usuarios\n");
    gotoxy(25, 12);
    printf("3- Editar cadastro usario\n");
    gotoxy(25, 13);
    printf("4- Sair\n");
    gotoxy(01, 21);
    printf("Insira sua resposta .....");
    gotoxy(27, 21);
    scanf("%d", &escolha);
    system("cls");
    switch (escolha)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    default:
        return 5;
    }
}

// Tela Padrao
void tela()

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
    printf("*TELA CADASTRO*");
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
}

int main()
{
    int resposta;
    int cadastro;
    int *ponteiro;
    int contagem = 0;

    ponteiro = &contagem;
    reg_cadastro usuarios[tam];

    do
    {   system("color 1f");
        tela();
        resposta = layout();

        switch (resposta)
        {
        case 1:
            tela();
            cadastro = cadastro_usu(usuarios, ponteiro);
            limpar();
            break;
        case 2:
            if (contagem != 0)
            {
                tela();
                cadastro = ler_usuarios(usuarios, ponteiro);
                limpar();
                break;
            }
            else
            {
                tela();
                gotoxy(24, 12);
                printf("*NENHUM USUARIO CADASTRADO*");
                gotoxy(01, 21);

                printf("Voltar ao menu ? (1-Sim 2-Nao)....");
                gotoxy(36, 21);
                scanf("%d", &cadastro);
                break;
            }
        case 3:
            if (contagem != 0)
            {
                tela();
                cadastro = editar_usuarios(usuarios, ponteiro);
                limpar();
                break;
            }
            else
            {
                tela();
                gotoxy(24, 12);
                printf("*NENHUM USUARIO CADASTRADO*");
                gotoxy(01, 21);

                printf("Voltar ao menu ? (1-Sim 2-Nao)....");
                gotoxy(36, 21);
                scanf("%d", &cadastro);
                break;
            }
        default:
            tela();
            gotoxy(24, 12);
            printf("OBRIGADO POR USAR O APLICATIVO");
            cadastro=2;
            break;
            
        }

    } while (cadastro == 1);
    gotoxy(01, 26);
    return 0;
}