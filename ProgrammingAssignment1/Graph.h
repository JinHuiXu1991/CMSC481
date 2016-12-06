/*****************************************
 ** File:    Graph.h
 ** Project: CMSC 481 Programming assignment 1, Spring 2015
 ** Authoer: Jin Hui Xu
 ** Date:    04/30/2015
 ** E-mail:  ac39537@umbc.edu
 **
 **    This file contains the header and the source code of Graph class for Programming assignment 1.
 ** This program contains the headers and implementations of methods and member functions
 ** for Graph class.
 *****************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <cstdlib>
using namespace std;

class Graph
{
	public:
		//implementation of constructors
		Graph();
		Graph(string filename);

		//-------------------------------------------------------
		// Name: shortestDistance
		// PreCondition:  none
		// PostCondition: return the shortest distance for every two nodes 
		//---------------------------------------------------------
		int shortestDistance();

		//-------------------------------------------------------
		// Name: dijkstra
		// PreCondition:  none
		// PostCondition: Dijkastra algorithm
		//---------------------------------------------------------
		void dijkstra();

		//-------------------------------------------------------
		// Name: printPath
		// PreCondition:  none
		// PostCondition: print out the travesal path between source and destination
		//---------------------------------------------------------
		void printPath(int, ostream &);

		//-------------------------------------------------------
		// Name: nextHop
		// PreCondition:  none
		// PostCondition: find the next hop node and return an integer value
		//---------------------------------------------------------
		int nextHop(int);
		
		//-------------------------------------------------------
		// Name: result
		// PreCondition:  none
		// PostCondition: print out the result
		//---------------------------------------------------------
		void result(ostream &);

		//-------------------------------------------------------
		// Name: routeTable
		// PreCondition:  none
		// PostCondition: print out the routing table
		//---------------------------------------------------------
		void routeTable(ostream &);

		//-------------------------------------------------------
		// Name: runDijkstra
		// PreCondition:  none
		// PostCondition: Run the Dijkastra algorithm simulation for the graph
		//---------------------------------------------------------
		void runDijkstra();

	private:
		static const int MAX = 999;     //adjacency matrix size
		int nodeNum;                    //total number of nodes
		int edgeNum;                    //total number of edges
		int adjacencyMatrix[MAX][MAX];  //adjacency matrix representation for weighted undirected graph
		int predecessor[MAX];           //predecssor of node in the path
		int distance[MAX];              //distance between nodes
		bool mark[MAX];                 //use for dijkstra algorithm
		int sourceIndex;		//source index 
		int destinationIndex;		//destination index
		int weight;                     //cost of link between two nodes
		int source;                     //source node
		int destination;                //destination node
		
		
};

#endif
