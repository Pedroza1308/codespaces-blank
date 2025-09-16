#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{
    struct listNode* ant;
    struct listNode* prox;
    int info;
} ListNode;

typedef struct list{
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} List;

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

ListNode* criarNo(int valor){
    ListNode* aux=(ListNode*) malloc(sizeof(ListNode));
    aux->ant=NULL;
    aux->prox=NULL;
    aux->info=valor;
    return aux;
}

List dividir(List* original){
    List aux; int count=0;
    inicializar(&aux);
    if(isEmpty(*original)==TRUE){
        printf("lista vazia! impossivel dividir\n");
    }
    else{
        if(original->qtd==1){
            return aux;
        }
        else{
            ListNode* ass = original->inicio;
            while(count < original->qtd/2){
                ass=ass->prox;
                count++;
            }
            aux.inicio=ass;
            aux.fim=original->fim;
            
            ass->ant->prox=original->inicio;
            original->inicio->ant=ass->ant;
            original->fim=ass->ant;
            aux.fim->prox=ass;
            if(original->qtd%2==0){
                original->qtd=original->qtd/2;
                aux.qtd=original->qtd;
            }
            else if(original->qtd%2!=0){
                original->qtd=original->qtd/2;
                aux.qtd=original->qtd + 1;
            }
        }
    }
    return aux;
}