#ifndef AMPLLIGHT_HPP
#define AMPLLIGHT_HPP

class AmplLight {
private:
    int _x;
    int _y;
    int _p;

public:
    AmplLight(int x, int y, int p);
    int getX();
    int getY();
    int getP();
    void setX(int x);
    void setY(int y);
    void setP(int p);
};

#endif // AMPLLIGHT_HPP

