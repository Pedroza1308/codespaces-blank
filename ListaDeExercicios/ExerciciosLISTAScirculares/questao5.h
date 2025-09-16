#define TAM 10
#define TRUE 1
#define FALSE 0
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char nome[TAM];
    char RG[TAM];
    int idade;
    double peso;
    double altura;
}Student;

typedef struct listNode{
    struct listNode* prox;
    struct listNode* ant;
    Student* info;
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

Student* criarAluno(char* nome, char* rg, int idade, double peso, double altura){
    Student* aux =(Student*) malloc(sizeof(Student));
    strcpy(aux->nome,nome);
    strcpy(aux->RG,rg);
    aux->idade=idade;
    aux->peso=peso;
    aux->altura=altura;
    return aux;
}

ListNode* criarNo(Student* aluno){
    ListNode* novoNo=(ListNode*) malloc(sizeof(ListNode));
    novoNo->ant=NULL;
    novoNo->prox=NULL;
    novoNo->info=aluno;
}

