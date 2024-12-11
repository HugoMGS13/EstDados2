//Discente: Hugo Martins Gaspar da Silva
//Matrícula: 202311140020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noh Noh;
struct noh{
    //Estrutura de cada nó do grafo (não necessariamente um vértice)
    int rotulo; //Valor do nó
    Noh *prox; //Ponteiro pro próximo nó
};

typedef struct grafo{
    //Estrutura do grafo
    Noh **A; //O apontador A aponta para a estrutura Noh que tem um apontador prox, logo A é um apontador de apontador
    int n; //nós
    int a; //arestas
}*Grafo; //Typedef está declarando um ponteiro para a struct grafo, ou seja, ao criar um grafo nós já estamos 
//criando um ponteiro para a struct grafo sem precisar criar um manualmente

Grafo inicializarGrafo(int n){

    Grafo G = malloc(sizeof(*G)); //Alocando o espaço para o grafo do tamanho da estrutura do grafo (*G aponta para a estrutura)

    G->n = n; //Colocando o número de nós
    G->a = 0; //No momento da inicialização do grafo, não há arestas 
    G->A = malloc(n * sizeof(Noh *)); //Alocando o espaço para os Nós de um grafo. Serão alocados n espaços para os nós
    //n = quantidade de nós, e o tamanho do alocamento será do tamanho de um ponteiro do tipo Nó

    for( int i = 0; i < n; i++){
        //Laço para colocar o valor de todos nós como NULL
        G->A[i] = NULL;
    }
    return G; //retornando o grafo
}

// Função recursiva para realizar DFS
void dfs_recursive(Grafo G, int current_node, bool visited[]) {
    // Marca o nó atual como visitado
    visited[current_node] = true;
    printf("Visitou noh: %d\n", current_node);

    // Percorre os vizinhos do nó atual
    Noh* temp = G->A[current_node];
    while (temp != NULL) {
        int adjacent = temp->rotulo;
        if (!visited[adjacent]) {
            dfs_recursive(G, adjacent, visited);
        }
        temp = temp->prox;
    }
}

// Função principal para realizar DFS
void dfs(Grafo G, int start_node) {
    // Vetor para rastrear os nós visitados
    bool visited[100] = {false};

    // Inicia a DFS
    dfs_recursive(G, start_node, visited);
}

void bfs(Grafo G, int start_node){
    
}

void inserirAresta(Grafo G, int o, int d){ //d = vértice destino, o = vértice de origem 
    //Inserir uma aresta pra conectar um nó de origem da aresta (o) em um nó de destino (d)
    Noh *p; //Ponteiro auxiliar
    for (p = G->A[o]; p != NULL; p = p->prox){ 
        //Iterando o vetor que armazena os vetores-vértices em busca
        //de saber se o novo vértice a ser inserido (n) já existe 
        if(p->rotulo == d){
            //Quando se achar o nó, termina a função, pois o vértice já existe
            printf("Esse aresta ja existe \n");
            return;
        }
    }
    p = malloc(sizeof(Noh)); // Alocando a aresta

    p->rotulo = d; //Colocando na parte de dados do nó o seu novo rótulo

    p->prox = G->A[o]; //Aponto o ponteiro do nó para o próximo nó

    G->A[o] = p; //Apontando o nó de origem para o novo nó e assim encaixa-lo no grafo

    G->a++; //Aumentando o número de arestas

}

void liberargrafo(Grafo G){
    Noh *p; //Ponteiro auxiliar
    for (int i = 0; i < G->n; i++){ //Iterando meu vetor de vetores A 
        p = G->A[i]; //Escolhendo o vetor atual para iterar
        while(p != NULL){ //Enquanto o nó atual não for igual a NULL
            G->A[i] = p; //O nó atual vai receber p (sem valor)
            p = p->prox; //O ponteiro p vai receber o próximo nó
            free(G->A[i]); //Iremos liberar o espaço que o nó atual ocupa
        }

        G->A[i] = NULL; //O vetor atual vai ser nulo
    }

    //Vetores do vetor A totalmente liberado

    free(G->A); //Liberando o espaço de memória que o Vetor A ocupa
    G->A = NULL;

    free(G); //Liberando o espaço de memória que o grafo ocupa
}

void imprimirGrafo(Grafo G) {
    printf("Grafo com %d nos e %d arestas:\n", G->n, G->a);

    for (int i = 0; i < G->n; i++) {
        printf("Vertice %d: ", i);

        Noh *p = G->A[i]; // Aponta para a lista de adjacência do vértice i
        while (p != NULL) {
            printf("%d -> ", p->rotulo);
            p = p->prox; // Avança para o próximo nó
        }

        printf("NULL\n"); // Fim da lista de adjacência do vértice
    }
}

int main(){
    
    Grafo G = inicializarGrafo(5); // Criando um grafo com 5 vértices

    inserirAresta(G, 0, 1);
    inserirAresta(G, 0, 4);
    inserirAresta(G, 1, 2);
    inserirAresta(G, 1, 3);
    inserirAresta(G, 1, 4);
    inserirAresta(G, 3, 4);

    imprimirGrafo(G); // Imprime o grafo

    dfs(G,0);

    return 0;
}
