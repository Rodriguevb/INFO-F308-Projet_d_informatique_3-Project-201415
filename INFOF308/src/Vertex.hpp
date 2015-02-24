/*
 * Vertex.hpp
 *
 *  Created on: 17 nov. 2014
 *      Author: julien
 */

#include <string>

#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include <iostream>
class Vertex { //SOMMET
public:
	Vertex();
	virtual ~Vertex();
	void setName(std::string name);
	std::string getName();

private:
	std::string m_name;
};

#endif /* VERTEX_HPP_ */
