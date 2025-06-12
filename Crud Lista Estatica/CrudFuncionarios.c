/*Autor.....Joao Victor
  Data......13/03/25
  Objetivo..Crud Funcionarios*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define valor 50
#define Max 12

void gotoxy(int x, int y)

{
  COORD coord;
  coord.X = (short)x;
  coord.Y = (short)y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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

void limpar()
{
  int i;
  for (i = 0; i < 15; i++)
  {
    gotoxy(1, 05 + i);
    printf("                                                                          ");
  }
  gotoxy(01, 21);
  printf("                                                                          ");
  gotoxy(01, 22);
  printf("                                                                          ");
}

void telaFuncionario()
{
  gotoxy(23, 6);
  printf("**CADASTRO FUNCIONARIO**");
  gotoxy(25, 8);
  printf("Insira o nome.....:");
  gotoxy(25, 9);
  printf("Insira o endereco.:");
  gotoxy(25, 10);
  printf("Insira o codigo...:");
  gotoxy(25, 11);
  printf("Insira o salario..:");
}

typedef struct
{
  char nome[valor];
  char endereco[valor];
  int codigo;
  float salario;
} reg_funcionario;

typedef struct
{
  reg_funcionario func[Max];
  int inicio;
  int final;
} Lista;

// Inicializar lista
void inicializaLista(Lista *L)
{
  L->inicio = 0;
  L->final = 0;
  for (int i = 0; i < Max; i++)
  {
    L->func[i].nome[0] = '\0';
    L->func[i].endereco[0] = '\0';
    L->func[i].salario = 0;
    L->func[i].codigo = 0;
  }
}

void salvarUsuario(Lista *L)
{
  FILE *file = fopen("funcionarios.txt", "w");
  if (file == NULL)
  {
    gotoxy(20, 19);
    printf("Erro ao abrir o arquivo para escrita");
    return;
  }

  for (int i = 0; i < L->final; i++)
  {
    fprintf(file, "%d\n%s\n%s\n%.2f\n",
            L->func[i].codigo,
            L->func[i].nome,
            L->func[i].endereco,
            L->func[i].salario);
  }

  fclose(file);
}

void carregarFuncionario(Lista *L)
{
  FILE *file = fopen("funcionarios.txt", "r");
  if (file == NULL)
  {
    gotoxy(20, 19);
    printf("Nenhum dado encontrado");
    return;
  }

  while (fscanf(file, "%d\n%49[^\n]\n%49[^\n]\n%f\n",
                &L->func[L->final].codigo,
                L->func[L->final].nome,
                L->func[L->final].endereco,
                &L->func[L->final].salario) == 4)
  {
    L->final++;
    if (L->final >= Max)
    {
      break;
    }
  }
  fclose(file);
}

int validarCodigo(Lista *L, int codigo)
{
  for (int i = 0; i < L->final; i++)
  {
    if (L->func[i].codigo == codigo)
    {
      return -1;
    }
  }
  return 1;
}

void cadastrarFuncionario(Lista *L)
{
  reg_funcionario funcionario;
  int reiniciar, confirma, validar;

  do
  {
    limpar();
    telaFuncionario();
    if (L->final >= Max)
    {
      gotoxy(25, 12);
      printf("**A LISTA ESTA CHEIA**");
      break;
    }

    gotoxy(20, 19);
    printf("Para nao cadastrar digite sair");
    // Nome
    gotoxy(45, 8);
    fflush(stdin);
    fgets(funcionario.nome, valor, stdin);

    if (strcmp(funcionario.nome, "sair\n") == 0)
    {
      return;
    }

    // endereco
    gotoxy(45, 9);
    fflush(stdin);
    fgets(funcionario.endereco, valor, stdin);

    if (strcmp(funcionario.endereco, "sair\n") == 0)
    {
      return;
    }
    /*Validar codigo se ja existe*/
    do
    {
      // codigo
      do
      {
        gotoxy(45, 10);
        printf("                    ");
        gotoxy(45, 10);
        scanf("%d", &funcionario.codigo);
        if (funcionario.codigo <= 0)
        {
          gotoxy(20, 19);
          printf("                                         ");
          gotoxy(20, 18);
          printf("Nao e possivel cadastrar codigo menor que 0");
          gotoxy(23, 19);
          printf("*Precione uma tecla para continuar*");

          getch();
          gotoxy(18, 18);
          printf("                                                          ");
          gotoxy(18, 19);
          printf("                                                          ");
        }
      } while (funcionario.codigo <= 0);

      validar = validarCodigo(L, funcionario.codigo);

      if (validar != 1)
      {
        gotoxy(25, 19);
        printf("Erro: Codigo ja foi cadastrado\n");
      }

    } while (validar != 1);

    do
    {
      // salario
      gotoxy(45, 11);
      scanf("%f", &funcionario.salario);
      if (funcionario.salario < 0)
      {
        gotoxy(45, 11);
        printf("                               ");
        gotoxy(25, 19);
        printf("Salario inserido e invalido \n");
      }
    } while (funcionario.salario < 0);

    gotoxy(01, 21);
    printf("Confirmar cadastro (1-Sim 2-Nao)..............        ");
    gotoxy(48, 21);
    scanf("%d", &confirma);

    if (confirma == 1)
    {
      L->func[L->final] = funcionario;
      L->final++;
      salvarUsuario(L);
    }

    gotoxy(01, 21);
    printf("Cadastrar outro funcionario (1-Sim 2-Nao).....       ");
    gotoxy(48, 21);
    scanf("%d", &reiniciar);
  } while (reiniciar == 1);
}

