/*****************************************
 ** File:    Graph.cpp
 ** Project: CMSC 481 Programming assignment 1, Spring 2015
 ** Authoer: Jin Hui Xu
 ** Date:    04/30/2015
 ** E-mail:  ac39537@umbc.edu
 **
 **    This file contains the source code of Graph class for Programming assignment 1.
 ** his program contains implementations of methods and member functions
 ** for Graph class.
 **
 *****************************************/

#include "Graph.h"
#include<sstream>

#define INFINITY 999


//initializer list
Graph::Graph(){}


//Graph
//read the input file to create the certain weighted undirected graph using adjacency matrix representation
Graph::Graph(string filename)
{
	char ch;
	string str;
	int temp = 0;
	string line;

	//initialize the adjacency matrix
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			adjacencyMatrix[i][j] = -1;

	ifstream infile;
	infile.open(filename.c_str(), ios_base::in);

	//check if the file is open
	if(infile.is_open())
	{
		//read the node number and total edge number for graph
		while(getline(infile, line))
		{	
			//count how many line in the file
			edgeNum ++;	
		}
		edgeNum = edgeNum - 2; //the last two lines are source and destination, so we substract them

		infile.clear(); 		// forget we hit the end of file 
		infile.seekg(0, ios::beg);	// move to the start of the file 
		
		while(getline(infile, line))
		{
			istringstream iss(line);
			while(iss >> sourceIndex >> ch >> destinationIndex >> ch >> weight)
			{	
				//the maximum value of node in the file is the total number of node in the graph
				if(sourceIndex > destinationIndex)
					nodeNum = sourceIndex;
				else
					nodeNum = destinationIndex;
			
			}	
		}

		infile.clear(); 		// forget we hit the end of file 
		infile.seekg(0, ios::beg);	// move to the start of the file 

		//set up the vertex number for adjacency matrix and 
		//set the distance between any city and itself to 0
		for(int i = 0; i < nodeNum - 1; i++)
			adjacencyMatrix[i][i] = 0;

		while(edgeNum > 0)
		{
			//add the certain edge to the adjacency matrix with weight
			infile >> sourceIndex >> ch >> destinationIndex >> ch >> weight;
			adjacencyMatrix[sourceIndex - 1][destinationIndex - 1] = weight;
			adjacencyMatrix[destinationIndex - 1][sourceIndex - 1] = weight;

			//decrease the edge number by 1 after added an edge to matrix
			edgeNum --;
		}
		
		infile >> str;
		//ignore the string and get the source node index
		for(unsigned int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 48 && str[i] <= 57)  
				temp = str[i] - 48;  // Store it in temp string.
		}
		source = temp;
		source -= 1;

		infile >> str;
		//ignore the string and get the destination node index
		for(unsigned int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 48 && str[i] <= 57)  
				temp = str[i] - 48;  // Store it in temp string.
		}
		destination = temp;
		destination -= 1;
		
	}

	//if the file is not open, exit the program
	else 
	{
		cout << "input files not found." << endl;
		exit(1);
	}
	infile.close();
}


//shortestDistance
//return the shortest distance for every two nodes 
int Graph::shortestDistance()
{

	int minDistance = INFINITY;
	int closestUnmarkedNode;
	for(int i = 0; i < nodeNum; i++) 
	{
		if(mark[i] == false && minDistance >= distance[i]) 
		{
			minDistance = distance[i];
			closestUnmarkedNode = i;
        	}
    	}
    	return closestUnmarkedNode;
}
 

//dijkstra
//Dijkastra algorithm
void Graph::dijkstra()
{
	// Initialize all distances as INFINITE and marks as false
	for(int i = 0; i < nodeNum; i++) 
	{
       		mark[i] = false;
		distance[i] = INFINITY;
        	predecessor[i] = -1;
    	}
	// Distance of source from itself is 0
    	distance[source]= 0;

    	int closestUnmarkedNode;
    	for(int j = 0; j < nodeNum - 1; j++)
	{
		closestUnmarkedNode = shortestDistance();
		mark[closestUnmarkedNode] = true;
		for(int i = 0; i < nodeNum; i++)
		{
			if(mark[i] == false && adjacencyMatrix[closestUnmarkedNode][i] > 0 &&
				distance[closestUnmarkedNode] + adjacencyMatrix[closestUnmarkedNode][i] < distance[i])
			{
				distance[i] = distance[closestUnmarkedNode] + adjacencyMatrix[closestUnmarkedNode][i];
				predecessor[i] = closestUnmarkedNode;
			}
		}
	}
}
 

//printPath
//print out the travesal path between source and destination 
void Graph::printPath(int node, ostream & out = cout)
{
	if(node == source)
	{
        	out << node + 1;
	}
    	else if(predecessor[node] == -1)
		out << "No path from source to " << node + 1 << endl;
    	else 
	{
        	printPath(predecessor[node], out);
		out << "->" << node + 1;
    	}
}


//nextHop
//find the next hop node and return an integer value
int Graph::nextHop(int node)
{

	int i = 0;
	int array[MAX] = {};

	while(predecessor[node] != -1)
	{
		array[i] = node;
		node = predecessor[node];
		i += 1;
	}

	if(array[0] == NULL)
		return -1;
	else
		return array[i - 1] + 1;
}


//result
//print out the result
void Graph::result(ostream & out = cout)
{
	string path;
	out << "-------------------------- (beginning of summary)" << endl;
	out << "Source " << source + 1 << " -> Destination " << destination + 1 << endl;
	if(destination == source)
		out << source+1 << "->" << source+1 << endl;
	else
	{
		out << "Traversal ";
		printPath(destination, out);
		out << endl;
	}
	out<<"Total Distance: "<< distance[destination] << endl;
}


//routeTable
//print out the routing table
void Graph::routeTable(ostream & out = cout)
{

	out << "-------------------------- (end of summary and separation)" << endl;
	for(int i = 0; i < nodeNum; i++) 
	{
		out << "Routing table of node " << i + 1 << endl;
		out << "To\tNext Hop\tDistance\tTraversal" << endl;
		out << i + 1 << "\t" << nextHop(i) << "\t\t" << distance[i] << "\t\t";
		printPath(i, out);
		out << endl << endl;
	}
	
}


//runDijkstra
//Run the Dijkastra algorithm simulation for the graph
void Graph::runDijkstra()
{
	ofstream outfile;
	string output = "output.txt";
	dijkstra();
	outfile.open(output.c_str(), ios_base::in);
	if (outfile.is_open())
	{
		result(outfile);
		routeTable(outfile);
	}
	else
	{
		cout << "output files not found." << endl;
		exit(1);
	}
	
	outfile.close();
	cout << "Output file is generated successfully." << endl;
}
