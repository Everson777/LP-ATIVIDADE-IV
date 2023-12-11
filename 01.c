#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 3

struct InfoUS
{
    char nome[2000];
    char numero[11];
    char email[2000];
};

void buscarTelefonePeloNome(struct InfoUS contato[], char *contatoDesejado)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(contato[i].nome, contatoDesejado) == 0)
        {
            printf("\nTelefone de %s:%s", contato[i].nome, contato[i].numero);
            break;
        }
    }
    printf("\nContato não encontrado.");
}

int main()
{
    int i;
    char contatoDesejado[200];
    struct InfoUS contatos[3];

    setlocale(LC_ALL, "");

    for (i = 0; i < TAM; i++)
    {
        printf("\nDigite os dados do %dº contato:\n", i + 1);
        printf("Nome:");
        gets(contatos[i].nome);
        printf("\nTelefone:\n");
        gets(contatos[i].numero);
        printf("\nE-mail\n");
        gets(contatos[i].email);
    }

    printf("\nDigite o nome do contato que deseja buscar:");
    gets(contatoDesejado);

    buscarTelefonePeloNome(contatos, contatoDesejado);
    return 0;
}
