// Estrutura de uma Lista Encadeada de inteiros com inserção ordenada.
#include <stdio.h>
#include <stdlib.h>

struct No {
    int elem;
    struct No *prox;
};

typedef struct No lista; 

// Verifica se o elemento está presente na lista. Caso esteja, retornará a posição do nó anterior a partir de *pre.
int buscaElemento(int elem, lista *L, lista **pre) {
    lista *aux = L, *ant = L;
    while (aux != NULL) {
        if (aux->elem == elem) {
            *pre = ant; 
            return 1;
        }
        ant = aux;
        aux = aux->prox; 
    }
    return -1; 
}

// Insere o elemento em meio a uma lista ordenada.
lista *insereElemento(int elem, lista *L) {
    lista *pre = NULL, *aux = L, *novo = (lista *) malloc(sizeof(lista));
    if (novo == NULL) {
        printf("Memória insuficiente");
        return L;
    } 
    novo->elem = elem; 
    // Verifica se é uma lista vazia. Caso seja, insere o elemento ao início dela.
    if (L == NULL) {
        // Novo->Prox aponta para a posição anterior do L, enquanto uma nova é definida.   
        novo->prox = L; 
        return novo; 
    }
    // Percorre a lista em busca da posição adequada em uma lista crescente de inteiros. 
    while (aux != NULL && (elem > aux->elem)) {
        pre = aux;
        aux = aux->prox;
    }
    // 'novo' é inserido entre 'pre' e 'aux'. 
    pre->prox = novo; 
    novo->prox = aux; 
    return L; 
}

// Remove a primeira ocorrência do elemento.
lista *removeElemento(int elem, lista *L) {
    lista *pre, *prox, *lixo; 
    // Verificamos se o elemento procurado é o primeiro da Lista.
    if (L->elem == elem) {
        lixo = L; 
        L = L->prox; 
        free(lixo);
    } else {
        // Passamos 'pre' por referência para que o seu valor possa ser alterado dentro da função.
        if (buscaElemento(elem, L, &pre) == 1) {
            lixo = pre->prox; 
            prox = lixo->prox; 
            pre->prox = prox; 
            free(lixo); 
        } else {
            printf("O elemento a ser removido não se encontra na lista.\n");
        }
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

void liberarLista(lista *L) {
    lista *aux = L, *prox;  
    while (aux != NULL) {
        prox = aux->prox; 
        free(aux);
        aux = prox; 
    }
}

int main(void) {
    lista *L = NULL;
    L = insereElemento(10, L); 
    L = insereElemento(16, L);
    L = insereElemento(14, L);
    L = removeElemento(10, L);
    imprimeLista(L);
    liberarLista(L); 
    return 0; 
}