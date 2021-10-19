/*
****************************************
NAME: BLOCK LETTER PRINTER
****************************************
The BLOCK LETTER PRINTER prints block 
letters on a grid that is 7 lines high
and 5 lines across. The program only
accepts and prints letters at this time.
****************************************
AUTHOR: JAYDEN WHITE
DATE_OF_INCEPTION: 2021-10-16
****************************************
****************************************
*/


/*
*Switch to a clean alternate buffer that will close on program exit.
*Solicit a user to input a string consisting only of letters.
*The block letter intakes a user string.
*The program defines a new array of undetermined length and height.
*Then a for loop uses the string iterator str.begin to loop through the string.
*On each iteration the string traverses a switch statement.
*For every upper and lowercase letter, there is a function to print the uppercase
form of the letter.
** This is where it gets hairy...Studying ANSI codes now.
** Test Phase 1 - Create a function that prints a 5*7 field of asterisks 
			relative to the last cursor location.
** Test Phase 2 - Print a vertical line in column 3 in a 5*7 field.
** Test Phase 3 - Initialize a 5*7 array with true or false values and print an asterisk border.
** Test Phase 4 - Create a Letter Class and an Alphabet Class. Print the Letter L; 
** Test Phase 5 - Create a Letter Class and an Alphabet Class. Print the Letter I;
** Test Phase 6 - Create a Letter Class and an Alphabet Class. Print the Letter A;
** Test Phase 7 - Create a Letter Class and an Alphabet Class. Print the Letter N;
** Test Phase 8 - Collect string input ;
** 10/17/2021
** Added Letters A, C, E, I, L, M, N
** Test Phase 9 - adjust Letter.setRowAs() to take allow specifying an integer
	start and end column. Otherwise default to zero.
	If I specify start, it should print from new start to the end of the row.
	If I specify end, it should print from start to to the new end of the row.
	If I specify a start and end, it should inclusively set those points in the field to true.
** 10/19/2021
** Parameterized setRowAs to allow start and end column.
** Adjusted style of E
** Parameterized setColumnAs to allow start and end row.
** Added a P
** Added an S
*/
#include "Alphabet.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
void closeInXSeconds(int);
void eraseInLine();
void initializeAs(bool*, int, bool);
void loadSavedCursorPosition();
void runTest(int);
void setRowAs(bool*, int, int, bool);
void setColumnAs(bool* r, const int row_length, const int column, const bool boolean, const int column_height);
void testPhase1();
void testPhase2();
void testPhase3();
void testPhase4();
void saveCursorPosition();
void reportCursor();
const char* ESC = "\x1b[";
const char* ALTERNATE_SCREEN_BUFFER = "?1049h";
const char* MAIN_SCREEN_BUFFER = "?1049l";

int main() {
	cout << ESC << ALTERNATE_SCREEN_BUFFER; /*Switch to a clean alternate buffer*/
	cout << ESC << "H"; //Position cursor at top of screen.
	Alphabet* alphabet = new Alphabet();
	//Initialize char* user_input
	//If string equals "test" run test prompt.
	//else print each character. 

	string user_input = "";
	cin >> user_input;
	if (user_input == "test") {
		int user_selected_test = 0;
		cout << "Choose a Test Number: 1,2,3";
		cin >> user_selected_test;
		runTest(user_selected_test);
		cout << endl;
	}
	else {
		for (string::iterator itr = user_input.begin(); itr != user_input.end(); itr++) {
			switch (*itr) {
			case 'A':
			case 'a':
				alphabet->printLetter(alphabet->A());
				break;
			case 'B':
			case 'b':
				alphabet->symbolNotDefined();
				break;
			case 'C':
			case 'c':
				alphabet->printLetter(alphabet->C());
				break;
			case 'D':
			case 'd':
				alphabet->symbolNotDefined();
				break;
			case 'E':
			case 'e':
				alphabet->printLetter(alphabet->E());
				break;
			case 'F':
			case 'f':
				alphabet->printLetter(alphabet->F());
				break;
			case 'G':
			case 'g':
				alphabet->printLetter(alphabet->G());
				break;
			case 'H':
			case 'h':
				alphabet->printLetter(alphabet->H());
				break;
			case 'I':
			case 'i':
				alphabet->printLetter(alphabet->I());
				break;
			case 'L':
			case 'l':
				alphabet->printLetter(alphabet->L());
				break;
			case 'M':
			case 'm':
				alphabet->printLetter(alphabet->M());
				break;
			case 'N':
			case 'n':
				if(itr+1!= user_input.end())
				alphabet->printLetter(alphabet->N());
				break;
			case 'P':
			case 'p':
				alphabet->printLetter(alphabet->P());
				break;
			case 'S':
			case 's':
				alphabet->printLetter(alphabet->S());
				break;
			case 'T':
			case 't':
				alphabet->printLetter(alphabet->T());
				break;
			case 'U':
			case 'u':
				alphabet->printLetter(alphabet->U());
				break;
			case 'W':
			case 'w':
				alphabet->printLetter(alphabet->W());
				break;
			default:
				cout << "default case";
				alphabet->symbolNotDefined();
			}
			cout << endl;
		}

	}
	
	closeInXSeconds(30);
	cout << ESC << MAIN_SCREEN_BUFFER; /*Return to main buffer*/
	return 0;
}

