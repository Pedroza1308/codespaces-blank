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
    lista->fim=NULL;
    lista->inicio=NULL;
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

ListNode* buscaMelhorada(List lista, int valor){
    ListNode* aux=lista.inicio;
    if(isEmpty(lista)==TRUE){
        return NULL;
    }
    else{
        aux=lista.inicio;
        do{
            if(aux->info==valor){
                return aux;
            }
            else{
                aux=aux->prox;
            }
        }while(aux!=lista.inicio);
    }
    return NULL;
}

ListNode* criarNo(int valor){
    ListNode* aux=(ListNode*) malloc(sizeof(ListNode));
    aux->ant=NULL;
    aux->prox=NULL;
    aux->info=valor;
}

void inserirOrdenado(List* lista, int valor){
    ListNode* aux, *novo;
    novo=criarNo(valor);
    if(buscaMelhorada(*lista, valor)!=NULL){
        printf("valor ja inserido!\n");
    }
    else{
        aux=lista->inicio;
        if(isEmpty(*lista)){
            lista->inicio=novo;
            lista->fim=novo;
            lista->fim->prox=novo;
            lista->inicio->ant=novo;
            lista->qtd++;
        }
        else if(valor < aux->info){
            novo->prox=lista->inicio;
            novo->ant=lista->fim;
            lista->inicio->ant=novo;
            lista->fim->prox=novo;
            lista->inicio=novo;
        }
        else if(valor > aux->info){
            novo->ant=lista->fim;
            lista->fim->prox=novo;
            novo->prox=lista->inicio;
            lista->inicio->ant=novo;
            lista->fim=novo;
        }
        else{
            do{
                aux=aux->prox;
            }while(valor < aux->info);
            novo->prox=aux;
            novo->ant=aux->ant;
            aux->ant->prox=novo;
            aux->ant=novo;
        }
        lista->qtd++;
    }
}

void removerValor(List* lista, int valor){
    ListNode* aux;
    if(isEmpty(*lista)==TRUE){
        printf("lista vazia! remocao nao efetuada\n");
    }
    else if(buscaMelhorada(*lista, valor)==NULL){
        printf("valor nao inserido! remocao nao efetuada\n");
    }
    else{
        aux=lista->inicio;
        if(lista->qtd==1){
            free(aux);
            lista->inicio->ant=NULL;
            lista->fim->prox=NULL;
            lista->inicio=NULL;
            lista->fim=NULL;
            lista->qtd=0;
        }
        else if(valor==aux->info){
            lista->inicio=lista->inicio->prox;
            lista->inicio->ant=lista->fim;
            lista->fim->prox=lista->inicio;
            free(aux);
        }
        else if(valor==lista->fim->info){
            aux=lista->fim;
            lista->fim=aux->ant;
            lista->fim->prox=lista->inicio;
            lista->inicio->ant=lista->fim;
            free(aux);
        }
        else{
            do{
                aux=aux->prox;
            }while(valor!=aux->info);
            aux->ant->prox=aux->prox;
            aux->prox->ant=aux->ant;
            free(aux);
        }
        lista->qtd--;
    }
}

void esvaziar(List* lista){
    ListNode* aux;
    if(isEmpty(*lista)==TRUE){
        printf("lista vazia! operacao nao realizada\n");
    }
    else if(lista->qtd==1){
        
    }
    else{
        aux=lista->inicio;
        do{
            if(lista->qtd==1){
                aux=lista->inicio;
                free(aux);
                lista->inicio=NULL;
                lista->fim=NULL;
                lista->qtd=0;
            }
            else{
                lista->inicio=aux->prox;
                lista->inicio->ant=lista->fim;
                lista->fim->prox=lista->inicio;
                free(aux);
                lista->qtd--;
            }
            aux=lista->inicio;
        }while(lista->qtd>0);
    }
    lista->inicio=NULL;
    lista->fim=NULL;
}