void consultarCadastro(Lista *L)
{
  int consulta;
  int resp;

  limpar();
  if (L->final == L->inicio)
  {
    gotoxy(20, 12);
    printf("*NAO TEM FUNCIONARIOS CADASTRADOS*");
  }
  else
  {
    gotoxy(22, 06);
    printf("*LISTA DE USUARIOS CADASTRADOS*");
    for (int i = 0; i < L->final; i++)
    {
      gotoxy(02, 8 + i);
      printf("%d)Nome.....%s", i + 1, L->func[i].nome);
    }
    gotoxy(01, 21);
    printf("Deseja consultar alguma cadastro? (1-Sim 2-Nao).......            ");
    gotoxy(57, 21);
    scanf("%d", &consulta);
  }

  if (consulta == 1)
  {
    gotoxy(01, 21);
    printf("Digite o numero do usuario que deseja consultar........            ");
    gotoxy(57, 21);
    scanf("%d", &resp);

    limpar();
    gotoxy(30, 06);
    printf("USUARIO CONSULTADO");
    gotoxy(27, 10);
    printf("Nome.....:%s", L->func[resp - 1].nome);
    gotoxy(27, 12);
    printf("Endereco.:%s", L->func[resp - 1].endereco);
    gotoxy(27, 14);
    printf("Salario..:%.2f", L->func[resp - 1].salario);
    gotoxy(27, 16);
    printf("Codigo...:%d", L->func[resp - 1].codigo);
  }
}

void editarCadastro(Lista *L)

{
  int num, resp, control, flecha;
  float flechafloat;
  char nome[valor];

  limpar();
  if (L->inicio == L->final)
  {
    gotoxy(22, 12);
    printf("*NAO TEM FUNCIONARIOS CADASTRADOS*");
    return;
  }
  for (int i = 0; i < L->final; i++)
  {
    gotoxy(02, 8 + i);
    printf("%d)Nome.....%s", i + 1, L->func[i].nome);
  }
  gotoxy(01, 21);
  printf("Deseja editar algum usuario? (1-Sim 2-Nao).....");
  gotoxy(49, 21);
  scanf("%d", &num);

  if (num == 1)
  {
    do
    {
      gotoxy(01, 21);
      printf("Qual usuario voce deseja editar.....              ");
      gotoxy(38, 21);
      scanf("%d", &resp);
      if (resp > L->final || resp < L->inicio)
      {
        gotoxy(20, 19);
        printf("Consulte um usuario valido ou 0 para sair");
      }
      else if (resp == 0)
      {
        return;
      }
    } while (resp > L->final || resp < L->inicio);
    limpar();
    gotoxy(30, 06);
    printf("USUARIO CONSULTADO");
    gotoxy(27, 10);
    printf("Nome.....:%s", L->func[resp - 1].nome);
    gotoxy(27, 12);
    printf("Endereco.:%s", L->func[resp - 1].endereco);
    gotoxy(27, 14);
    printf("Salario..:%.2f", L->func[resp - 1].salario);
    gotoxy(27, 16);
    printf("Codigo...:%d", L->func[resp - 1].codigo);

    gotoxy(01, 21);
    printf("Qual campo deseja editar?.....                     ");
    gotoxy(32, 21);
    scanf("%d", &control);
    switch (control)
    {
    case 1:
      limpar();
      gotoxy(25, 12);
      printf("Nome atual.....:%s", L->func[resp - 1].nome);
      gotoxy(25, 14);
      printf("Novo nome......:");
      gotoxy(42, 14);
      fflush(stdin);
      fgets(nome, 50, stdin);

      strcpy(L->func[resp - 1].nome, nome);
      salvarUsuario(L);
      break;
    case 2:
      limpar();
      gotoxy(25, 12);
      printf("Endereco atual.....:%s", L->func[resp - 1].endereco);
      gotoxy(25, 14);
      printf("Novo endereco......:");
      gotoxy(46, 14);
      fflush(stdin);
      fgets(nome, 50, stdin);

      strcpy(L->func[resp - 1].endereco, nome);
      salvarUsuario(L);
      break;
    case 3:
      limpar();
      gotoxy(25, 12);
      printf("Codigo atual.....:%d", L->func[resp - 1].codigo);
      gotoxy(25, 14);
      do
      {
        printf("Novo codigo......:");
        gotoxy(46, 14);
        scanf("%d", &flecha);
        if (validarCodigo(L, flecha) != 1)
        {
          gotoxy(20, 19);
          printf("Este codigo ja esta em uso, insira outro");
          gotoxy(46, 14);
          printf("                                ");
        }
        else
        {
          L->func[resp - 1].codigo = flecha;
          gotoxy(20, 19);
          printf("Cadastrado com sucesso");
        }
      } while (validarCodigo(L, flecha) != 1);
      salvarUsuario(L);
      break;

    case 4:
      limpar();
      gotoxy(25, 12);
      printf("Salario atual.....:%.2f", L->func[resp - 1].salario);
      gotoxy(25, 14);
      do
      {
        printf("Novo salario......:");
        gotoxy(45, 14);
        scanf("%f", &flechafloat);
        if (flechafloat < 0)
        {
          gotoxy(25, 19);
          printf("Insira um salario valido");
        }
        else
        {
          gotoxy(25, 19);
          printf("Cadastrado com sucesso");
        }
      } while (flechafloat < 0);
      salvarUsuario(L);
      break;
    }
  }
}

