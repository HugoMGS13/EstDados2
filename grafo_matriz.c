#include <stdio.h>
#include <stdlib.h>

//Criando um valor máximo da matriz
#define maximo 10

//Criando a variável que irá armazenar o tamanho da matriz
int tamanho = 0;

//Criando a matriz com o seu tamanho máximo
int m[maximo][maximo];

//Escolher o tipo de grafo
int tipo_do_grafo(){
    int t ;
    printf("Escolha o tipo do grafo (0 = Direcionado, 1 = Não Direcionado");
    scanf("%d", &t);
}

//Função que pede o tamanho da matriz pro usuário
int grafo_tamanho(){
    int tamanho;
    printf("Escolha a quantidade de vertices (Nos) no grafo:\n ");
    scanf("%d", &tamanho);
    return tamanho;
}

//Função que pede os vértices existentes no grafo (Onde há relação entre dois nós através de uma aresta)
//Essa função colocará o valor de 1 na posição que os vértices estão na matriz binária
void grafo_inserirv_direcionado(int tamanho){
    for(int i = 0; i < tamanho; i++){
        int vertice1, vertice2;
        printf("Digite o vértice de origem entre 0 e %i", tamanho-1 );
        scanf("%i" , vertice1);
        printf("Digite o vértice de destino entre 0 e %i", tamanho-1);
        scanf("%i", vertice2);
        
        if (vertice1>tamanho-1 || vertice2>tamanho-1 || vertice1<0 || vertice2<0){
            printf("Valor invalido, tente novamente.");
        }else{
            //m[vertice1][vertice2] = 1;
            m[vertice2][vertice1] = 1;
        }
    }

void grafo_inserirv_direcionado(int tamanho){
    int vertice1, vertice2;
    printf("Escolha o vertice de origem entre 0 e %d \n", tamanho-1);
    scanf("%d", &vertice1);
    printf("Escolha o vertice de destino entre 0 e %d \n", tamanho-1);
    scanf("%d", &vertice2);
    if (vertice1>tamanho-1 || vertice2>tamanho-1 || vertice1<0 || vertice2<0){
        printf("Valor invalido, tente novamente.");
    }else{
        m[vertice1][vertice2] = 1;
        m[vertice2][vertice1] = 1;
    }
}


int main(){

    int t = grafo_tamanho();
    grafo_inserirv_direcionado(t);

    //Printando a matriz
    for (int i=0; i<10 ; i++){
        for (int j=0; j<10; j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}
