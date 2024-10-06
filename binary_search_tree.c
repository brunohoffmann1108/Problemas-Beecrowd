#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *esquerdo;
    struct node *direito;
} node;

node *raiz = NULL;

node *cria_node(int valor){
    node *temp = malloc(sizeof(node));
    temp->esquerdo = NULL;
    temp->direito = NULL;
    temp->valor = valor;
    return temp;
}

void adiciona_node(node *novo, node **local_arvore){
    if(*local_arvore == NULL){
        *local_arvore = novo;
        return;
    }
    if(novo->valor < (*local_arvore)->valor){
        adiciona_node(novo, &(*local_arvore)->esquerdo);
    }
    else{
        adiciona_node(novo, &(*local_arvore)->direito);
    }
}

void printa_arvore(node *node_printado){
    if(node_printado == NULL){
        return;
    }
    printf("%i ", node_printado->valor);
    printa_arvore(node_printado->esquerdo);
    printa_arvore(node_printado->direito);
}


int main(){
    int casos_teste;
    scanf("%i", &casos_teste);
    for(int i = 0; i < casos_teste; i++){
        raiz = NULL;
        int num_nodes;
        scanf("%i", &num_nodes);
        for(int j = 0; j < num_nodes; j++){
            int node;
            scanf("%i", &node);
            adiciona_node(cria_node(node), &raiz);
        }
        printf("Case %i:\n", i + 1);
        printa_arvore(raiz);
        printf("\n");
    }

    return 0;
}