void excluirCadastro(Lista *L)
{
  limpar();
  int resp, temp, num;
  if (L->inicio == L->final)
  {
    gotoxy(22, 12);
    printf("*NAO TEM FUNCIONARIOS CADASTRADOS*");
    return;
  }
  for (int i = 0; i < L->final; i++)
  {
    gotoxy(02, 8 + i);
    printf("%d)Nome.....%s", i + 1, L->func[i].nome);
  }

  gotoxy(01, 21);
  printf("Deseja excluir algum usuario? (1-Sim 2-Nao).....");
  gotoxy(50, 21);
  scanf("%d", &resp);

  if (resp == 1)
  {
    do
    {
      gotoxy(01, 21);
      printf("Qual usuario voce deseja excluir?....                    ");
      gotoxy(38, 21);
      scanf("%d", &temp);
      if (temp < L->inicio || temp > L->final)
      {
        gotoxy(20, 19);
        printf("Digite um usuario valido");
      }
    } while (temp < L->inicio || temp > L->final);
    limpar();
    gotoxy(25, 10);
    printf("Nome.....%s", L->func[temp - 1].nome);
    gotoxy(25, 11);
    printf("Endereco.%s", L->func[temp - 1].endereco);
    gotoxy(25, 12);
    printf("Codigo...%d", L->func[temp - 1].codigo);
    gotoxy(25, 13);
    printf("Salario..%.2f", L->func[temp - 1].salario);

    gotoxy(01, 21);
    printf("Confirmar exclusao? Essa acao nao pode ser revertida (1-Sim 2-Nao)....");
    gotoxy(72, 21);
    scanf("%d", &num);
    gotoxy(01, 21);
    printf("                                                                            ");
    if (num == 1)
    {
      gotoxy(23, 19);
      printf("*Excluido com sucesso*");
      for (int i = temp - 1; i < L->final - 1; i++)
      {
        L->func[i] = L->func[i + 1];
      }
      L->final--;
      salvarUsuario(L);
    }
  }
}

int menuOpcao()
{
  int resp;
  system("cls");
  tela();
  gotoxy(31, 06);
  printf("MENU OPCOES");
  gotoxy(25, 8);
  printf("1-Cadastrar Funcionario");
  gotoxy(25, 9);
  printf("2-Consultar Funcionario");
  gotoxy(25, 10);
  printf("3-Editar Funcionario");
  gotoxy(25, 11);
  printf("4-Excluir usuario");
  gotoxy(25, 12);
  printf("5-Sair\n");
  gotoxy(01, 21);
  printf("Insira uma resposta....");
  gotoxy(25, 21);
  scanf("%d", &resp);

  return resp;
}

int main()
{
  system("color 3e");
  Lista L;
  inicializaLista(&L);
  carregarFuncionario(&L);
  int menu, reiniciar;

  do
  {
    menu = menuOpcao();

    switch (menu)
    {
    case 1:
      cadastrarFuncionario(&L);
      break;
    case 2:
      consultarCadastro(&L);
      break;
    case 3:
      editarCadastro(&L);
      break;
    case 4:
      excluirCadastro(&L);
      break;
    default:
      return 0;
    }
    gotoxy(01, 21);
    printf("Voltar para o menu (1-Sim 2-Nao).....                     ");
    gotoxy(39, 21);
    scanf("%d", &reiniciar);
  } while (reiniciar == 1);

  limpar();
  gotoxy(25, 12);
  printf("OBRIGADO POR USAR O APLICATIVO");

  gotoxy(01, 25);
  return 0;
}