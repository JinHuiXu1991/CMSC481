/*****************************************
 ** File:    Driver.cpp
 ** Project: CMSC 481 Programming assignment 1, Spring 2015
 ** Authoer: Jin Hui Xu
 ** Date:    04/30/2015
 ** E-mail:  ac39537@umbc.edu
 **
 **    This file contains the main driver program for Programming assignment 1 1.
 ** This program accept commond line arguments for the Graph Shortest Path project.
 **
 *****************************************/

#include "Graph.h"

int main(int argc, char *argv[])
{
	//read the command line argument and generate a graph
	string filename = argv[1];
	Graph mygraph(filename);
	mygraph.runDijkstra();
	return 0;

}
 
