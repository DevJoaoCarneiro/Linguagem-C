/*Autor.....João Victor Simeão Carneiro
  Data......24/10/2024
  Objetivo..INVERTE MATRIZ*/

#include <stdio.h>
#include <windows.h>
#define Max 10

void trocarmatriz(int matriz[Max][Max])
{
  int troca;
  int j;
  int i;
  //TROCA DE LINHA 2 PELA LINHA 8
  for (j = 0; j < 10; j++)
  {
    troca = matriz[1][j];
    matriz[1][j] = matriz[7][j];
    matriz[7][j] = troca;
  }

  //TROCA DE COLUNAS 4 PARA 10
  for (i = 0; i < 10; i++)
  {
    troca = matriz[i][3];
    matriz[i][3] = matriz[i][9];
    matriz[i][9] = troca;
  }

  //TROCA DE DIAGONAIS
  for (i = 0; i < 10; i++)
  {
    troca = matriz[i][i];
    matriz[i][i] = matriz[Max - 1][i];
    matriz[i][Max - 1] = troca;
  }

  //TROCA LINHA DE COLUNA
  for (i = 0; i < 10; i++)
  {
    troca = matriz[i][4];
    matriz[i][4] = matriz[i][9];
    matriz[i][9] = troca;
  }
}

int main()
{
  int matriz[Max][Max];
  int i;
  int j;
  int num = 01;

  //Preencher a matriz
  for (i = 0; i < Max; i++)
  {
    for (j = 0; j < Max; j++)
    {
      matriz[i][j] = num;
      num++;
    }
  }

  //Mostrar matriz original

  for (i = 0; i < Max; i++)
  {
    for (j = 0; j < Max; j++)
    { 
      printf("[%d]", matriz[i][j]);
    }
    printf("\n");
  }

  trocarmatriz(matriz);

  printf("\n");
  printf("======================================= \n");
  //Inverte Matriz
  for (i = 0; i < Max; i++)
  {

    for (j = 0; j < Max; j++)
    {
      printf("[%d]", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}