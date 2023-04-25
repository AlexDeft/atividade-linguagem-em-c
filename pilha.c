//Alex Aparecido
//Gabriel Diogenes



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100000

typedef struct pilha {
    char dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, char c) {
    if (p->topo == MAX-1) {
        printf("pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->dados[p->topo] = c;
}

char desempilhar(Pilha *p) {
    if (p->topo == -1) {
        printf("pilha vazia\n");
        exit(1);
    }
    char c = p->dados[p->topo];
    p->topo--;
    return c;
}

int main() {
    char str[MAX];
    int i, len, palidromo = 1;
    Pilha p;
    
    printf("Digite uma sequência de caracteres: ");
    fgets(str, MAX, stdin);
    
    len = strlen(str);
    inicializarPilha(&p);
    
    
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            empilhar(&p, tolower(str[i]));
        }
    }
    
    
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) != desempilhar(&p)) {
                palidromo = 0;
                break;
            }
        }
    }
    
    
    printf("O texto na ordem inversa é: ");
    for (i = len-2; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    
    if (palidromo) {
        printf("A sequência digitada é um palindromo");
    } else {
        printf("A sequência digitada não é um palidromo");
    }
    
    return 0;
}