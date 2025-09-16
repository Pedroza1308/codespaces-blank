#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    struct listNode* prox;
    struct listNode* ant;
    int info;
}ListNode;

typedef struct list{
    ListNode* inicio;
    ListNode* fim;
    int qtd;
}List;

void inicializar(List* lista){
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->qtd=0;
}

int isEmpty(List lista){
    if(lista.qtd==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void concatenar(List* original, List* novo){
    original->fim->prox=novo->inicio;
    novo->inicio->ant=original->fim;
    original->inicio->ant=novo->fim;
    novo->fim->prox=original->inicio;
    original->fim=novo->fim;
    novo->inicio=NULL;
    novo->fim=NULL;
    novo->qtd=0;
}