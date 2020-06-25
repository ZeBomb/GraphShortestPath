#include "main.h"
#include "util.h"
#include "heap.h"
#include "graph.h"

#include <iostream>
using namespace std;

GRAPH* initialize() {
	//GRAPH* graph = NULL;
	GRAPH *graph = new GRAPH;
	graph->v = 0;
	graph->e = 0;
	
	return graph;
}

void readGraph(GRAPH* graph) {
	readFile(graph);
	for (int i = 1; i <= graph->v; i++) {
		graph->H[i].node = i;
		graph->H[i].d = 10000;
		graph->H[i].p = -1;
	}
 }
void writeGraph(GRAPH* graph) {
	cout << graph->v << " " << graph->e << "\n";
	for (int i = 1; i <= graph->v; i++) {//iterates through each vertex
		
		cout << i << " : ";
		if (graph->A[i] != NULL) {
			struct LIST* SAVED = graph->A[i];// Saves original list start
			cout << "(" << graph->A[i]->neighbor << ", " << graph->A[i]->weight << ")";
			while (graph->A[i]->next != 0) {
				graph->A[i] = graph->A[i]->next;
				cout << "; (" << graph->A[i]->neighbor << ", " << graph->A[i]->weight << ")";
			}
			graph->A[i] = SAVED; //This resets the pointer
		}
		cout << "\n";
	}
}
void destroyGraph(GRAPH* graph) {
	
	if (graph != NULL) {
		
		delete[] graph->H;
		delete[] graph->A;
		delete graph;
	}
}