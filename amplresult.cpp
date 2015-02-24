#include "amplresult.hpp"

AmplResult::AmplResult() :
    _lights(),
    _s()
{

}

AmplResult::~AmplResult()
{

}

void AmplResult::addLight(AmplLight light) {
    _lights.push_back(light);
}

void AmplResult::addLight(int x, int y, int p) {
    addLight(AmplLight(x,y,p));
}

void AmplResult::addMatrixLine(std::vector<float> line) {
    _s.push_back(line);
}

int AmplResult::getNbLight() {
    return _lights.size();
}

AmplLight AmplResult::getLight(int index) {
    return _lights[index];
}

int AmplResult::getNbLine() {
    return _s.size();
}

int AmplResult::getNbColumn() {
    if ( getNbLine() >= 1 ) {
        return _s.at(0).size();
    } else {
        return 0;
    }
}

float AmplResult::getS(int line, int col)  {
    return _s.at(line).at(col);
}

