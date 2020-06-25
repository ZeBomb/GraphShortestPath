#pragma once
struct ELEMENT {
	int node; // key only has a range from 0 to capacity
	int d; //distance from source
	int p; 
};

struct GRAPH {
	int v;
	int e;
	struct ELEMENT* H;
	struct LIST** A;
};

struct LIST {
	int neighbor; //where neighbor is the node adj.
	int weight;
	struct LIST* next;
};

struct QUEUE {
	int size;
	struct ELEMENT* Q;
};
GRAPH* initialize();
void readGraph(GRAPH* graph);
void writeGraph(GRAPH* graph);
void destroyGraph(GRAPH* graph);