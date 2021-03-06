#include "dfs.h"

int DFS::WHITE = 1;
int DFS::GRAY = 2;
int DFS::BLACK = 3;

DFS::DFS(Graph* g){
	this->graph = g;
}

/*
 * Executa o algoritmo Busca em Profundidade DFS
 */
void DFS::run(int vertex){
	//Validação necessária para que o usuario não digite um vertice que
    //não exista
    if(vertex <= 0 || vertex > graph->size){
        Console::print("ERRO no DFS: vértices devem está entre 1 e "+Strings::convertIntToString(graph->size));
        return;
    }
    //Será criado um vetor que guardará todos os requisitos que já foram visitados.
    color = new int[graph->size];
    for(int i=0;i<graph->size;i++){
        color[i] = WHITE;
    }

    vector<int> answer;
    dfs(vertex-1,&answer);
    
    Console::print(answer);
}

/**
 * Algoritmo de Busca em Profundidade DFS
 */
void DFS::dfs(int position,vector<int> *answer){
    answer->push_back(position+1);
    color[position] = GRAY;
    
    //Percorre todos os elementos que estão na lista de vertices adjacentes ao vertice de entrada e
    //que ainda não foram marcados ou selecionados.
    for(int j=0;j<graph->size;j++){
        if(graph->adjacencyMatrix[position][j] != 0){
            if(color[j] == WHITE){
                //Fazer chamada recursiva para chamar os elementos que ainda faltam ser percorridos
                dfs(j,answer);
            }
        }
    }
    color[position] = BLACK;
}
