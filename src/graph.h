#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <stack>

using namespace std;

class Graph {
	public:
		double** adjacencyMatrix;
		int size;
		
		Graph(int size);
		~Graph();
		void printMatrixToScreen();
		void depthFirstSearch(int position);
		Graph* clone();
	private:
		void dfs(int position,int* marked);
 };
 
 #endif /* GRAPH_H_ */