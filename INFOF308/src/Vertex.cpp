/*
 * Vertex.cpp
 *
 *  Created on: 17 nov. 2014
 *      Author: julien
 */

#include "Vertex.hpp"

Vertex::Vertex() {
	// TODO Auto-generated constructor stub

}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

void Vertex::setName(std::string name){
	m_name=name;
}

std::string Vertex::getName(){
	return m_name;
}
