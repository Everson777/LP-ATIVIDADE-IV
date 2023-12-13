#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
};


void depositar(struct ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Deposito de R$%.2f realizado com sucesso!\n", valor);
    } else {
        printf("Valor do deposito deve ser positivo.\n");
    }
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso!\n", valor);
    } else if (valor <= 0) {
        printf("Valor do saque deve ser positivo.\n");
    } else {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual da conta: R$%.2f\n", conta.saldo);
}


int main() {

    struct ContaBancaria minhaConta = {123456, "Liro", 1000.00, "Corrente"};

    int opcao;
    float valor;

    do {
       
        printf("\nMenu:\n");
        printf("1 - Depositar dinheiro\n");
        printf("2 - Sacar dinheiro\n");
        printf("3 - Consultar saldo\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
               
                printf("Informe o valor a depositar: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;

            case 2:
                
                printf("Informe o valor a sacar: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;

            case 3:
                
                imprimirSaldo(minhaConta);
                break;

            case 4:
                
                printf("Saindo do programa. Obrigado!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}

