#include <stdio.h>

struct INfAL
{
    char nome[50];
    char dataNascimento[20];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct INfAL aluno)
{
    return (aluno.nota1 + aluno.nota2) / 2.0;
}

void verificarAprovacaodoAL(struct INfAL aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("%s  APROVADO!\n", aluno.nome);
    }
    else
    {
        printf("%s  REPROVADO.\n", aluno.nome);
    }
}

int main()
{

    struct INfAL alunos[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a data de nascimento do aluno %d: ", i + 1);
        scanf("%s", alunos[i].dataNascimento);

        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcularMedia(alunos[i]);

        printf("Média do aluno %d: %.2f\n", i + 1, alunos[i].media);

        verificarAprovacaodoAL(alunos[i]);

        printf("\n");
    }

    return 0;
}