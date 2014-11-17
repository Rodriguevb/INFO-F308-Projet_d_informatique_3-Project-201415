/*
 * Edge.cpp
 *
 *  Created on: 17 nov. 2014
 *      Author: julien
 */

#include "Edge.hpp"
#include "Vertex.hpp"

Edge::Edge(){

}

Edge::Edge(Vertex* a, Vertex* b) {
	setStart(a);
	setEnd(b);
}

Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

Vertex* Edge::getStart(){
	return m_start;
}

void Edge::setStart(Vertex* a){
	m_start=a;
}

Vertex* Edge::getEnd(){
	return m_end;
}

void Edge::setEnd(Vertex* a){
	m_end=a;
}

void Edge::display(){
	std::cout<<"Edge from "<< m_start->getName() <<" to " << m_end->getName()<<std::endl;;
}

std::ostream& operator<<(std::ostream &os,const Edge & edge){
    //Affichage des attributs

	//os << edge.display();
    return os;
}
