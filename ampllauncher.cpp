#include "ampllauncher.hpp"

AmplLauncher::AmplLauncher()
{

}

AmplLauncher::~AmplLauncher()
{

}

AmplResult AmplLauncher::launch() {
    reset();
    executeAmpl();
    return readResult();
}

void AmplLauncher::reset() {
    // Reset pour relancer un calcul.
}

void AmplLauncher::executeAmpl() {
    std::string cmd = "ampl amplscript.run > " + _OUTFILE;
    system(cmd.c_str());
}

AmplResult AmplLauncher::readResult() {
    AmplResult result;
    std::ifstream file(_OUTFILE.c_str());
    if ( file ) {
        std::string line = "";
        // On parcourt la fichier jusqu'au début des résultats:
        bool end = false;
        while( ( line != ":   X   Y   P     :=") && !end ){
            end = !std::getline(file,line);
        }
        // On récupère les N, P, X, Y:
        int n(0), p(0), x(0), y(0) , i = 1;
        file >> n;
        while ( n >= i ) {
            file >> x >> y >> p;
            result.addLight(x,y,p);
            ++i;
            file >> n;
        }
        file.clear();
        // On passe deux lignes pour attendre la variable imax;
        std::getline(file, line);
        std::getline(file, line);
        // On récupère imax:
        std::string tmpstring;
        int imax;
        file >> tmpstring >> tmpstring >> imax;
        // On passe cinq lignes pour arriver aux résultats Sij:
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);
        // On récupère les résultats de la matrice Sij:
        file.clear();
        int c(1);
        float sij(0.f);
        n = 0;
        file >> n;
        while ( n >= c ) {
            // On récupère la ligne:
            std::vector<float> line;
            for ( i = 0; i < imax; ++i ) {
                file >> sij;
                line.push_back(sij);
            }
            result.addMatrixLine(line);
            ++c;
            file >> n;
        }
        file.close();
    }

    return result;
}
