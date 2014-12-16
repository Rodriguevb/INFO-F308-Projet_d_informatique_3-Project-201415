#ifndef GRID_H
#define GRID_H

#include <vector>
#include "gridcase.hpp"

class Grid
{
public:
    Grid();
    Grid(int caseSize, int width, int height);
    ~Grid();

    int getNbLine();
    int getNbColumn();
    bool caseExist(int line, int column);

    int getCaseSize();
    void setCaseSize();

    int getWidth();
    int getHeight();

    bool getLighted(int line, int column);
    void setLighted(int line, int column, bool lighted);

    bool getFree(int line, int column);
    void setFree(int line, int column, bool free);

    int xToColumn(int x);
    int yToLine(int x);

private:
    void createMatrix();

private:
    int m_caseSize;
    int m_width;
    int m_height;
    std::vector< std::vector<GridCase> > m_matrix;
};

#endif // GRID_H
