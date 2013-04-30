#include "graph.h"

int Graph::WHITE = 1;
int Graph::GRAY = 2;
int Graph::BLACK = 3;
/**
 * Construtor da Classe
 */
Graph::Graph(int size){
	this->size = size;
	this->adjacencyMatrix = new double*[size];
	
	for(int i=0;i<size;i++){
		this->adjacencyMatrix[i] = new double[size];
	}
	
	init();
}

/**
 * Inicia os valores  da matriz para impedir que o programa
 * capture alguma sujeira na hora da execução
 */
void Graph::init(){
	if(adjacencyMatrix != NULL){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				adjacencyMatrix[i][j] = 0;
			}
		}
	}
}

/**
 * Destrutor da Classe
 */
Graph::~Graph(){
	for(int i=0;i<size;i++){
		delete adjacencyMatrix[i];
	}
	delete adjacencyMatrix;
}

/**
 * Imprime da tela a matriz de adjancencias
 */
void Graph::printMatrixToScreen(){
	if(adjacencyMatrix == NULL){
		Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
		return;
	}
	cout<<endl<<"\t";
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<adjacencyMatrix[i][j]<<" ";
		}
		cout<<endl<<"\t";
	}
	cout<<endl;
}

/**
 * Algoritmo de Busca em Profundidade DFS
 */
void Graph::depthFirstSearch(int vertex){
	//Validação necessária para que o usuario não digite um vertice que
	//não exista
	if(vertex <= 0 || vertex > size){
		Console::print("ERROR in DFS: vertex should be between 1 and "+String::convertIntToString(size));
		return;
	}
	//Será criado um vetor que guardará todos os requisitos que já foram visitados.
	int* color = new int[size];
	for(int i=0;i<size;i++){
		color[i] = WHITE;
	}
	
	cout<<endl<<"\t";
	dfs(vertex-1,color);
	cout<<endl<<endl;
}

/**
 * Algoritmo de Busca em Profundidade DFS
 */
void Graph::dfs(int position,int* color){
	cout<<position+1<<" ";
	color[position] = GRAY;
	//Percorre todos os elementos que estão na lista de vertices adjacentes ao vertice de entrada e 
	//que ainda não foram marcados ou selecionados.
	for(int j=0;j<size;j++){
		if(adjacencyMatrix[position][j] != 0){
			if(color[j] == WHITE){
				//Fazer chamada recursiva para chamar os elementos que ainda faltam ser percorridos
 				dfs(j,color);
			}
		}
	}
	color[position] = BLACK;
}

/**
 * Algoritmo de Busca em Largura BFS
 */
void Graph::breadthFirstSearch(int vertex){
	//Validação necessária para que o usuario não digite um vertice que
	//não exista
	if(vertex <= 0 || vertex > size){
		Console::print("ERROR in BFS: vertex should be between 1 and "+String::convertIntToString(size));
		return;
	}
	
	//Cria um vetor para marcar todos os vertices que foram visitados
	int* color = new int[size];
	for(int i=0;i<size;i++){
		color[i] = WHITE;
	}
	queue<int> q;
	q.push(vertex-1);
	color[vertex-1] = GRAY;
	
	cout<<endl<<"\t";
	while ( ! q.empty()){
		int v = q.front();
		q.pop();
		cout<<v+1<<" ";
		//Percorre todos os vertices adjacentes a V que ainda não foram marcados
		for(int j=0;j<size;j++){
			if(adjacencyMatrix[v][j] != 0){
				if(color[j] == WHITE){
					color[j] = GRAY;
					q.push(j);
				}
			}
		}
		color[v] = BLACK;
	}
	cout<<endl<<endl;
}

/**
 * Cria um novo objeto baseado nos dados do atual. Ao final do proceso, será criado um 
 * novo grafo idêntico nas Arestas e Vértices.
 */
Graph* Graph::clone(){
	Graph* g = new Graph(size);
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			g->adjacencyMatrix[i][j] = adjacencyMatrix[i][j];
		}
	}
	
	return g;
}


