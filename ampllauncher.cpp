#include "ampllauncher.hpp"

AmplLauncher::AmplLauncher()
{

}

AmplLauncher::~AmplLauncher()
{

}

void AmplLauncher::launch() {
    reset();
    executeAmpl();
}

void AmplLauncher::reset() {
    // Reset pour relancer un calcul.
}

void AmplLauncher::executeAmpl() {
    std::string cmd = "ampl amplscript.run > outampl.txt";
    system(cmd.c_str());
}

void AmplLauncher::readResult() {
    std::ifstream file(_OUTFILE.c_str());
    if ( file ) {

        file.close();
    }
}
