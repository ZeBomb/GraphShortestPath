#pragma once
#include "main.h"
#include "util.h"
#include "heap.h"
#include "graph.h"
int shortestPath(GRAPH *graph2, int start, int end, int iFlag);
void dijkstra(GRAPH* graph2, int iFlag, int start, QUEUE* queue);
void printPath(QUEUE set, int start, int end);
ELEMENT extractMin(QUEUE* queue);
void initilizeSource(GRAPH* graph2, int start);
QUEUE* initilizeQueue(GRAPH* graph2, int start);
void printQueue(QUEUE queue);
void sortQueue(QUEUE* queue);
void swap(QUEUE* set, int node1, int node2);
void minHeap(QUEUE* queue, int index);
void relax(QUEUE* queue, ELEMENT u, int v, int w);
int findElement(QUEUE queue, int listInx);
void printGraphQ(GRAPH graph2);
void sortSet(QUEUE* set);
void destroy(QUEUE* queue);
