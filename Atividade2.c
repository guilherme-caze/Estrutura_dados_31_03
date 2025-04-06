#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[50];
    int quantidade;
    struct Produto* proximo;
} Produto;

typedef struct ListaDeCompras {
    Produto* inicio;
} ListaDeCompras;

void adicionar_no_inicio(ListaDeCompras* lista, const char* nome, int quantidade) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->proximo = lista->inicio;
    lista->inicio = novoProduto;
}

void adicionar_no_fim(ListaDeCompras* lista, const char* nome, int quantidade) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoProduto;
    } else {
        Produto* temp = lista->inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoProduto;
    }
}

void imprimir_lista(ListaDeCompras* lista) {
    Produto* temp = lista->inicio;
    printf("Lista de Compras:\n");
    while (temp != NULL) {
        printf("%s: %d\n", temp->nome, temp->quantidade);
        temp = temp->proximo;
    }
}

void liberar_lista(ListaDeCompras* lista) {
    Produto* temp = lista->inicio;
    while (temp != NULL) {
        Produto* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    lista->inicio = NULL;
}

int main() {
    ListaDeCompras lista = {NULL};

    adicionar_no_fim(&lista, "Maca", 5);
    adicionar_no_inicio(&lista, "Banana", 10);
    adicionar_no_fim(&lista, "Leite", 2);

    imprimir_lista(&lista);
    
    liberar_lista(&lista); 

    return 0;
}
