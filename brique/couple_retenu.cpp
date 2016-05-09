#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

/*
La fonction prend en entrée le fichier .result et le vecteur translation.
Elle retourne un vecteur qui contient l'indice du couple de mesures retenu.
*/
int choisirCoupleResult(const std::string& nomfichier, std::vector<double>& translation)
{
    std::ifstream fichier(nomfichier, ios::in); // ouverture du fichier en lecture

    double xa, ya, xb, yb;

    std::vector<std::vector<double>> M;

    if(fichier) // si ouverture a reussi
    {
        //cout << "ouverture du fichier reussie !" << endl;
        std::string ligne;
        do{
            fichier >> xa >> ya >> xb >> yb;
            //cout << xa << " " << ya << " " << xb << " " << yb << endl;
            std::vector<double> v;
            v.push_back(xa);
            v.push_back(ya);
            v.push_back(xb);
            v.push_back(yb);
            M.push_back(v);
        }while(getline(fichier, ligne));
        M.pop_back();
        fichier.close();
    }
    else{
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }

    for(auto ligne : M)
    {
        double x_image1 = ligne[0];
        double y_image1 = ligne[1];
        double x_image2 = ligne[2];
        double y_image2 = ligne[3];
        // | (X1 - X2) - tX |
        double xt = fabs(x_image1 - x_image2 - translation[0]);
        // | (Y1 - Y2) - tY |
        double yt = fabs(y_image1 - y_image2 - translation[1]);
        double somme = xt + yt;
        std::vector<double> v;
        v.push_back(somme);
    }

    // On cherche l'indice de la ligne contenant les plus petits éléments
    int min_index = std::min_element(v.begin(), v.end()) - v.begin();

    return min_index;
}
