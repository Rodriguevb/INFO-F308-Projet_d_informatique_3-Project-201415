/*
 * Edge.hpp
 *
 *  Created on: 17 nov. 2014
 *      Author: julien
 */
#include "Vertex.hpp"

#ifndef EDGE_HPP_
#define EDGE_HPP_

class Edge { //ARRETE
public:
	Edge();
	Edge(Vertex* a, Vertex* b);

	virtual ~Edge();

	Vertex* getStart();
	void setStart(Vertex* a);
	Vertex* getEnd();
	void setEnd(Vertex* a);
	void display();


	friend std::ostream& operator<<(std::ostream &os, const Edge &edge);

private:
	Vertex* m_start;
	Vertex* m_end;

};



#endif /* EDGE_HPP_ */
