#include "position.h"
#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

//
//  position.cpp
//
Position::Position()
{
    _ligne = 0;
    _colonne = 0;
}

Position::Position(int lig, int col)
{
    _ligne = lig;
    _colonne = col;
}

int Position::ligne() const
{
    return _ligne;
}

int Position::colonne() const
{
    return _colonne;
}

// description : fonction utilitaire qui permet de lire et valider si c'est bien un entier qui est lu
// param[ES] : flux d'entree sur lequel on lit l'entier
// param[S] : entier lu
// pre : le flux est existant et ouvert (diff. de NULL)
// post : lit une valeur dans le flux jusqu'a ce qu'elle soit un entier
void lireValiderEntier(istream& es_entree, int& s_entier)
{
    assert(es_entree);

    while (!(es_entree >> s_entier))
    {
        cout << "Erreur! Vous devez entrer une nombre entier! " << endl << "Entrez la ligne : ";
        es_entree.clear();
        es_entree.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    assert(es_entree);
}

istream& operator>>(istream& is, Position& p)
{
    int lig, col;
    cout << "Entrez la ligne : ";
    lireValiderEntier(is, lig);
    cout << "Entrez la colonne : ";
    lireValiderEntier(is, col);
    p = Position(lig, col);
    return is;
}

ostream& operator<<(ostream& os, const Position& p)
{
    os << "(" << p.ligne() << ", " << p.colonne() << ")";
    return os;
}
