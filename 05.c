#include <stdio.h>

struct FUNc {
    char nome[50];
    char cargo[30];
    float salario;
};

float calcularMediaSalarial(struct FUNc funcionarios[], int tamanho, const char cargoBusca[]) {
    int contador = 0;
    float somaSalarios = 0;

    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(funcionarios[i].cargo, cargoBusca) == 0) {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador > 0) {
        return somaSalarios / contador;
    } else {
        return 0; 
    }
}

int main() {
    const int tamanhoFuncionarios = 5; 
    struct FUNc funcionarios[tamanhoFuncionarios];

    for (int i = 0; i < tamanhoFuncionarios; ++i) {
        printf("Cadastro do Funcionário %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("Cargo: ");
        scanf("%s", funcionarios[i].cargo);
        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
        printf("\n");
    }

    
    const char cargoProgramador[] = "Programador";
    float mediaSalarialProgramadores = calcularMediaSalarial(funcionarios, tamanhoFuncionarios, cargoProgramador);

    if (mediaSalarialProgramadores > 0) {
        printf("A média salarial dos programadores na empresa é: R$%.2f\n", mediaSalarialProgramadores);
    } else {
        printf("Não há programadores na empresa.\n");
    }

    return 0;
}