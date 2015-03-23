#include "ampllauncher.hpp"

AmplLauncher::AmplLauncher()
{

}

AmplLauncher::~AmplLauncher()
{

}

AmplResult AmplLauncher::launch(std::vector<std::vector<float> > demand) {
    reset();
    writeData(demand);
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
    } else  {
        std::cout << "Impossible d'ouvrir le fichier de résultat" << std::endl;
    }

    return result;
}


void AmplLauncher::writeData(std::vector< std::vector<float> > demand) {
    std::ofstream fichier(_dataFile.c_str(), std::ios::out | std::ios::trunc);
    if ( fichier ) {
        fichier << "# Paramètre de taille de matrice." << std::endl;
        fichier << "param imin := 1;" << std::endl;
        fichier << "param jmin := 1;" << std::endl;
        fichier << "param imax := 7;" << std::endl;
        fichier << "param jmax := 7;" << std::endl;
        fichier << "# Matrice de la demande." << std::endl;
        fichier << "param D:" << std::endl;
        fichier << "1 2 3 4 5 6 7:=" << std::endl;

        for ( int l(0); l < 7; ++l ) {
            fichier << l+1;
            for ( int c(0); c < 7; ++c ) {
                fichier << " " << demand.at(l).at(c);
            }
            if ( l == 6 ) {
                fichier << ";";
            }
            fichier << std::endl;
        }

        fichier << "# Autres:" << std::endl;
        fichier << "param nmax := 3;" << std::endl;
        fichier << "param B := 1; # Constante de bordure" << std::endl;
        fichier << "param r := 4; # Hauteur de l'éclairage" << std::endl;
        fichier << "param UB := 50; # Limite de Pn" << std::endl;

        fichier.close();

    } else {
        std::cout << "Erreur lors de l'écriture du fichier de demande" << std::endl;
    }
}
