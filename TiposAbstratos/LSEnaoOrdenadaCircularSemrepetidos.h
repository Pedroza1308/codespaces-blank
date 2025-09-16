#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
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
    aux->prox=NULL;
    aux->info=valor;
    return aux;
}

void inserirInicio(List* lista, int valor){
    ListNode* novoNo=criarNo(valor); ListNode* aux; int count=0;
    if(isEmpty(*lista)==TRUE){
        lista->inicio=novoNo;
        lista->fim=novoNo;
        lista->fim->prox=lista->inicio;
        lista->qtd++;
    }
    else{
        aux=lista->inicio;
        if(valor!=aux->info){
            while(aux->info > count){
                if(valor==aux->info){
                    printf("valor ja inserido! insercao nao efetuada\n");
                    free(novoNo);
                    break;
                }
                else{
                    aux=aux->prox;
                    count++;
                }
            }
        }
        else{
            novoNo->prox=lista->inicio;
            lista->inicio=novoNo;
            lista->fim->prox=novoNo;
            lista->qtd++;
        }
    }
}

void inserirFinal(List* lista, int valor){
    ListNode* novoNo=criarNo(valor); ListNode* aux; int count=0;
    if(isEmpty(*lista)==TRUE){
        lista->inicio=novoNo;
        lista->fim=novoNo;
        lista->fim->prox=lista->inicio;
        lista->qtd++;
    }
    else{
        aux=lista->inicio;
        if(valor!=aux->info){
            while(lista->qtd > count){
                if(valor==aux->info){
                    printf("valor ja inserido! insercao nao efetuada\n");
                    free(novoNo);
                    break;
                }
                else{
                    aux=aux->prox;
                    count++;
                }
            }
        }
        else{
            lista->fim->prox=novoNo;
            lista->fim=novoNo;
            lista->fim->prox=lista->inicio;
        }
    }
}

void removerInicio(List* lista){
    ListNode* atual;
    if(isEmpty(*lista)==TRUE){
        printf("lista vazia!\n");
    }
    else{
        atual=lista->inicio;
        lista->inicio=lista->inicio->prox;
        lista->fim=lista->inicio;
        lista->qtd--;
        free(atual);
    }
}

void removerFinal(List* lista){
    ListNode* atual; int count=2;
    if(isEmpty(*lista)==TRUE){
        printf("lista vazia!\n");
    }
    else{
        atual=lista->inicio;
        while(count < lista->qtd){
            atual=atual->prox;
            count++;
        }
        lista->fim=atual;
        atual=atual->prox;
        lista->fim->prox=lista->inicio;
        free(atual);
        lista->qtd--;
    }
}

void removerValor(List* lista, int valor){
    ListNode* ant, *atual; int count=0;
    if(isEmpty(*lista)==TRUE){
        printf("lista vazia!\n");
    }
    else{
        atual=lista->inicio; ant=lista->fim;
        if(valor==lista->inicio->info){
            removerInicio(lista);
        }
        else if(valor==lista->fim->info){
            removerFinal(lista);
        }
        else{
            while(count < lista->qtd){
                if(valor==atual->info){
                    ant->prox=atual->prox;
                    free(atual);
                    lista->qtd--;
                }
                else if(count==lista->qtd - 1){
                    printf("valor nao encontrado! remocao nao efetuada\n");
                }
                else{
                    atual=atual->prox;
                    ant=ant->prox;
                    count++;
                }
            }
        }
    }
}

void listar(List lista){
    ListNode* aux; int count=0;
    if(isEmpty(lista)==TRUE){
        printf("lista vazia!\n");
    }
    else{
        aux=lista.inicio;
        while(lista.qtd > count){
            printf("%d\n", aux->info);
            aux=aux->prox;
            count++;
        }
        printf("\n");
    }
}

void esvaziar(List* lista){
    ListNode* aux; int count=0;
    if(lista->qtd==1){
        lista->inicio=NULL;
        lista->fim=NULL;
        lista->qtd=0;
    }
    while(lista->qtd > count){
        aux=lista->inicio;
        lista->inicio=lista->inicio->prox;
        lista->fim->prox=lista->inicio;
        free(aux);
        count++;
    }  
}