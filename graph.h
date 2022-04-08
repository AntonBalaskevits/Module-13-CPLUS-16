#pragma once
#include <string>

#define SIZE 10

class Graph
{
public:
	Graph();
	
	void addVertexName(int vnumber, const std::string& name);
	void addEdge(int v1, int v2);
	void addBondByName(const std::string& name1, const std::string& name2);
	bool vertexExists(int v);
	bool edgeExists(int v1, int v2);
	void checkBonds();
private:
	int matrix_[SIZE][SIZE];

	int vertexes_[SIZE];
	int vertexCount_ = 0;

	std::string name_[SIZE]; // array for names
	char name_shelf_[SIZE][SIZE]; // matrix for names 
};
