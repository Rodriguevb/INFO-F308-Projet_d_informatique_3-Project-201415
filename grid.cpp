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
    m_matrix.clear();
    int nbLine = getNbLine();
    int nbColumn = getNbColumn();

    for(int l = 0; l < nbLine; ++l) {
        std::vector<GridCase> line;
        for(int c = 0; c < nbColumn; ++c) {
            line.push_back(GridCase());
        }
        m_matrix.push_back(line);
    }
}

int Grid::getNbColumn() {
    int cols = m_width / m_caseSize;
    return (m_width % m_caseSize == 0) ? cols : cols+1;
}

int Grid::getNbLine() {
    int lines = m_height / m_caseSize;
    return (m_height % m_caseSize == 0) ? lines : lines+1;
}

bool Grid::caseExist(int line, int column) {
    bool result = (line >= 0) && (column >= 0);
    result = result && ( (line < m_matrix.size()) && (column < m_matrix.at(0).size()) );
    return result;
}

bool Grid::getLighted(int line, int column) {
    return m_matrix.at(line).at(column).isLighted();
}

void Grid::setLighted(int line, int column, bool lighted) {
    m_matrix[line][column].setLighted(lighted);
}

bool Grid::getFree(int line, int column) {
    return m_matrix.at(line).at(column).isFree();
}

void Grid::setFree(int line, int column, bool free) {
    m_matrix[line][column].setFree(free);
}

int Grid::getHeight() {
    return m_height;
}

int Grid::getWidth() {
    return m_width;
}

int Grid::getCaseSize() {
    return m_caseSize;
}

int Grid::xToColumn(int x) {
    return (x / m_caseSize);
}

int Grid::yToLine(int y) {
    return (y / m_caseSize);
}
