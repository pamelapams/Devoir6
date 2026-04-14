// fichier : carte_.cpp
// auteur.es : METTEZ VOS NOMS ICI
// date : 2020
// modifications :
// description : Ce fichier contient la definition des methodes A IMPLEMENTER de la classe Carte d'un jeu de demineur

#include "carte.h"
#include "utilitaires.h"

#include <iomanip>
#include <cassert>
#include <stdio.h>

// Description: Methode qui calcule le nombre de mines adjacentes a une case
// param[E] Position de la case
// retour : nombre de mines adjacentes a la case
// post : on compte le nombre de mines adjacentes a la case (entre 0 et 8)

Compteur Carte::getNbMinesAdjacentes(Position e_pos)
{
    Compteur nb_mines = 0;
    for (int lig = e_pos.ligne() - 1; lig <= e_pos.ligne() + 1; ++lig)
    {
        for (int col = e_pos.colonne() - 1; col <= e_pos.colonne() + 1; ++col)
        {
            Position cur_pos{ lig, col };
            if (estDansCarte(cur_pos) && !(lig == e_pos.ligne() && col == e_pos.colonne())) {
                if (m_cases[lig][col].estUneMine()) { nb_mines++; }
            }
        }
    }
    return nb_mines;
}

// Description: Methode qui essaie d'ouvrir une case
// param[E] Position de la case
// retour : booleen - vrai si ce n'est pas une mine, faux sinon
// post : si la case a deja ete ouverte, ce n'est pas une mine -> retourne vrai, si la case n'est pas une mine, les cases voisines doivent etre ouvertes jusqu'a une prochaine mine

bool Carte::essaieCase(Position e_pos)
{
    Compteur nb_mines = 0;
    Position cur_pos{ e_pos.ligne(), e_pos.colonne() };

    if (estDansCarte(e_pos)) {
        if (m_cases[e_pos.ligne()][e_pos.colonne()].estOuverte()) { return true; }
        m_cases[e_pos.ligne()][e_pos.colonne()].ouvre();
        if (m_cases[e_pos.ligne()][e_pos.colonne()].estUneMine()) { return false; }
        nb_mines = getNbMinesAdjacentes(e_pos);
    } 
    else
    {
        return false;
    }

    for (int lig = e_pos.ligne() - 1; lig <= e_pos.ligne() + 1; ++lig)
    {
        for (int col = e_pos.colonne() - 1; col <= e_pos.colonne() + 1; ++col)
        {
            Position next_pos{ lig, col };
            if (!estDansCarte(next_pos) || (lig == cur_pos.ligne() && col == cur_pos.colonne())) continue;
            if (nb_mines == 0) essaieCase(next_pos);
        }
    }
    return true;
};

// Description: Methode qui calcule le nombre de mines adjacentes pour les cases libres de la carte
// post : pour chacune des cases qui ne contient pas une mine, on compte le nombre de mines adjacentes

void Carte::compteMinesAdjParCase()
{   
    Compteur nb_mines = 0;
    for (int lig = 0; lig < nbLignes(); ++lig) {
        for (int col = 0; col < nbColonnes(); ++ col) {
            Position cur_pos{ lig, col };

            if (!m_cases[lig][col].estUneMine())
            {
                nb_mines = getNbMinesAdjacentes(cur_pos);
                
                if (nb_mines != 0) 
                {
                    for (int i = 0; i < nb_mines; ++i) ++m_cases[lig][col];
                } 
            }
        }
    }
}
