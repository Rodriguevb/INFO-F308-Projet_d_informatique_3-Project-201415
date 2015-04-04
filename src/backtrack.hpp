#ifndef BACKTRACK_H
#define BACKTRACK_H

#include<vector>
#include<cmath>
#include<iostream>
#include "ampllight.hpp"
#include "amplresult.hpp"


class Backtrack
{
private:
    const float S_INIT = 100000.f; // Un S initial assez gros pour ne pas être la meilleure solution
    const int POWER = 16;
    const int R = 4;

    struct Case {
        int x;
        int y;
    };

private:
    int _maxX;
    int _maxY;
    int _maxLight;
    float _Ssolution;
    std::vector< std::vector<float> > _demand;
    std::vector< std::vector<bool> > _free;
    std::vector< AmplLight > _lightSolution;
    std::vector< AmplLight > _lightInTest;
    int _requiredS;
    bool _optimal;
public:
    Backtrack(std::vector< std::vector<float> >, std::vector< std::vector<bool> >, int);
    ~Backtrack();

    AmplResult executeOptimal();
    AmplResult findAGoodSolution(float);

private:
    bool execute(int n);
    struct Case getNextCase(struct Case);
    bool isCaseFree(struct Case);

    void checkSoluce();
    std::vector< std::vector< float > > calculateMatrix();
    float calculateS( std::vector< std::vector< float > > matrix );
    float calcSij(int i, int j);
    float calcSijn(int i, int j, int n);
    float calcSin(int i, int n);
    float calcSjn(int j, int n);

    float calculateRequiredS(float pourcentage);
    bool isSoluceAcceptable();

    AmplResult getResult();
};

#endif // BACKTRACK_H
