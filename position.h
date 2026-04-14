#include <iostream>
#include <stdio.h>

//
//  position.h
//

#ifndef POSITION_H
#define POSITION_H

class Position {

	int _ligne;
	int _colonne;

public:
	Position();

	Position(int lig, int col);

	int ligne();

	int colonne();
};

istream& operator>>(std::istream&, Position&);
ostream& operator<<(std::ostream&, Position&);

void lireValiderEntier(std::istream&, int&);

#endif /* Position_h */
