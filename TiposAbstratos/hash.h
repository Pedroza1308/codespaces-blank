#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hInt(int chv){
    return (chv% /*posicoesDaTabela*/);
}

int hAlfa (char* chv){
    int i, soma=0, tam=strlen(chv);
    for(int i=0; i<tam; i++){
        soma=soma+chv[i];
    }
    return (soma % /*posicoesDaTabela*/);
}

//PROBLEMA: strings diferentes podem resultar em somas iguais!
//SOLUCAO: somatorio com deslocamentos ("shift left", "shift right") -> deslocamento de bits
/*obs: p/ complemento de dois, o bit mais a esquerda indica resultado negativo
    exemplo: 01000010 -> shift left -> 10000100 -> resultado=-126*/

int hDesl(char* chv){
    int i, soma=0, tam=strlen(chv);
    for(i=0; i<tam; i++){
        soma=soma+chv[i] << (i%8);
    }
    return abs(soma) % /*posicoes da tabela*/;
}

//metodos de tratamento de colisao: encadeamento externo!!