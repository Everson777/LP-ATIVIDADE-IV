#include <stdio.h>
#include <string.h>

struct Loja_deProdutos
{
    char nome[200];
    float preco;
    int quantidade;
};

float calcularVAlortotal(struct Loja_deProdutos Product)
{
    return Product.preco * Product.quantidade;
}

void Compra(struct Loja_deProdutos *produto, int quantidadeComprada)
{
    produto->quantidade += quantidadeComprada;
}

int main()
{

    struct Loja_deProdutos menuprodutos  = {" Uva", 10.50, 50};

    int opcao;
    int compraRealizada;

    do
    {

        printf("\n\nMenu:");
        printf("\n=========================\n");
        printf("'1' - Realizar uma compra\n");
        printf("'2' - Consultar estoque\n");
        printf("'3' - Encerrar programa!\n");
        printf("Escolha uma das opções:\n");
        printf("\n=======================\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Informe a quantidade a comprar: ");
            scanf("%d", &compraRealizada);
            Compra(&menuprodutos, compraRealizada);
            printf("Compra realizada com sucesso!\n");
            break;

        case 2:
            printf("Nome do produto: %s\n", menuprodutos.nome);
            printf("Preco unitario: R$%.2f\n", menuprodutos.preco);
            printf("Quantidade em estoque: %d\n", menuprodutos.quantidade);
            printf("Valor total em estoque: R$%.2f\n", calcularVAlortotal(menuprodutos));
            break;

        case 3:

            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}