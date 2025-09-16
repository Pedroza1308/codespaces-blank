//questao 5
#define TRUE 1
#define FALSE 0
#define TAM 10
#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char RG[TAM];
    char nome[TAM];
    int idade;
    float peso;
}Pessoa;

typedef struct listNode5{
    struct listNode5* prox;
    Pessoa* info;
}ListNode5;

typedef struct list{
    ListNode5* inicio;
    ListNode5* fim;
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

void inserirOrdenado(List* lista, char* nome, int faltas, int media) {
    ListNode5 *novo;
    ListNode5 *aux;
 
    //strcmp Retorna um valor negativo se a primeira string for alfabeticamente menor que a segunda.
    //strcmp Retorna um valor positivo se a primeira string for alfabeticamente maior que a segunda.
    if (isEmpty(*lista)) {
        novo = novoAluno(nome, faltas, media);
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->prox = lista->inicio;
        lista->qtd++;
    }
   
    else if (strcmp(lista->inicio->info.nome, nome) == 0) {
        printf("O aluno já está inserido na lista\n");
    }
   
    else if (strcmp(nome, lista->inicio->info.nome) < 0) {
        novo = novoAluno(nome, faltas, media);
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
        lista->qtd++;
        lista->fim->prox = lista->inicio;
    }
 
    else if (strcmp(lista->fim->info.nome, nome) == 0) {
        printf("O aluno já está na turma\n");
    }
 
    else if (strcmp(nome, lista->fim->info.nome) > 0) {
        novo = novoAluno(nome, faltas, media);
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qtd++;
        lista->fim->prox = lista->inicio;
    }
    else {
        aux = lista->inicio;
        while (aux != NULL) {
            if (strcmp(aux->info.nome, nome) == 0) {
                printf("Aluno já está na sala\n");
                return;
            }
            else if (strcmp(nome, aux->info.nome) < 0) {
                novo = novoAluno(nome, faltas, media);
                novo->prox = aux;
                lista->qtd++;
                return;
            }
            aux = aux->prox;
        }
    }
}

List ordenar(List original){
    List copia; inicializar(&copia);
    ListNode5* aux;
    if(isEmpty(original)==TRUE){
        return copia;
    }
    else{
        if(original.qtd==1){
            copia.inicio=original.inicio;
            copia.fim=original.fim;
            copia.qtd=original.qtd;
        }
        else{
            aux=original.inicio;
            do{
                inserirOrdenado(&copia, aux->info);
                aux=aux->prox;
            }while(aux!=original.inicio);
        }
    }
    return copia;
}

//questao 04
typedef struct aluno{
    char nome[TAM];
    char matricula[TAM];
    float media;
    int faltas;
}Aluno;

typedef struct listNode4{
    struct listNode4* prox;
    struct listNode4* ant;
    Aluno* info;
} ListNode4;

typedef struct lDEC{
    ListNode4* inicio;
    ListNode4* fim;
    int qtd;
}LDEC;

listNode4* criarNo(char* nome, char* matricula, float media, int faltas){
    ListNode4* aux=(ListNode4) malloc(sizeof(ListNode4));
    strcpy(aux->info->nome, nome);
    strcpy(aux->info->matricula, matricula);
    aux->info->media=media;
    aux->info->faltas=faltas;
    return aux;
}

