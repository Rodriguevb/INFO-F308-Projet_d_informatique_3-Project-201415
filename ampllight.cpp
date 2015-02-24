#include "ampllight.hpp"

AmplLight::AmplLight(int x, int y, int p) :
_x(x),
_y(y),
_p(p)
{

}

int AmplLight::getX() {
    return _x;
}

int AmplLight::getY() {
    return _y;
}

int AmplLight::getP() {
    return _p;
}

void AmplLight::setX(int x) {
    _x = x;
}

void AmplLight::setY(int y) {
    _y = y;
}

void AmplLight::setP(int p) {
    _p = p;
}
