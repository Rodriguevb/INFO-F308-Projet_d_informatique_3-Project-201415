#include "backtrack.hpp"

Backtrack::Backtrack(std::vector< std::vector<float> > demand, std::vector< std::vector<bool> > free, int maxLight) :
    _maxX(0),
    _maxY(0),
    _maxLight(maxLight),
    _Ssolution(S_INIT),
    _demand(demand),
    _free(free),
    _lightSolution(),
    _lightInTest(),
    _requiredS(0),
    _optimal(true)
{

    _maxX = _demand.size();
    if ( _maxX > 0 ) {
        _maxY = _demand.at(0).size();
    }
}

Backtrack::~Backtrack()
{

}

AmplResult Backtrack::executeOptimal() {
    _optimal = true;
    execute(0);
    return getResult();
}

AmplResult Backtrack::findAGoodSolution(float pourcentage) {
    _optimal = false;
    _requiredS = calculateRequiredS(pourcentage);
    execute(0);
    return getResult();
}

bool Backtrack::execute(int n) {

    if ( n >= _maxLight) return false;

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
        if ( isCaseFree(next) ) {
            _lightInTest.push_back(AmplLight(next.x,next.y, POWER));
            checkSoluce();
            if ( !_optimal && isSoluceAcceptable() ) {
                return true;
            }
            bool found = execute(n+1);
            if ( found ) {
                return true;
            }
            _lightInTest.pop_back();
        }
        next = getNextCase(next);
    }

    return false;
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
    for ( int n(0); n < _lightInTest.size(); ++n ) {
        Sij += calcSijn(i,j,n);
    }
    return Sij;
}


float Backtrack::calcSijn(int i, int j, int n) {
    float Sin = calcSin(i,n);
    float Sjn = calcSjn(j,n);
    return (Sin < Sjn ) ? Sin : Sjn;
}

float Backtrack::calcSin(int i, int n) {
    AmplLight light = _lightInTest.at(n);
    float pn2 = ( (float) POWER) / ( R * R ); // P / r^2
    float ixr = std::abs(i - light.getX()) / ((float)R); // | i - Xn | / r
    float sin = pn2 * std::cos(std::atan(ixr));
    return sin;
}


float Backtrack::calcSjn(int j, int n) {
    AmplLight light = _lightInTest.at(n);
    float pn2 = ( (float) POWER) / ( R * R ); // P / r^2
    float jyr = std::abs(j - light.getY()) / ((float)R); // | j - Yn | / r
    float sjn = pn2 * std::cos(std::atan(jyr));
    return sjn;
}

float Backtrack::calculateS( std::vector< std::vector< float > > matrix ) {
    float sum = 0.f;

    for ( int c(0); c < _maxX; ++c ) {
        for ( int l(0); l < _maxY; ++l) {
            float diff = std::abs( _demand.at(l).at(c) - matrix.at(l).at(c));
            sum += diff;
        }
    }

    return sum;
}

bool Backtrack::isCaseFree(struct Case c) {
    return _free.at(c.y).at(c.x);
}

float Backtrack::calculateRequiredS(float pourcentage) {
    float sum = 0.f;
    for ( int c(0); c < _maxX; ++c ) {
        for ( int l(0); l < _maxY; ++l ) {
            sum += _demand.at(l).at(c);
        }
    }

    return pourcentage * sum;
}


bool Backtrack::isSoluceAcceptable() {
    return _Ssolution <= _requiredS;
}

AmplResult Backtrack::getResult() {
    AmplResult result;

    for ( int i(0); i < _lightSolution.size(); ++i ) {
        AmplLight light = _lightSolution.at(i);
        result.addLight(light.getX()+1, light.getY()+1, light.getP());
    }

    _lightInTest = _lightSolution;
    std::vector < std::vector < float > > matrix = calculateMatrix();
    for ( int y(0); y < _maxY; ++y ) {
        std::vector<float> line;
        for ( int x(0); x < _maxX; ++x ) {
            line.push_back(matrix.at(x).at(y));
        }
        result.addMatrixLine(line);
    }

    return result;
}
