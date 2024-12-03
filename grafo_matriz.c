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
    printf("Escolha o tipo do grafo (0 = Direcionado, 1 = Nao Direcionado) \n");
    scanf("%d", &t);
    return t;
}

//Função que pede o tamanho da matriz pro usuário
int grafo_tamanho(){
    int tamanho;
    printf("Escolha a quantidade de vertices (Nos) no grafo:\n ");
    scanf("%d", &tamanho);
    return tamanho;
}

//No caso de representação de um grafo direcionado:
//Função que pede os vértices existentes no grafo (Onde há relação entre dois nós através de uma aresta)
//Essa função colocará o valor de 1 na posição que os vértices estão na matriz binária
void grafo_inserirv_direcionado(int tamanho){
    int loop, choice = 1;
    while(loop){

        loop = 0;
        int vertice1, vertice2;
        printf("Digite um vertice de origem entre 0 e %i \n", tamanho-1 );
        scanf("%i" , &vertice1);
        printf("Digite um vertice de destino entre 0 e %i \n", tamanho-1);
        scanf("%i", &vertice2);
        
        if (vertice1>tamanho-1 || vertice2>tamanho-1 || vertice1<0 || vertice2<0){
            printf("Valor invalido \n");
        }else{
            m[vertice1][vertice2] = 1;
        }

        printf("Aresta adicionada. Deseja colocar outra? (1 - Sim, 0 - Nao) \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
            loop = 1;
            break;
        default:
            printf("Valor inválido, programa terminando\n");
            break;
        }
    }
}

//No caso da escolha de representação de um grafo não direcionado:
void grafo_inserirv_ndirecionado(int tamanho){
    int loop, choice = 1;
    while(loop){

        loop = 0;
        int vertice1, vertice2;
        printf("Digite o vertice de extremidade da aresta entre 0 e %i \n", tamanho-1 );
        scanf("%i" , &vertice1);
        printf("Digite o outro vertice de extremidade da aresta entre 0 e %i \n", tamanho-1);
        scanf("%i", &vertice2);
        
        if (vertice1>tamanho-1 || vertice2>tamanho-1 || vertice1<0 || vertice2<0){
            printf("Valor invalido \n");
        }else{
            m[vertice2][vertice1] = 1;
            m[vertice1][vertice2] = 1;
        }

        printf("Aresta adicionada. Deseja colocar outra? (1 - Sim, 0 - Nao) \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
            loop = 1;
            break;
        default:
            printf("Valor invalido, programa terminando\n");
            break;
        }
    }

}

void print_matriz(int t){

    printf("\n");

    for (int i=0; i<t; i++){
        for (int j=0; j<t; j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}


int main(){

    int tg = tipo_do_grafo();
    int t;

    switch (tg)
    {
    case 0:
        t = grafo_tamanho();
        grafo_inserirv_direcionado(t);
        print_matriz(t);
        break;
    case 1:
        t = grafo_tamanho();
        grafo_inserirv_ndirecionado(t);
        print_matriz(t);
        break;

    default:
        printf("Valor invalido. Tente novamente. \n");
        break;
    }

    return 0;
}
