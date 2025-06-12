/*Autor.....Joao Victor
  Data......09/05/25
  Objetivo..Sistema pedidos com fila*/
  
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  typedef struct{
    int id_Pedido;
    int quantidade;
    char nome_Usuario[50];
    char descricao[50];
    float valorProduto;
    
  }reg_Pedido;
  
  typedef struct tipoItem *Ponteiro;
  
  typedef struct tipoItem{
    reg_Pedido conteudo;
    Ponteiro proximo;
  }tipoItem;
  
  typedef struct{
    Ponteiro primeiro;
    Ponteiro ultimo;
    int tamanho;
  }fila;
  
  void inicializaFila(fila *L){
    L->primeiro = NULL;
    L->ultimo = NULL;
    L->tamanho = 0;
  }
  
  void lancaPedido(fila *L){
    reg_Pedido pedido;
    int resp;
    int opcao;
    
    do{
    //Fila esta vazia
    if(L->primeiro ==NULL){
      pedido.id_Pedido = 1;
    }else{
    //Tem gente na lista
      pedido.id_Pedido = L->ultimo->conteudo.id_Pedido+1;
    }
    
    printf("O seu Id pedido......:%d\n", pedido.id_Pedido);
    printf("Digite seu nome......:");
    fflush(stdin);
    fgets(pedido.nome_Usuario, 50, stdin);
    pedido.nome_Usuario[strcspn(pedido.nome_Usuario, "\n")] = '\0';
    
    printf("Digite a descricao...:");
    fflush(stdin);
    fgets(pedido.descricao, 50, stdin);
    pedido.descricao[strcspn(pedido.descricao, "\n")] = '\0';
    
    printf("Digite o valor.......:");
    scanf("%f", &pedido.valorProduto);

    
    printf("Digite a quantidade..:");
    scanf("%d", &pedido.quantidade);
    
    printf("Deseja confirmar o pedido (1-Sim 2-Nao)..:");
    scanf("%d", &resp);
    getchar();
    
    if(resp==1){
      Ponteiro p=(Ponteiro)malloc(sizeof(tipoItem));
      p->conteudo = pedido;
      
      if(L->primeiro == NULL){
        L->primeiro = p;
        L->ultimo= p;
        p->proximo = L->primeiro;
      }else{
        L->ultimo->proximo = p;
        L->ultimo = p;
        p->proximo = L->primeiro;
        
      }
      L->tamanho++;
      printf("Pedido enviado!!\n");
      
    }else{
      printf("Pedido nao enviado!!\n");
      
    }
    
    printf("Deseja cadastrar mais um pedido (1-Sim 2-Nao)...");
    scanf("%d", &opcao);
    getchar();
    }while(opcao==1);
  }
  
  
  void consultaFila(fila *L){
    Ponteiro p = L->primeiro;
    
    if(L->primeiro ==NULL){
      printf("**A fila esta vazia**\n");
      return;
    }
    
    do{
      printf("ID Pedido..%d\n", p->conteudo.id_Pedido);
      printf("Nome...........%s\n", p->conteudo.nome_Usuario);
      printf("Descricao......%s\n", p->conteudo.descricao);
      printf("Valor produto..%.2f\n", p->conteudo.valorProduto);
      printf("Quantidade.....%d\n", p->conteudo.quantidade);
      p = p->proximo;
    }while(p != L->primeiro);
    
  
  }
  
  void finalizaPedido(fila *L){
    Ponteiro p=L->primeiro;
    int resp;
    
    if(L->primeiro ==NULL){
      printf("**A fila esta vazia**\n");
      return;
    }
    
    
    printf("Deseja finalizar o %d pedido (1-Sim 2-Nao)..",p->conteudo.id_Pedido);
    scanf("%d", &resp);
    
    if(resp ==1){
      if(L->primeiro == L->ultimo){
        //So tem um cadastrado
        L->primeiro=NULL;
        L->ultimo=NULL;
        free(p);
      }else{
        
      L->primeiro = p->proximo;
      L->ultimo->proximo = p->proximo;
      free(p);
      }
      printf("Excluido com sucesso!!\n");
    }else{
      printf("Nenhum pedido foi excluido!!\n");
    }
  }
  
  
  int main(){
    int resp;
    int reiniciar;
    fila L;
    inicializaFila(&L);
    
    do{
    printf("*Menu de opcoes*\n");
    printf("1)Cadastrar pedido\n");
    printf("2)Consulta pedidos\n");
    printf("3)Finaliza pedido\n");
    printf("4)Sair\n");
    printf("Digite sua resposta..");
    scanf("%d", &resp);
    getchar();
    
    switch(resp){
      case 1:
        lancaPedido(&L);
        break;
      case 2:
        consultaFila(&L);
        break;
      case 3:
        finalizaPedido(&L);
        break;
      case 4:
        printf("Obrigado por usar o sistema!\n");
        exit(1);
      default:
        printf("Numero inserido invalido!\n");
    }
    
    printf("Voltar ao menu ?(1-Sim 2-Nao)...");
    scanf("%d", &reiniciar);
    getchar();
    }while(reiniciar==1);
    
    
    
  }