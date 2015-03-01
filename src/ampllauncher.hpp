#ifndef AMPLLAUNCHER_H
#define AMPLLAUNCHER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "amplresult.hpp"

class AmplLauncher
{
private:
    std::string const _OUTFILE = "amplout.txt";
    std::string _modelFile = "amplmodel.mod";

    void executeAmpl();
    AmplResult readResult();
public:
    AmplLauncher();
    ~AmplLauncher();

    AmplResult launch();
    void reset();
};

#endif // AMPLLAUNCHER_H
