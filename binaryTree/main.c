#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esquerda, *direita;

}No;

typedef struct{
    No *raiz;
}ArvB;

void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->info = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }else {
        if(valor < no->esquerda->info) inserirEsquerda(no->esquerda, valor);
        else inserirDireita(no->esquerda, valor);
    }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->info = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }else {
        if(valor > no->direita->info) inserirDireita(no->direita, valor);
        else inserirEsquerda(no->direita, valor);
    }

}

void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->info = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }else {
        if(valor < arv->raiz->info) inserirEsquerda(arv->raiz, valor);
        else inserirDireita(arv->raiz, valor);
    }
}

int tamanhoArv(No *raiz){
    if(raiz == NULL) return 0;
    else return 1 + tamanhoArv(raiz->esquerda) + tamanhoArv(raiz->direita);
}

void buscar(No *raiz, int valor){
    if(raiz == NULL){
        printf("Valor nao pertence a arvore");
        return;
    }else {
        if(raiz->info == valor){
            printf("Valor pertence a arvore");
            return;
        } else{
            if(valor < raiz->info) 
                return buscar(raiz->esquerda, valor);
            else 
                return buscar(raiz->direita, valor);
        }
    }
}

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf("%d ", raiz->info);
        imprimir(raiz->direita);
    };
}

No* remover(No *raiz, int valor){
    if(raiz == NULL){
        printf("Valor nao encontrado");
        return NULL;
    }else {
        if(raiz->info == valor){
            // remove nós folhas(sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }else {
                // remove nós com apenas um filho
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;

                    free(raiz);
                    return aux; 
                }else {
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->info = aux->info;
                    aux->info = valor;
                    raiz->esquerda = remover(raiz->esquerda, valor);
                    return raiz;
                }
            }
        }else {
            if(valor < raiz->info)
                raiz->esquerda = remover(raiz->esquerda, valor);
            else   
                raiz->direita = remover(raiz->direita, valor);

            return raiz; 
        }
    }
}

int main(){
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Tamanho\n4 - Buscar\n5 - Remover\n");

        scanf("%d", &op);

        switch(op){
            case 0: 
                printf("\nSaindo\n");
                break;
            case 1:
                printf("\nDigite o valor: \n");
                scanf("%d", &valor);
                inserir(&arv, valor);
                break;
            case 2:
                imprimir(arv.raiz);
                printf("\n");
                break;
            case 3:
                printf("\nTamanho da arvore eh: %d", tamanhoArv(arv.raiz));
                printf("\n");
                break;
            case 4:
                printf("\nDigite o valor que deseja buscar: \n");
                scanf("%d", &valor);
                buscar(arv.raiz, valor);
                printf("\n");
                break;
            case 5:
                printf("\nDigite o valor que deseja remover: \n");
                scanf("%d", &valor);
                arv.raiz = remover(arv.raiz, valor);
                printf("\n");
                break;    
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while (op != 0);

    return 0;
}