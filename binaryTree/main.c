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

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf("%d ", raiz->info);
        imprimir(raiz->direita);
    };
}

int main(){

    

    return 0;
}