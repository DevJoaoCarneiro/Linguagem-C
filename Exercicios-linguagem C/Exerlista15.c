/*Autor..... João Victor
  Data...... 30/11/24
  Objetivo.. 7. Construir um programa em "C" que implementa uma agenda eletrônica. O
                programa deve ter um menu com as seguintes opções:
                1- Entrar um nome na agenda
                2- Imprimir na tela os dados de uma das pessoas cadastradas (consulta por
                nome)
                3- Imprimir na impressora a lista dos nomes que começam pela letra indicada*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Max 50

typedef struct agenda
{
    char nome[Max];
    int numero;
    char descricao[Max];
} RegAgenda;

int cadastro_usuario (RegAgenda* usuario, int *ponteiro){
    int i;
    int confirma;
    int repet;
    int back_menu;

    for(i=0;i<Max;i++){
        *ponteiro=*ponteiro+1;
        do{
        printf("==Cadastro usuario==\n");
        printf("Nome........");
        fflush(stdin);
        fgets(usuario[i].nome, Max, stdin);

        printf("Numero......");
        scanf("%d", &usuario[i].numero);

        printf("Descricao...");
        fflush(stdin);
        fgets(usuario[i].descricao, Max, stdin);

        printf("Confirmar cadastro (1-Sim 2-Nao)?........");
        scanf("%d", &confirma);
        }while(confirma==2);

        printf("Cadastrar outro usuario (1-Sim 2-Nao)?...");
        scanf("%d", &repet);
        if(repet==1){
            continue;
        }else{
            break;
        }
        
    }
    printf("Deseja voltar ao menu (1-Sim 2-Nao)?.....");
    scanf("%d", &back_menu);

    return back_menu;

}

int consultar_cadastro (RegAgenda* usuario, int *ponteiro){
    int i;
    int back_menu;
    
    for(i=0;i<*ponteiro;i++){
        printf("Nome........ %s",usuario[i].nome);
        printf("Numero...... %d\n",usuario[i].numero);
        printf("Descricao... %s",usuario[i].descricao);

    }
    printf("Deseja voltar ao menu (1-Sim 2-Nao)?.....");
    scanf("%d", &back_menu);

    return back_menu;
}

int telainic()
{
    int menu;
    printf("Agenda Eletronica \n");
    printf("Cadastrar usuario na agenda \n");
    printf("Consultar Cadastro \n");
    printf("Escolha sua opcao.....");
    scanf("%d", &menu);

    return menu;
}

int main()
{   int menu_opcao;
    int *ponteiro;
    int contagem=0;
    int back_menu;

    ponteiro=&contagem;

    RegAgenda agenda[Max];

    do{
    system("cls");
    menu_opcao=telainic();

    switch (menu_opcao){
        case 1:
        back_menu=cadastro_usuario(agenda, ponteiro);
        break;

        case 2:
        if(*ponteiro<=0){
            printf("Nao tem usuario cadastrado\n");
            printf("Voltar ao menu (1-Sim 2-Nao).....");
            scanf("%d", &back_menu);
        }
        consultar_cadastro(agenda, ponteiro);
        break;
    }
    }while(back_menu==1);
    return 0;
}