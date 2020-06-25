#pragma once
#include "main.h"
#include "util.h"
#include "heap.h"
#include "graph.h"

int nextCommand(int* s, int* t, int* iFlag);
void readV(int* v);
void readFlag(int* iFlag);
void readFile(GRAPH* graph);
int checkNodes(GRAPH graph, int s, int t);
int checkFlag(int iFlag);