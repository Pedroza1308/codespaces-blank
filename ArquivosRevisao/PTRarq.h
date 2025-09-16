#define TAM 10
#include <stdlib.h>
#include <stdio.h>

typedef struct aluno{
    char ra[TAM];
    char nome[TAM];
    int faltas;
    float media;
} Aluno;

FILE* prepararArquivo(char* nome) {
    FILE* aux;
    aux = fopen(nome,"r+b");
    if(aux==NULL){
        aux = fopen(nome, "w+b");
    }
    return aux;
}

void liberarArquivo(FILE* arquivo, char* nome){
    int status;
    status=fclose(arquivo);
    if(status==0){
        printf("arquivo %s liberado!\n");
    }
    else{
        printf("falha ao tentar!\n");
    }
}

void retirarEnter(char* nome ){

}

void gravar(){

}