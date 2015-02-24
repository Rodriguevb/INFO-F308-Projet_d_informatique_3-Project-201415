/*
 * Graph.hpp
 *
 *  Created on: 17 nov. 2014
 *      Author: Julien Vanbergen
 */
#include <vector>
#include "Edge.hpp"
#include <iostream>

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

class Graph {
public:
	Graph();
	virtual ~Graph();

	void addEdge(std::string a, std::string b);

	void addEdge(Edge* a);
	std::vector<Edge*> getEdgeVector();

private:
	std::vector<Edge*> m_vectorEdge;
};

#endif /* GRAPH_HPP_ */
