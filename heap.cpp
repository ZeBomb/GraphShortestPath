
#include "main.h"
#include "util.h"
#include "heap.h"
#include "graph.h"
#include <iostream>
using namespace std;

int shortestPath(GRAPH *graph2, int start, int end, int iFlag) {
	QUEUE* queue = NULL;
	queue = initilizeQueue(graph2, start);
	dijkstra(graph2, iFlag, start, queue);
	QUEUE set = *queue; 
	//printGraphQ(*graph2);
	//printQueue(set);
	sortSet(&set);
	//printQueue(set);
	if (set.Q[end].d >= 1000) {
		cout << "Error: node " << end << " not reachable from node " << start << "\n";
	}
	else {
		if (iFlag == 1) {
			cout << "LENGTH: " << set.Q[end].d << "\n";
		}
		else {
			printPath(set, start, end);
		}
	}
	destroy(queue);
	return 1;
}
void printGraphQ(GRAPH graph2) {
	for (int i = 1; i <= graph2.v; i++) {
		cout << graph2.H[i].node << " " << graph2.H[i].d << " ";
		cout << graph2.H[i].p << "\n";
	}
}
void dijkstra(GRAPH *graph2, int iFlag, int start, QUEUE* queue) { 
	int w = 0;
	//initilizeSource(graph2, start);
	//QUEUE queue = initilizeQueue(graph2, start);
	//sortQueue(&queue);
	//printQueue(queue);
	int intialSize = queue->size;
	while (queue->size != 0) {
		sortQueue(queue);
		ELEMENT u = extractMin(queue);
		//for each vetex in adj list to u
		if (graph2->A[u.node] != NULL) {
			struct LIST* SAVED = graph2->A[u.node];
			int cont = 1;
			while (cont == 1) {
				int v = findElement(*queue, graph2->A[u.node]->neighbor);
				if (v != -1) {//v has not already been popped from the queue
					//ELEMENT vE = queue.Q[v];
					w = graph2->A[u.node]->weight;
					relax(queue, u, v, w);
				}

				if (graph2->A[u.node]->next == 0) { cont = 0; }
				else { graph2->A[u.node] = graph2->A[u.node]->next; }
			}
			graph2->A[u.node] = SAVED; //resets graph2 pointer
		}
	}
	queue->size = intialSize;
}
void relax(QUEUE * queue, ELEMENT u, int v, int w) {
	if (queue->Q[v].d > u.d + w) {
		queue->Q[v].d = u.d + w;
		queue->Q[v].p = u.node;
	}
}
int findElement(QUEUE queue, int listInx) { //where it returns its index in the queue
	int i = 1;
	int found = 0;
	while (found == 0 && i <= queue.size) {
		if (queue.Q[i].node == listInx) {
			found = 1;
		}
		else {
			i++;
		}
	}
	if (found == 0) {
		//cout << "Error can't find node";'
		i = -1;
	}
	return i;
}
void printQueue(QUEUE queue) {
	cout << "Queue: \n";
	for (int i = 1; i <= queue.size; i++) {
		cout << i << ": node " << queue.Q[i].node << " distance " << queue.Q[i].d;
		cout << " parent " << queue.Q[i].p << "\n";
	}

}
QUEUE* initilizeQueue(GRAPH* graph2, int start) {
	QUEUE* queue = new QUEUE;
	queue->size = graph2->v;
	queue->Q = new ELEMENT[queue->size + 1];
	//queue->Q[queue->size + 1];
	for (int i = 1; i <= queue->size; i++) {
		queue->Q[i] = graph2->H[i];
	} 
	queue->Q[start].d = 0;
	queue->Q[start].p = start;
	//swap to put start at top of queue
	//ELEMENT temp = queue->Q[start];
	//queue->Q[start] = queue->Q[1];
	//queue->Q[1] = temp;
	return queue;
}
void sortQueue(QUEUE* queue) {
	//printQueue(*queue);
	int length = queue->size / 2;
	for (int i = length; i >= 1; i--) {
		minHeap(queue, i);
	}
}
void minHeap(QUEUE* queue, int i) {
	int smallest = i;
	int l = 2 * i;
	int r = 2 * i + 1;
	if (l <= queue->size && queue->Q[l].d < queue->Q[i].d) {
		smallest = l;
	}
	if (r <= queue->size && queue->Q[r].d < queue->Q[smallest].d) {
		smallest = r;
	}
	if (smallest != i) {
		ELEMENT temp = queue->Q[i];
		queue->Q[i] = queue->Q[smallest];
		queue->Q[smallest] = temp;
		minHeap(queue, smallest);
	}
}
void swap(QUEUE* set, int node1, int node2) {
	ELEMENT temp = set->Q[node1];
	set->Q[node1] = set->Q[node2];
	set->Q[node2] = temp;
}
void initilizeSource(GRAPH* graph2, int start) {
	

}

void sortSet(QUEUE* set) {
	int i, j;
	for (i = 1; i <= set->size; i++) {
		for (j = 1; j <= set->size - i; j++) {
			if (set->Q[j].node > set->Q[j + 1].node) {
				swap(set, j,  j + 1);
			}
		}
	}
}
void printPath(QUEUE set, int start, int end) {
	int end1 = end; //saves the begining end value
	QUEUE set2 = set;
	int n = 1;
	while (start != end) {
		if (set.Q[end].p == -1) {
			cout << "Error: node " << end1 << " not reachable from node " << start << "\n";
			start = end;
			n = -1;
		}
		else {
			set2.Q[n].node = end;
			end = set.Q[end].p;
			n++;
		}
	}
	if (n > 0) {
		cout << "PATH: " << start ;
		for (int i = n - 1; i >= 1; i--) {
			cout<< ", " << set2.Q[i].node;
		}
		cout << "\n";
	}
	
	
}

ELEMENT extractMin(QUEUE* queue) {
	ELEMENT min = queue->Q[1];
	queue->Q[1] = queue->Q[queue->size];
	queue->Q[queue->size] = min;
	queue->size = queue->size - 1;
	return min;
}

void destroy(QUEUE* queue) {
	/*if (queue->Q != NULL) {
		delete[] queue->Q;
	} */
	if (queue != NULL) {
		delete[] queue->Q;
		delete queue;
	} 
}
