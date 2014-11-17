/*
 * Graph.cpp
 *
 *  Created on: 17 nov. 2014
 *      Author: Julien Vanbergen
 */

#include "Graph.hpp"


Graph::Graph() {
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::addEdge(Edge* a){
	m_vectorEdge.push_back(a);
}

std::vector<Edge*> Graph::getEdgeVector(){
	return m_vectorEdge;
}

void Graph::addEdge(std::string a, std::string b){
	Vertex* y = new Vertex();
	y->setName(a);
	Vertex* z = new Vertex();
	z->setName(b);
	Edge* u = new Edge(y,z);
	this->addEdge(u);
	u->display();
}


