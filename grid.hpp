#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid
{
public:
    Grid();
    Grid(int caseSize, int width, int height);
    ~Grid();

    int getNbLine();
    int getNbColumn();

    int getCaseSize();
    void setCaseSize();

    int get(int line, int column);
    void set(int line, int column, int data);

private:
    void createMatrix();

private:
    int m_caseSize;
    int m_width;
    int m_height;
    std::vector< std::vector<int> > m_matrix;
};

#endif // GRID_H
