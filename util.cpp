#include <iostream>
#include <fstream>
#include <limits>

#include "main.h"
#include "util.h"
#include "heap.h"
#include "graph.h"

using namespace std;

int nextCommand(int* s, int* t, int* iFlag) {
	char c;
	while (1) {
		//cout << "\nInput Command: ";
		cin >> c;
		cin.ignore(1);
		//Command is empty space, tab, or newline
		if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		//Command S, R, or W
		if (c == 'S' || c == 'R' || c == 'W') {
			break;
		}
		if (c == 's' || c == 'r' || c == 'w') {
			break;
		}
		if (c == 'F' || c == 'f') {
			readV(s);
			readV(t);
			readFlag(iFlag);
			break;
		}
	}
	
	
	
	
	return c;
}
/*******************************************
Helper functions:

These funtions read in integers and catch bad inputs
*******************************************/
/*reads in integers represetning vertices on the graph,
will use checker to make sure nodes are in range*/
void readV(int* v) {
	cin >> *v;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nThis is not an integer, please enter an integer: " << endl;
	}
}

/*reads in flag value, will later check flag value*/
void readFlag(int* iFlag) {
	cin >> *iFlag;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nThis is not an integer, please enter an integer: " << endl;
	}
}

/**********************************************/

void readFile(GRAPH* graph) { 
	int v1, e1;
	ifstream file;
	file.open("Ginput.txt");
	if (!file) {
		cout << "Error: Can't open Ginput.txt, exiting program \n";
		exit(1);
	}
	file >> v1; // number of vertecies
	file >> e1; // number of edges
	graph->v = v1;
	graph->e = e1;
	graph->H = new ELEMENT[v1 + 1];
	graph->A = new LIST * [v1 + 1];
	for (int i = 1; i <= v1; i++) {
		graph->A[i] = NULL;
	//	graph->SAVED = NULL;
	}
	
	int u, v, w;
	while (file >> u >> v >> w) {
		LIST* temp = new LIST;
		temp->neighbor = v;
		temp->weight = w;
		temp->next = NULL;
		if (graph->A[u] == NULL) {
			graph->A[u] = temp;
	//		graph->SAVED[u] = temp;
		}
		else {
			temp->next = graph->A[u];
			graph->A[u] = temp;
	//		graph->SAVED[u] = temp;
		}
	}
	
	file.close();
	/*if (checkSize(*heap, n) == 0) {
		buildHeap(heap, A, n);
	}*/

} 
int checkNodes(GRAPH graph, int s, int t) {
	int n = graph.v;
	if (s < 1 || t < 1 || s > n || t > n) {
		cout << "Error: one or more invalid nodes\n";
		return 1;
	}
	else
		return 0;
}
int checkFlag(int iFlag) {
	if (iFlag < 0 || iFlag > 1) {
		cout << "Error: invalid flag value\n";
		return 1;
	}
	else
		return 0;
}