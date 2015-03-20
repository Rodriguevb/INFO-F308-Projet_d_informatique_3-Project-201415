#ifndef AMPLLAUNCHER_H
#define AMPLLAUNCHER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "amplresult.hpp"

class AmplLauncher
{
private:
    std::string const _OUTFILE = "amplout.txt";
    std::string _modelFile = "amplmodel.mod";
    std::string _dataFile = "ampldata.data";

    void executeAmpl();
    void writeData(std::vector< std::vector<float> > demand);
    AmplResult readResult();
public:
    AmplLauncher();
    ~AmplLauncher();

    AmplResult launch(std::vector< std::vector<float> > demand);
    void reset();
};

#endif // AMPLLAUNCHER_H
