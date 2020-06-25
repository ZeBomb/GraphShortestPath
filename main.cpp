#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "main.h"
#include "util.h"
#include "heap.h"
#include "graph.h"

using namespace std;

int main() {
	int s, t, iFlag;
	char c;
	GRAPH* graph = NULL;
	int madeGraph = 0;
	int haveRead = 0;
	while (1) {
		c = nextCommand(&s, &t, &iFlag);

		switch (c) {
		case 's':
		case 'S': printf("COMMAND: %c\n", c); exit(0);

		case 'r':
		case 'R':
			cout << "COMMAND: " << c << "\n";
			if (madeGraph == 1) {
				//cout << "Error graph already initilaized\n"; break;
				destroyGraph(graph);
				graph = NULL;
				graph = initialize();
				readGraph(graph);
			}
			else {
				graph = initialize();
				readGraph(graph);
				madeGraph = 1;
			}
			break;

		case 'w':
		case 'W':
			cout << "COMMAND: " << c << "\n";
			if (madeGraph == 0) {
				cout << "Error: graph not initialized\n"; break;
			}
			else {
				
				writeGraph(graph);
				madeGraph = 1;
			}
			break;

		case 'f':
		case 'F':
			cout << "COMMAND: " << c << " " << s << " " << t << " " << iFlag << "\n";
			if (madeGraph == 0) {
				cout << "Error: graph not initialized\n";
			}
			else {
				int check1 = checkNodes(*graph, s, t);
				int check2 = checkFlag(iFlag);
				if (check1 == 1 || check2 == 1) {
					break;
				}
				shortestPath(graph, s, t, iFlag);
			}
			break;

		default: break;
		}
	}
	exit(0);
}