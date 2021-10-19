#pragma once
class Letter {
	

public:
	Letter() {
		initializeFieldAs(false);
	}
	void initializeFieldAs(bool boolean) {
		for (int i = 0; i < field_length; i++)field[i] = boolean;
	}
	void setRowAs(const int row, const bool boolean, const int start = int(false), const int end = row_length ) {
		for (int i = start; i < end; i++) {
		field[(row_length*row + i)] = boolean;
		}
	}
	
	void setColumnAs(const int column, const bool boolean) {
		for (int i = 0; i < column_height; i++)		field[(row_length*i + column)] = boolean;
	}

	const int field_length = 35;
	bool field[35];
	static const int row_length = 7; //Learn the many uses of static please.
	const int column_height = 5;
};

