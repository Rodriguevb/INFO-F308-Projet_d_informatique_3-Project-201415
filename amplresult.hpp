#ifndef AMPLRESULT_H
#define AMPLRESULT_H

#include <vector>
#include "ampllight.hpp"

class AmplResult
{
private:
    std::vector<AmplLight> _lights;
    std::vector< std::vector<float> > _s;
public:
    AmplResult();
    ~AmplResult();

    void addLight(int x, int y, int p);
    void addLight(AmplLight light);
    void addMatrixLine(std::vector<float> Line);

    int getNbLight();
    AmplLight getLight(int index);
    int getNbLine();
    int getNbColumn();

    float getS(int line, int col);

};

#endif // AMPLRESULT_H
