/*Autor.....João Victor
  Data......02/05/25
  Objetivo..Cadastro usuario lista duplamente encadeado*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define Max 50

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
    gotoxy(28, 02);
    printf("CADASTRO DE CLIENTES");
    gotoxy(01, 01);
    printf("Autor.......Joao Carneiro");
    gotoxy(01, 02);
    printf("Faculdade...UNICV");
    gotoxy(01, 03);
    printf("Ano.........2025");
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
        printf("                                                                             ");
    }
    gotoxy(01, 21);
    printf("                                                                             ");
    gotoxy(01, 22);
    printf("                                                                             ");
}

typedef struct
{
    int codigo;
    char nome[Max];
    char endereco[Max];
    char doc[20];
    char cidade[20];
    char uf[5];
    char dataCadastro[20];
    char numeroTelefone[20];
} reg_funcionario;

typedef struct tipoItem *Ponteiro;

typedef struct tipoItem
{
    reg_funcionario conteudo;
    Ponteiro proximo;
    Ponteiro anterior;
} tipoItem;

typedef struct
{
    Ponteiro primeiro;
    Ponteiro ultimo;
    int tamanho;
} Lista;

void inicializaLista(Lista *L)
{
    L->primeiro = NULL;
    L->ultimo = NULL;
    L->tamanho = 0;
}

void salvarDados(Lista *L)
{
    FILE *fp = fopen("funcionarios.dat", "wb");
    if (fp == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("Erro ao abrir o arquivo para escrita!");
        Sleep(2000);
        return;
    }

    Ponteiro atual = L->primeiro;

    if (atual == NULL)
    {
        gotoxy(27, 12);
        printf("Lista vazia, nada a salvar.");
        Sleep(2000);
    }

    while (atual != NULL)
    {
        fwrite(&atual->conteudo, sizeof(reg_funcionario), 1, fp);
        atual = atual->proximo;
    }

    fclose(fp);
}

void carregarArquivo(Lista *L)
{
    FILE *fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL)
    {
        return;
    }

    reg_funcionario temp;

    while (fread(&temp, sizeof(reg_funcionario), 1, fp) == 1)
    {
        Ponteiro novo = (Ponteiro)malloc(sizeof(tipoItem));
        if (novo == NULL)
        {
            printf("Erro de alocação de memória.\n");
            fclose(fp);
            return;
        }

        novo->conteudo = temp;
        novo->proximo = NULL;
        novo->anterior = L->ultimo;

        if (L->ultimo != NULL)
        {
            L->ultimo->proximo = novo;
        }
        else
        {
            L->primeiro = novo;
        }

        L->ultimo = novo;
        L->tamanho++;
    }

    fclose(fp);
}

void telaCadastro()
{
    gotoxy(06, 05);
    printf("Insira seu codigo................");
    gotoxy(06, 07);
    printf("Insira seu nome..................");
    gotoxy(06, 9);
    printf("Insira seu endereco..............");
    gotoxy(06, 11);
    printf("Insira seu numero documento......");
    gotoxy(06, 13);
    printf("Insira sua cidade................");
    gotoxy(06, 15);
    printf("Insira seu UF....................");
    gotoxy(06, 17);
    printf("Insira a data do cadastro........");
    gotoxy(06, 19);
    printf("Insira o seu numero de telefone..");
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

int codigoDuplicado(Lista *L, int codigo)
{
    Ponteiro p = L->primeiro;
    while (p != NULL)
    {
        if (p->conteudo.codigo == codigo)
        {
            return 1;
        }
        p = p->proximo;
    }
    return 0;
}

void entradaCadastro(reg_funcionario *func, Lista *L)
{
    do{
    gotoxy(40, 05);
    scanf("%d", &func->codigo);
    if (codigoDuplicado(L, func->codigo) == 1)
    {
        gotoxy(01, 21);
        printf("Codigo ja existente, cadastre outro!!");
        Sleep(2000);
        gotoxy(01, 21);
        printf("                                        ");
        gotoxy(40, 05);
        printf("             ");
    }else{
        break;
    }
}while(1);
    getchar();
    gotoxy(40, 07);
    fflush(stdin);
    fgets(func->nome, Max, stdin);
    func->nome[strcspn(func->nome, "\n")] = '\0';

    gotoxy(40, 9);
    fflush(stdin);
    fgets(func->endereco, Max, stdin);
    func->endereco[strcspn(func->endereco, "\n")] = '\0';

    gotoxy(40, 11);
    fflush(stdin);
    fgets(func->doc, sizeof(func->doc), stdin);
    func->doc[strcspn(func->doc, "\n")] = '\0';

    gotoxy(40, 13);
    fflush(stdin);
    fgets(func->cidade, sizeof(func->cidade), stdin);
    func->cidade[strcspn(func->cidade, "\n")] = '\0';

    gotoxy(40, 15);
    fflush(stdin);
    fgets(func->uf, sizeof(func->uf), stdin);
    func->uf[strcspn(func->uf, "\n")] = '\0';

    gotoxy(40, 17);
    fflush(stdin);
    fgets(func->dataCadastro, sizeof(func->dataCadastro), stdin);
    func->dataCadastro[strcspn(func->dataCadastro, "\n")] = '\0';

    gotoxy(40, 19);
    fflush(stdin);
    fgets(func->numeroTelefone, sizeof(func->numeroTelefone), stdin);
    func->numeroTelefone[strcspn(func->numeroTelefone, "\n")] = '\0';
}

void cadastraUsuario(Lista *L)
{
    int resp, opcao, contador;
    reg_funcionario func;
    telaCadastro();
    entradaCadastro(&func, L);

    Ponteiro p = (Ponteiro)malloc(sizeof(tipoItem));

    if (p == NULL)
    {
        gotoxy(01, 21);
        printf("Erro ao alocar memoria!!");
        Sleep(2000);
        return;
    }
    gotoxy(01, 21);
    printf("Confirmar cadastro (1-Sim 2-Nao)...               ");
    gotoxy(37, 21);
    scanf("%d", &resp);
    if (resp == 1)
    {
        p->conteudo = func;
        contador = 0;
        if (L->primeiro == NULL)
        {
            // Lista vazia
            L->primeiro = p;
            L->ultimo = p;
            L->tamanho++;
            limpar();
            gotoxy(27, 12);
            printf("Cadastro com sucesso!!");
            salvarDados(L);
            return;
        }

        limpar();
        gotoxy(27, 07);
        printf("*ESCOLHA A POSICAO*");
        gotoxy(27, 8);
        printf("     1-Inicio");
        gotoxy(27, 9);
        printf("     2-Meio");
        gotoxy(27, 10);
        printf("     3-Final");
        gotoxy(01, 21);
        printf("Digite aqui sua resposta....                      ");
        gotoxy(30, 21);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            p->proximo = L->primeiro;
            L->primeiro->anterior = p;
            p->anterior = NULL;
            L->primeiro = p;
            L->tamanho++;
            limpar();
            gotoxy(18, 12);
            printf("Adicionado no inicio da fila com sucesso!!");
            salvarDados(L);
            break;
        case 2:
            do
            {
                printf("Em qual posicao deseja adicionar (Max %d)...", L->tamanho);
                scanf("%d", &resp);
                if (resp < 0 || resp > L->tamanho)
                {
                    gotoxy(01, 21);
                    printf("Insira um posicao valida!!");
                }
            } while (resp < 0 || resp > L->tamanho);
            Ponteiro n = L->primeiro;

            while (contador < resp - 1)
            {
                n = n->proximo;
                contador++;
            }
            Ponteiro aux = n->proximo;

            n->proximo = p;
            p->anterior = n;
            p->proximo = aux;
            if (aux != NULL)
            {
                aux->anterior = p;
            }
            L->tamanho++;
            limpar();
            gotoxy(18, 12);
            printf("Adicionado na posicao %d da fila com sucesso!!", resp);
            salvarDados(L);
            break;
        case 3:
            p->anterior = L->ultimo;
            L->ultimo->proximo = p;
            p->proximo = NULL;
            L->ultimo = p;
            L->tamanho++;
            limpar();
            gotoxy(18, 12);
            printf("Adicionado no final da fila com sucesso!!");
            salvarDados(L);
            break;
        default:
            break;
        }
    }
}

void mostraUsuario(Ponteiro p)
{

    limpar();
    gotoxy(28, 06);
    printf("USUARIO SELECIONADO");
    gotoxy(22, 07);
    printf("1)Codigo...........%d", p->conteudo.codigo);
    gotoxy(22, 8);
    printf("2)Nome.............%s", p->conteudo.nome);
    gotoxy(22, 9);
    printf("3)Endereco.........%s", p->conteudo.endereco);
    gotoxy(22, 10);
    printf("4)Numero documento.%s", p->conteudo.doc);
    gotoxy(22, 11);
    printf("5)Cidade...........%s %s", p->conteudo.cidade, p->conteudo.uf);
    gotoxy(22, 12);
    printf("6)Data cadastro....%s", p->conteudo.dataCadastro);
    gotoxy(22, 13);
    printf("7)Numero telefone..%s", p->conteudo.numeroTelefone);
}

void consultaCodigo(Lista *L)
{
    int codigo;
    Ponteiro p = L->primeiro;
    limpar();
    gotoxy(24, 12);
    printf("**CONSULTA POR CODIGO**");
    gotoxy(01, 21);
    printf("Digite o codigo que deseja consultar...");
    gotoxy(41, 21);
    scanf("%d", &codigo);

    while (p != NULL)
    {
        if (codigo == p->conteudo.codigo)
        {
            mostraUsuario(p);
            return;
        }
        p = p->proximo;
    }
    limpar();
    gotoxy(24, 12);
    printf("*CODIGO NAO ENCONTRADO*");
    return;
}

void ordenaCodigo(Lista *L)
{
    if (L->primeiro == NULL)
    {
        return;
    }

    Ponteiro p;
    Ponteiro q;
    reg_funcionario temp;

    p = L->primeiro;

    while (p->proximo != NULL)
    {
        q = p->proximo;
        if (p->conteudo.codigo > q->conteudo.codigo)
        {
            temp = p->conteudo;
            p->conteudo = q->conteudo;
            q->conteudo = temp;
        }
        p = p->proximo;
    }
}

void ordenaNome(Lista *L)
{
    if (L->primeiro == NULL)
    {
        return;
    }

    Ponteiro p;
    Ponteiro q;
    reg_funcionario func;

    p = L->primeiro;

    while (p->proximo != NULL)
    {
        q = p->proximo;
        if (strcmp(p->conteudo.nome, q->conteudo.nome) > 0)
        {
            func = p->conteudo;
            p->conteudo = q->conteudo;
            q->conteudo = func;
        }
        p = p->proximo;
    }
}

void ordemCodigo(Lista *L)
{

    Ponteiro p = L->primeiro;
    int contador = 1;
    limpar();
    gotoxy(01, 06);
    printf("|Codigo    |Nome Completo                                |Data Cadastro          ");

    while (p != NULL)
    {
        gotoxy(01, 06 + contador);
        printf("|%-10d|%-45s|%-8s", p->conteudo.codigo, p->conteudo.nome, p->conteudo.dataCadastro);
        p = p->proximo;
        contador++;
        if (contador >= 14)
        {
            gotoxy(01, 21);
            printf("Pressione ENTER para a proxima pagina");
            getch();

            contador = 0;
            limpar();
            gotoxy(01, 06);
            printf("|Codigo    |Nome Completo                                |Data Cadastro          ");
        }
    }
}

void consultaUsuario(Lista *L)
{

    int resp;
    limpar();
    if (L->primeiro == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("A LISTA ESTA VAZIA");
        return;
    }

    gotoxy(25, 06);
    printf("*MENU OPCOES*");
    gotoxy(22, 8);
    printf("1-Consultar por codigo");
    gotoxy(22, 10);
    printf("2-Ordem alfabeticar");
    gotoxy(22, 12);
    printf("3-Ordem de codigo");
    gotoxy(01, 21);
    printf("Insira sua resposta....           ");
    gotoxy(25, 21);
    scanf("%d", &resp);

    switch (resp)
    {
    case 1:
        consultaCodigo(L);
        break;
    case 2:
        ordenaNome(L);
        ordemCodigo(L);
        break;
    case 3:
        ordenaCodigo(L);
        ordemCodigo(L);
        break;
    }
}

void excluiUsuario(Lista *L)
{
    int resp, confirmar, opcao;
    Ponteiro p = L->primeiro;

    if (L->primeiro == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("A LISTA ESTA VAZIA");
        return;
    }
    limpar();
    gotoxy(27, 07);
    printf("*ESCOLHA A POSICAO*");
    gotoxy(27, 8);
    printf("     1-Inicio");
    gotoxy(27, 9);
    printf("     2-Meio");
    gotoxy(27, 10);
    printf("     3-Final");
    gotoxy(01, 21);
    printf("Digite aqui sua resposta....                      ");
    gotoxy(30, 21);
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        mostraUsuario(p);
        gotoxy(01, 21);
        printf("Deseja realmente excluir? (1-Sim / 2-Nao):            ");
        gotoxy(44, 21);
        scanf("%d", &confirmar);
        if (confirmar != 1)
        {
            gotoxy(01, 22);
            printf("Operacao cancelada pelo usuario.");
            return;
        }
        L->primeiro = p->proximo;
        if (L->primeiro != NULL)
        {
            L->primeiro->anterior = NULL;
        }
        else
        {
            L->ultimo = NULL;
        }
        free(p);
        salvarDados(L);
        break;
    case 2:
        limpar();
        ordemCodigo(L);

        gotoxy(01, 21);
        printf("Qual usuario deseja excluir (%d MAX)..", L->tamanho);
        gotoxy(40, 21);
        scanf("%d", &resp);

        if (resp < 1 || resp > L->tamanho)
        {
            limpar();
            gotoxy(27, 12);
            printf("Posicao invalida.");
            return;
        }

        for (int i = 1; i < resp; i++)
        {
            p = p->proximo;
        }

        mostraUsuario(p);
        gotoxy(01, 21);
        printf("Deseja realmente excluir? (1-Sim / 2-Nao):            ");
        gotoxy(44, 21);
        scanf("%d", &confirmar);
        if (confirmar != 1)
        {
            gotoxy(01, 22);
            printf("Operacao cancelada pelo usuario.");
            return;
        }

        if (resp == 1)
        {
            Ponteiro aux = L->primeiro;
            if (L->primeiro == L->ultimo)
            {
                L->primeiro = NULL;
                L->ultimo = NULL;
            }
            else
            {
                L->primeiro = aux->proximo;
                L->primeiro->anterior = NULL;
            }
            free(aux);
        }
        else
        {

            if (p == L->ultimo)
            {
                L->ultimo = p->anterior;
                L->ultimo->proximo = NULL;
            }
            else
            {
                p->anterior->proximo = p->proximo;
                p->proximo->anterior = p->anterior;
            }
            free(p);
        }
        salvarDados(L);
        break;
    case 3:
        p = L->ultimo;
        mostraUsuario(p);
        gotoxy(01, 21);
        printf("Deseja realmente excluir? (1-Sim / 2-Nao):            ");
        gotoxy(44, 21);
        scanf("%d", &confirmar);
        if (confirmar != 1)
        {
            gotoxy(01, 22);
            printf("Operacao cancelada pelo usuario.");
            return;
        }

        L->ultimo = p->anterior;
        if (L->ultimo != NULL)
            L->ultimo->proximo = NULL;
        else
            L->primeiro = NULL;

        free(p);
        salvarDados(L);
        break;
    default:
        gotoxy(27, 12);
        printf("Opcao invalida.");
        return;
    }
    L->tamanho--;
    limpar();
    gotoxy(24, 12);
    printf("Funcionario excluido com sucesso.");
}

void editaUsuario(Lista *L)
{
    int resp;
    int confirmar;
    int opcao;
    Ponteiro p = L->primeiro;
    if (L->primeiro == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("A LISTA ESTA VAZIA");
        return;
    }

    consultaUsuario(L);

    gotoxy(01, 21);
    printf("Qual usuario deseja editar (%d MAX)..                  ", L->tamanho);
    gotoxy(39, 21);
    scanf("%d", &resp);

    if (resp < 1 || resp > L->tamanho)
    {
        limpar();
        gotoxy(27, 12);
        printf("Posicao invalida.");
        return;
    }

    for (int i = 1; i < resp; i++)
    {
        p = p->proximo;
    }

    mostraUsuario(p);
    gotoxy(01, 21);
    printf("Deseja realmente editar? (1-Sim / 2-Nao):                ");
    gotoxy(43, 21);
    scanf("%d", &confirmar);
    if (confirmar != 1)
    {
        gotoxy(01, 22);
        printf("Operacao cancelada pelo usuario.");
        return;
    }

    gotoxy(01, 21);
    printf("Qual campo deseja editar?...                    ");
    gotoxy(30, 21);
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR CODIGO");
        gotoxy(20, 8);
        printf("Codigo atual......: %d", p->conteudo.codigo);
        gotoxy(20, 10);
        printf("Novo codigo.......: ");
        gotoxy(41, 10);
        scanf("%d", &p->conteudo.codigo);
        getchar();
        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;

    case 2:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR NOME");
        gotoxy(20, 8);
        printf("Nome atual........: %s", p->conteudo.nome);
        gotoxy(20, 10);
        printf("Novo nome.........: ");
        gotoxy(41, 10);
        fflush(stdin);
        fgets(p->conteudo.nome, sizeof(p->conteudo.nome), stdin);
        p->conteudo.nome[strcspn(p->conteudo.nome, "\n")] = '\0';

        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;

    case 3:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR ENDERECO");
        gotoxy(20, 8);
        printf("Endereco atual....: %s", p->conteudo.endereco);
        gotoxy(20, 10);
        printf("Novo endereco.....: ");
        gotoxy(41, 10);
        fflush(stdin);
        fgets(p->conteudo.endereco, sizeof(p->conteudo.endereco), stdin);
        p->conteudo.endereco[strcspn(p->conteudo.endereco, "\n")] = '\0';
        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;

    case 4:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR NUMERO DOCUMENTO");
        gotoxy(20, 8);
        printf("Documento atual...: %s", p->conteudo.doc);
        gotoxy(20, 10);
        printf("Novo documento....: ");
        gotoxy(41, 10);
        fflush(stdin);
        fgets(p->conteudo.doc, sizeof(p->conteudo.doc), stdin);
        p->conteudo.doc[strcspn(p->conteudo.doc, "\n")] = '\0';
        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;

    case 5:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR CIDADE");
        gotoxy(20, 8);
        printf("Cidade atual......: %s", p->conteudo.cidade);
        gotoxy(20, 10);
        printf("Nova cidade.......: ");
        gotoxy(41, 10);
        fflush(stdin);
        fgets(p->conteudo.cidade, sizeof(p->conteudo.cidade), stdin);
        p->conteudo.cidade[strcspn(p->conteudo.cidade, "\n")] = '\0';
        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;


    case 6:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR DATA DE CADASTRO");
        gotoxy(20, 8);
        printf("Data atual........: %s", p->conteudo.dataCadastro);
        gotoxy(20, 10);
        printf("Nova data.........: ");
        gotoxy(41, 10);
        fflush(stdin);
        fgets(p->conteudo.dataCadastro, sizeof(p->conteudo.dataCadastro), stdin);
        p->conteudo.dataCadastro[strcspn(p->conteudo.dataCadastro, "\n")] = '\0';
        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;

    case 7:
        limpar();
        gotoxy(30, 6);
        printf("ALTERAR NUMERO TELEFONE");
        gotoxy(20, 8);
        printf("Telefone atual....: %s", p->conteudo.numeroTelefone);
        gotoxy(20, 10);
        printf("Novo telefone.....: ");
        gotoxy(41, 10);
        fflush(stdin);
        fgets(p->conteudo.numeroTelefone, sizeof(p->conteudo.numeroTelefone), stdin);
        p->conteudo.numeroTelefone[strcspn(p->conteudo.numeroTelefone, "\n")] = '\0';
        limpar();
        gotoxy(27, 12);
        printf("Atualizado com sucesso!!");
        salvarDados(L);
        break;
    default:
        limpar();
        gotoxy(27, 12);
        printf("Posicao invalida.");
        break;
    }
}

int main()
{
    int resp;
    system("color 1f");
    Lista L;
    inicializaLista(&L);
    carregarArquivo(&L);

    do
    {
        limpar();
        tela();
        resp = menuOpcao();

        switch (resp)
        {
        case 1:
            limpar();
            cadastraUsuario(&L);
            break;
        case 2:
            limpar();
            consultaUsuario(&L);
            break;
        case 3:
            limpar();
            editaUsuario(&L);
            break;
        case 4:
            limpar();
            excluiUsuario(&L);
            break;
        case 5:
            exit(1);
        default:
            limpar();
            gotoxy(22, 12);
            printf("Insira um valor valido");
            break;
        }
        gotoxy(01, 21);
        printf("Voltar ao menu (1-Sim 2-Nao)....           ");
        gotoxy(34, 21);
        scanf("%d", &resp);
        getchar();
    } while (resp == 1);
    gotoxy(01, 23);
    return 0;
}