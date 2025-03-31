#include <stdio.h>
#include <string.h>

struct Aluno{
    char nome[40];
    int idade;
    int serie;
    int matricula;
};

void inserirOrdenado(int valor, int *tamanho, int vetor[], int indices[], int indice) {
    if (*tamanho >= 100) {
        printf("Lista de alunos cheia!\n");
        return;
    }
    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        indices[i + 1] = indices[i];
        i--;
    }

    vetor[i + 1] = valor;
    indices[i + 1] = indice;
    (*tamanho)++;
}

int main() {
    int tamanho = 0;
    int vetor[100];
    int indices[100];
    struct Aluno alunos[] = {
        {"joaozinho", 16, 3, 3},
        {"Mariazinha", 15, 2, 1},
        {"Pedrinho", 17, 3, 2},
        {"Clebinho", 16, 3, 4}
    };

    for (int i = 0; i < 4; i++) {
        inserirOrdenado(alunos[i].matricula, &tamanho, vetor, indices, i);
    }

        printf("Alunos ordenados pela matricula: \n ");
        for (int i = 0; i < tamanho; i++) {
        printf(" %s - %d \n", alunos[indices[i]].nome,vetor[i]);
}


    return 0;
}
