#include <stdio.h>
#include <string.h>


struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
};


float calcularMediaSalarial(struct Funcionario funcionarios[], int numFuncionarios, const char cargoAlvo[]) {
    float somaSalarial = 0;
    int contador = 0;

    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0) {
            somaSalarial += funcionarios[i].salario;
            contador++;
        }
    }

    
    if (contador > 0) {
        return somaSalarial / contador;
    } else {
        return 0; 
    }
}

int main() {
    
    struct Funcionario empresa[5] = {
        {"Alice", "Programador", 5000.00},
        {"Bob", "Analista de Sistemas", 4500.00},
        {"Charlie", "Programador", 6000.00},
        {"David", "Gerente de Projeto", 7000.00},
        {"Eva", "Programador", 5500.00},
    };

    const char cargoAlvo[] = "Programador";

    
    int numFuncionarios = sizeof(empresa) / sizeof(empresa[0]);

    
    float mediaSalarial = calcularMediaSalarial(empresa, numFuncionarios, cargoAlvo);

    if (mediaSalarial > 0) {
        printf("A média salarial dos programadores na empresa é: R$%.2f\n", mediaSalarial);
    } else {
        printf("Não há programadores na empresa.\n");
    }

    return 0;
}
