#include <iostream>
#include "graph.h"

Graph::Graph()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix_[i][j] = 0;
	vertexCount_ = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			name_shelf_[i][j] = '_';
		}
	}
}

void Graph::addVertexName(int vnumber, const std::string& name)
{
	vertexes_[vertexCount_++] = vnumber;
	name_[vnumber] = name; // array of names

	for (int i = 0; i < name_[vnumber].size(); i++)
	{
		name_shelf_[vnumber][i] = name_[vnumber].at(i); 
	}
}

void Graph::addEdge(int v1, int v2)
{
	matrix_[v1][v2] = 1;
	matrix_[v2][v1] = 1;
}

void Graph::addBondByName(const std::string& name1, const std::string& name2)
{
	int check_name1 = 0; // counter
	int check_name2 = 0; // 
	int v_number = 0; // index that should correspond with vertex where name1 is
	int v_number2 = 0; // index that should correspond with vertex where name2 is


	// algorithm to find vertices number by input name
	for (int i = 0; i < vertexCount_; i++)
	{
		for (int j = 0; j < name1.size(); j++)
		{
			if (name_shelf_[i][j] == name1[j]) // comparing each symbol
			{                                  // if true counter increments by one
				check_name1++;
			}
		}
		if (check_name1 == name1.size()) // after for loop is done checks if counter is equal whit size
		{                                // if true vertex index is found. algorithm breaks
			v_number = i;
			break;
		}
		else
		{
			check_name1 = 0;
		}
	}
	for (int i = 0; i < vertexCount_; i++)
	{
		for (int j = 0; j < name2.size(); j++)
		{
			if (name_shelf_[i][j] == name2[j])
			{
				check_name2++;
			}
		}
		if (check_name2 == name2.size())
		{
			v_number2 = i;
			break;
		}
		else
		{
			check_name2 = 0;
		}
	}
	if (vertexExists(v_number) && vertexExists(v_number2)) // checks if bought vertices are exists
	{
		Graph::addEdge(v_number, v_number2);
	}
}

bool Graph::vertexExists(int v)
{
	for (int i = 0; i < vertexCount_; i++)
	{
		if (vertexes_[i] == v)
		{
			return true;
		}
	}
	return false;
}

bool Graph::edgeExists(int v1, int v2)
{
	return matrix_[v1][v2] > 0;
}

void Graph::checkBonds() // cout all edges between friends
{
	for (int i = 0; i < vertexCount_; i++)
	{
		if (vertexExists(i)) // 1 step, check if vertex exists
		{
			std::cout << name_[i] << " friends whit -> ";

			for (int j = 0; j < vertexCount_; j++)
			{
				if (edgeExists(i, j)) // 2 step, check if edge exists
				{
					if (j == i) // 3 step, check to avoid main name being displayed twice
					{
						continue;
					}
					else
					{
						std::cout << name_[j] << "-> ";
					}
				}
				if (vertexCount_ - 1 == j) // if its final vertex, puts dot at the end of friend name
				{
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "there is no vertex exists with corresponding index : " << i << std::endl;
		}
	}
}
