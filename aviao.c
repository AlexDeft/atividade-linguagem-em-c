//Gabriel Diogenes
//Alex Aparecido

#include <stdio.h>
#include <stdlib.h>

#define MAX_AVIOES 100

struct Aviao {
    int numero;
    char modelo[10];
    char cor[10];
};

struct FilaDecolagem {
    struct Aviao avioes[MAX_AVIOES];
    int inicio, fim;
};

void inicializarFila(struct FilaDecolagem *fila) {
    fila->inicio = 0;
    fila->fim = -1;
}

void adicionarAviao(struct FilaDecolagem *fila) {
    if (fila->fim == MAX_AVIOES - 1) {
        printf("A fila de espera esta cheia.\n");
        return;
    }

    struct Aviao aviao;
    printf("Digite o numero do aviao: ");
    scanf("%d", &aviao.numero);
    printf("Digite o modelo do aviao: ");
    scanf("%s", aviao.modelo);
    printf("Digite a cor do aviao: ");
    scanf("%s", aviao.cor);


    fila->fim++;
    fila->avioes[fila->fim] = aviao;
}

void listarAvioes(struct FilaDecolagem *fila) {
    if (fila->fim < fila->inicio) {
        printf("Nao ha avioes na fila de espera.\n");
        return;
    }

    printf("Avioes na fila de espera:\n");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("Numero: %d - Modelo: %s - Cor: %s \n", fila->avioes[i].numero, fila->avioes[i].modelo, fila->avioes[i].cor);
    }
}

void listarProximoAviao(struct FilaDecolagem *fila) {
    if (fila->fim < fila->inicio) {
        printf("Nao ha avioes na fila de espera.\n");
        return;
    }

    printf("Proximo aviao a decolar:\n");
    printf("Numero: %d\n", fila->avioes[fila->inicio].numero);
    printf("Modelo: %s\n", fila->avioes[fila->inicio].modelo);
    printf("Cor: %s\n", fila->avioes[fila->inicio].cor);
}

void autorizarDecolagem(struct FilaDecolagem *fila) {
    if (fila->fim < fila->inicio) {
        printf("Nao ha avioes na fila de espera.\n");
        return;
    }

    printf("Autorizando decolagem do aviao de numero:%d\n", fila->avioes[fila->inicio].numero);
    printf("Do modelo: %s\n", fila->avioes[fila->inicio].modelo);
    printf("Da cor: %s\n", fila->avioes[fila->inicio].cor);


    fila->inicio++;
}

int main() {
    struct FilaDecolagem fila;
    inicializarFila(&fila);

    int opcao;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar aviao a fila de espera\n");
        printf("2 - Listar avioes na fila de espera\n");
        printf("3 - Listar proximo aviao a decolar\n");
        printf("4 - Autorizar decolagem do proximo aviao\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAviao(&fila);
                break;
            case 2:
                listarAvioes(&fila);
                break;
            case 3:
                listarProximoAviao(&fila);
                break;
            case 4:
                autorizarDecolagem(&fila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
             default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