void runTest(int whichTest) {
	switch (whichTest) {
	case 1:
		cout << "Running Test " << whichTest << endl;
		testPhase1();
		break;
	case 2:
		cout << "Running Test " << whichTest << endl;
		testPhase2();
		break;
	case 3:
		cout << "Running Test " << whichTest << endl;
		testPhase3();
		break;
	case 4:
		cout << "Running Test " << whichTest << endl;
		testPhase4();
		break;
	default:
		cout << "Test Number Not Defined";
	}
}

void testPhase1(){
	cout << "\n";
	const int length = 7;
	const int height = 5;
	const int sentinel = (length + 1)* height;
	for (int i = 1; i <= sentinel; i++) {
		const int mod = i % (length + 1);
		cout << ESC << mod << "G" << '*'; // Horizontal Positioning using ANSI
		if (mod == 0) cout << ESC << "B"; // Vertical Positioning using ANSI
	}
	cout << "\n";
}
void testPhase2() {
	cout << "\n";
	const int length = 7;
	const int height = 5;
	const int column = 3;
	const int sentinel = (length + 1)* height;
	for (int i = 1; i <= height; i++) {
		cout << ESC << column << "G" << '*'; // Horizontal Positioning using ANSI
		cout << ESC << "B"; // Increment Vertical Positioning using ANSI
	}
	cout << "\n";
}
void testPhase3() {
	bool field[35];
	const int length = 7;
	const int height = 5;
	initializeAs(field, 35, false);
	setRowAs(field, length, 4, true);
	setRowAs(field, length, 0, true);
	setColumnAs(field, length, 0, true, height);
	setColumnAs(field, length, 6, true, height);
	//Print
	for (int i = 0; i < 35; i++) {
		char output = field[i] ? '*' :' ';
		const int mod = (i) % 7 + 1;
		cout << ESC << mod << "G" << output; // Horizontal Positioning using ANSI
		if ((i + 1) % 7 == 0) {
			cout << endl <<ESC << -6 << "G"; // Reset printer head on next line
		}
	}

}
void testPhase4() {
	Alphabet alpha = Alphabet();
	alpha.printAlphabet();
}


void saveCursorPosition() { cout << "\x1B[s"; }
void loadSavedCursorPosition() { cout << "\x1B[u"; }
void eraseInLine() { cout << "\x1B[K"; }
void reportCursor() { cout << "\x1B[6n"; }
void printMessage(char* message) { cout << message; }
void closeInXSeconds(int seconds) {
	while(seconds > -1) {
		cout << seconds << "\r";
		--seconds;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

void initializeAs(bool* r, int length, bool boolean) {
	for (int i = 0; i < length; i++)r[i] = boolean;
}
void setRowAs(bool* r, const int row_length, const int row, const bool boolean) {
	//Write Bottom Edge
	for (int i = 0; i < row_length; i++) {
		r[(row_length*row + i)] = boolean;
	}
}
void setColumnAs(bool* r, const int row_length, const int column, const bool boolean, const int column_height) {
	for (int i = 0; i < column_height; i++) r[(row_length*i + column)] = true;
}