// Estrutura de uma Lista Encadeada de inteiros com inserção em forma de pilha (LIFO (Last-In, First-Out)).
#include <stdio.h>
#include <stdlib.h>

struct No {
    int elem;
    struct No *prox;
};

typedef struct No lista; 

// Insere o elemento no topo da fila.
lista *insereElemento(int elem, lista *L) {
    // Criamos os ponteiros que irão nos auxiliar a percorrer a lista.
    lista *novo = (lista *) malloc(sizeof(lista));

    // O sistema foi capaz de alocar?
    if (novo == NULL) {
        printf("Memória insuficiente.\n");
        return L; 
    }

    novo->prox = L; // O novo nó irá apontar para o início da lista. 
    novo->elem = elem; 

    return novo; 
}

// Remove o último elemento inserido na lista.
lista *removeElemento(lista *L) {
    lista *aux; 
    if (L != NULL) {
        aux = L->prox; 
        free(L);
        return aux; 
    }
    return L;
}

// Modifica um elemento por outro a partir da sua posição.
lista *modificaElemento(int pos, int elem, lista *L) {
    lista *aux = L;
    int i = 0;
    while (aux != NULL) {
        if (i == pos) {
            aux->elem = elem;
            return L;
        }
        aux = aux->prox;
        i++; 
    }
    return L;
}

void imprimeLista(lista *L) {
    lista *aux = L;
    printf("[");
    while (aux != NULL) {
        if (aux->prox == NULL) {
            printf("%d]", aux->elem);
        } else {
            printf("%d, ", aux->elem);
        }
        aux = aux->prox;  
    }
}

// Precisamos liberar individualmente cada elemento alocado. 
void liberarLista(lista *L) {
    lista *aux = L, *prox;  
    while (aux != NULL) {
        prox = aux->prox; 
        free(aux);
        aux = prox; 
    }
}

int main (void) {
    lista *L = NULL;
    L = insereElemento(10, L); 
    L = insereElemento(12, L);
    L = insereElemento(14, L);
    imprimeLista(L);
    liberarLista(L); 
    return 0;
}