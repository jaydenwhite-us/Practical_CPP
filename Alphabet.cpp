#pragma once
#include "Alphabet.h"
#include "Letter.h"
#include <iostream>
#include <thread>
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
const bool* Alphabet::C() {
	Letter* letter = new Letter();
	/*Draw a block C*/
	letter->setColumnAs(0, true); //Set first column as true
	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height -1, true); //Set middle last as true;
	return letter->field;
}
const bool* Alphabet::E() {
	Letter* letter = new Letter();
	/*Draw a block E*/
	letter->setColumnAs(0, true); //Set first column as true

	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height/ 2, true, 0, 5); //Set middle row as true
	letter->setRowAs(letter->column_height - 1, true); //Set last row as true
	return letter->field;
}
const bool* Alphabet::F() {
	Letter* letter = new Letter();
	/*Draw a block F*/
	letter->setColumnAs(0, true); //Set first column as true

	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height / 2, true, 0, 5); //Set middle row as true
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
const bool* Alphabet::M() {
	Letter* letter = new Letter();
	/*Draw a block A*/
	letter->setColumnAs(0, true); //Set first column as true
	letter->setColumnAs(letter->row_length - 1, true); //Set last column as true
	letter->setColumnAs(letter->row_length /2 , true); //Set middle column as true
	letter->setRowAs(0, true); //Set first row as true
	return letter->field;
}
const bool* Alphabet::N() {
	Letter* letter = new Letter();
	/*Draw a block A*/
	letter->setColumnAs(0, true); //Set first column as true
	letter->setColumnAs(letter->row_length - 1, true); //Set last column as true
	letter->setRowAs(0, true); //Set first row as true
	return letter->field;
}

const bool* Alphabet::P() {
	Letter* letter = new Letter();
	/*Draw a block P*/
	letter->setColumnAs(0, true); //Set first column as true
	letter->setColumnAs(letter->row_length - 1, true, 0, letter->column_height / 2); //Set top half of last column

	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height / 2, true); //Set middle row as true
	return letter->field;
}

const bool* Alphabet::S() {
	Letter* letter = new Letter();
	/*Draw a block S*/
	letter->setColumnAs(letter->row_length - 1, true, letter->column_height/2, letter->column_height); //Set bottom half of first column as true
	letter->setColumnAs(0, true, 0, letter->column_height / 2); //Set top half of last column as true

	letter->setRowAs(0, true); //Set first row as true
	letter->setRowAs(letter->column_height / 2, true); //Set middle row as true.
	letter->setRowAs(letter->column_height - 1, true); //Set last row as true.
	return letter->field;
}

const bool* Alphabet::T() {
	Letter* letter = new Letter();
	letter->setRowAs(0, true);
	letter->setColumnAs(letter->row_length / 2, true);
	return letter->field;
}
const bool* Alphabet::U() {
	Letter* letter = new Letter();
	letter->setRowAs(letter->column_height-1, true);
	letter->setColumnAs(0, true);
	letter->setColumnAs(letter->row_length-1, true);
	return letter->field;
}

const bool* Alphabet::W() {
	Letter* letter = new Letter();
	letter->setRowAs(letter->column_height - 1, true); //Set bottom row as true.

	letter->setColumnAs(0, true); // Set first column as true.
	int height = letter->column_height;
	height /= 2; height += 1;
	letter->setColumnAs(letter->row_length / 2, true, height); //Set middle column as true.
	letter->setColumnAs(letter->row_length - 1, true); // Set last column as true.
	return letter->field;
}
void Alphabet::printLetter(const bool* r) {
	const char* ESC = "\x1b[";
	for (int i = 0; i < 35; i++) {
		this_thread::sleep_for(chrono::milliseconds(100));
		char output = r[i] ? '*' : ' ';
		const int mod = (i) % 7 + 1;
		cout << ESC << mod << "G" << output; // Horizontal Positioning using ANSI
		if ((i + 1) % 7 == 0) {
			cout << endl << ESC << -6 << "G"; // Reset printer head on next line
		}
	}
};

void Alphabet::printAlphabet() {
	printLetter(A());
	cout << endl;
	printLetter(C());
	cout << endl;
	printLetter(E());
	cout << endl;
	printLetter(I());
	cout << endl;
	printLetter(L());
	cout << endl;
	printLetter(M());
	cout << endl;
	printLetter(N());
	cout << endl;
}
void Alphabet::symbolNotDefined() {
	cout << "Symbol not defined.\n";
}