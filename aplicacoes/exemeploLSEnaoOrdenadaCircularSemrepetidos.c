#include "../TiposAbstratos/LSEnaoOrdenadaCircularSemrepetidos.h"

void exibirOpcoes(){
    printf("\n");
    printf("opcoes:\n");
    printf("1) inserir no inicio\n");
    printf("2) inserir no final\n");
    printf("3) remover o primeiro\n");
    printf("4) remover o ultimo\n");
    printf("5) remover um valor especifico\n");
    printf("6) exibir todos\n");
    printf("0) sair\n");
    printf("informe a opcao desejada: ");
}

int main(){
    List listaNumeros;
    inicializar(&listaNumeros);
    int op, num;
    do{
        exibirOpcoes();
        scanf("%d", &op);
        switch(op){
            case 1: printf("informe um valor a ser inserido: ");
                scanf("%d", &num);
                inserirInicio(&listaNumeros, num);
                break;
            case 2: printf("informe um valor a ser inserido: ");
                scanf("%d", &num);
                inserirFinal(&listaNumeros, num);
                break;
            case 3: removerInicio;
                break;
            case 4: removerFinal;
                break;
            case 5: printf("informe um valor a ser removido: ");
                scanf("%d", &num);
                removerValor(&listaNumeros, num);
                break;
            case 6: listar(listaNumeros);
                break;
            case 0: printf("bye bye\n");
        }
    }while(op!=0);
    esvaziar(&listaNumeros);
    return 0;
}