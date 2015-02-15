#ifndef AMPLLAUNCHER_H
#define AMPLLAUNCHER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class AmplLauncher
{
private:
    std::string const _OUTFILE = "amplout.txt";
    std::string _modelFile = "amplmodel.mod";

    void executeAmpl();
    void readResult();
public:
    AmplLauncher();
    ~AmplLauncher();

    void launch();
    void reset();
};

#endif // AMPLLAUNCHER_H
