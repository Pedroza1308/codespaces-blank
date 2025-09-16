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

int comparacao(List original, List novo){
    ListNode* auxOriginal,*auxNovo;
    if(isEmpty(original)==TRUE && isEmpty(novo)==TRUE){
        return 1;
    }
    else if(original.qtd!=novo.qtd){
        return 0;
    }
    else{
        auxOriginal=original.inicio; auxNovo=novo.inicio;
        do{
            if(auxOriginal->info!=auxNovo->info){
                return 0;
            }
            else{
                auxNovo=auxNovo->prox;
                auxOriginal=auxOriginal->prox;
            }
        }while(auxOriginal!=original.inicio);
    }
    return 1;
}