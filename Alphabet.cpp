#pragma once
#include "Alphabet.h"
#include "Letter.h"
#include <iostream>
using namespace std;

const bool* Alphabet::A() {
	Letter* letter = new Letter();
	/*Draw a block A*/
	letter->setColumnAs(0, true); //Set first column as true
	letter->setColumnAs(letter->row_length-1, true); //Set last column as true

	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height / 2, true); //Set middle row as true;
	return letter->field;
}
const bool* Alphabet::I() {
	Letter* letter = new Letter();
	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height - 1, true); //Set last row as true

	if (letter->row_length % 2) {
		letter->setColumnAs((letter->row_length / 2), true);
	}
	else {
		letter->setColumnAs((letter->row_length / 2), true);
		letter->setColumnAs((letter->row_length / 2) + 1, true);
	}//Set middle Column as True;
	return letter->field;
}

const bool* Alphabet::L() {
	Letter* letter =  new Letter();
	letter->setColumnAs(0, true); //Set first column as true
	letter ->setRowAs(letter->column_height - 1, true); //Set last row as true
	return letter->field;
}


void Alphabet::printLetter(const bool* r) {
	const char* ESC = "\x1b[";
	for (int i = 0; i < 35; i++) {
		char output = r[i] ? '*' : ' ';
		const int mod = (i) % 7 + 1;
		cout << ESC << mod << "G" << output; // Horizontal Positioning using ANSI
		if ((i + 1) % 7 == 0) {
			cout << endl << ESC << -6 << "G"; // Reset printer head on next line
		}
	}
};

