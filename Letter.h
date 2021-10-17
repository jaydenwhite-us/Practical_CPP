#pragma once
class Letter {
	

public:
	Letter() {
		initializeFieldAs(false);
	}
	void initializeFieldAs(bool boolean) {
		for (int i = 0; i < field_length; i++)field[i] = boolean;
	}
	void setRowAs(const int row, const bool boolean) {
		for (int i = 0; i < row_length; i++)	field[(row_length*row + i)] = boolean;
	}
	void setColumnAs(const int column, const bool boolean) {
		for (int i = 0; i < column_height; i++)		field[(row_length*i + column)] = boolean;
	}


	const int field_length = 35;
	bool field[35];
	const int row_length = 7;
	const int column_height = 5;
};

