#include "grid.hpp"

Grid::Grid() : m_caseSize(32), m_width(800), m_height(600), m_matrix()
{
    createMatrix();
}

Grid::Grid(int caseSize, int width, int height) :
    m_caseSize(caseSize),
    m_width(width),
    m_height(height),
    m_matrix()
{
    createMatrix();
}

Grid::~Grid()
{

}

void Grid::createMatrix() {
    int nbLine = getNbLine();
    int nbColumn = getNbColumn();

    for(int l = 0; l < nbLine; ++l) {
        std::vector<int> line;
        for(int c = 0; c < nbColumn; ++c) {
            line.push_back(0);
        }
        m_matrix.push_back(line);
    }
}

int Grid::getNbColumn() {
    return m_width / m_caseSize;
}

int Grid::getNbLine() {
    return m_height / m_caseSize;
}

int Grid::get(int line, int column) {
    return m_matrix.at(line).at(column);
}

void Grid::set(int line, int column, int data) {
    m_matrix[line][column] = data;
}


