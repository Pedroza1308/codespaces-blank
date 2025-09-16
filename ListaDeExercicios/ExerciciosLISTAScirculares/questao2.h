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

List dividir(List* original){
    List novo; int count=0; ListNode* aux;
    inicializar(&novo);
    if(isEmpty(*original)==TRUE && original->qtd==1){
        return novo;
    }
    else{
        aux=original->inicio;
        do{
            aux=aux->prox;
            count++;
        }while(count < original->qtd/2);
        novo.inicio=aux;
        novo.fim=original->fim;

        original->fim=aux->ant;

        aux->ant->prox=original->inicio;
        original->inicio->ant=aux->ant;

        novo.inicio->ant=novo.fim;
        novo.fim->prox=aux;

        original->qtd=original->qtd/2;
        novo.qtd=(original->qtd/2) + 1;
    }
    return novo;
}