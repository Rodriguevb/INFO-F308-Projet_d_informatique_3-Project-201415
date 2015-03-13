#include "backtrack.hpp"

Backtrack::Backtrack(std::vector< std::vector<float> > demand, std::vector< std::vector<bool> > free, int maxLight) :
    _maxX(0),
    _maxY(0),
    _maxLight(maxLight),
    _Ssolution(S_INIT),
    _demand(demand),
    _free(free),
    _lightSolution(),
    _lightInTest()
{

}

Backtrack::~Backtrack()
{

}

void Backtrack::execute() {
    execute(0);
    // TODO: Renvoyer un résultat.
}

void Backtrack::execute(int n) {

    if ( n >= _maxLight) return;

    struct Case next;
    next.x = 0;
    next.y = 0;

    if ( n != 0 ) {
        AmplLight light = _lightSolution.back();
        struct Case actual;
        actual.x = light.getX();
        actual.y = light.getY();
        next = getNextCase(actual);
    }

    while ( next.y < _maxY ) {
        _lightInTest.push_back(AmplLight(next.x,next.y, POWER));

        // TODO: check la solution

        execute(n+1);
        _lightInTest.pop_back();
        next = getNextCase(next);
    }

}

struct Backtrack::Case Backtrack::getNextCase(struct Case actual) {
    struct Case next;
    if( actual.x <_maxX-1 ) {
        next.x = actual.x+1;
        next.y = actual.y;
    } else {
        next.x = 0;
        next.y = actual.y+1;
    }
    return next;
}

void Backtrack::checkSoluce() {

    std::vector< std::vector< float > > matrix = calculateMatrix();
    float S = calculateS(matrix);
    if ( S < _Ssolution ) {
        _Ssolution = S;
        _lightSolution = _lightInTest;
    }
}

std::vector< std::vector< float > > Backtrack::calculateMatrix() {
    std::vector< std::vector < float > > matrix;
    for ( int j(0); j < _maxY; ++j ) {
        std::vector<float> line;
        for ( int i(0); i < _maxX; ++i ) {
            line.push_back(calcSij(i,j));
        }
        matrix.push_back(line);
    }
    return matrix;
}

float Backtrack::calcSij(int i, int j) {
    float Sij = 0.f;
    for ( int n(0); n < _lightSolution.size(); ++n ) {
        Sij += calcSijn(i,j,n);
    }
    return Sij;
}


float Backtrack::calcSijn(int i, int j, int n) {
    int Sin = calcSin(i,n);
    int Sjn = calcSjn(j,n);
    return (Sin < Sjn ) ? Sin : Sjn;
}

float Backtrack::calcSin(int i, int n) {
    AmplLight light = _lightSolution.at(n);
    float pn2 = POWER / ( R * R ); // P / r^2
    float ixr = std::abs(i - light.getX()) / R; // | i - Xn | / r
    float sin = pn2 * std::cos(std::atan(ixr));
    return sin;
}


float Backtrack::calcSjn(int j, int n) {
    AmplLight light = _lightSolution.at(n);
    float pn2 = POWER / ( R * R ); // P / r^2
    float jyr = std::abs(j - light.getY()) / R; // | j - Yn | / r
    float sjn = pn2 * std::cos(std::atan(jyr));
    return sjn;
}

float Backtrack::calculateS( std::vector< std::vector< float > > matrix ) {
    float sum = 0.f;

    for ( int i(0); i < _maxX; ++i ) {
        for ( int j(0); j < _maxY; ++j) {
            float diff = std::abs( _demand.at(i).at(j) - matrix.at(i).at(j));
            sum += diff;
        }
    }

    return sum;
}
