#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <assert.h>
#include "Classes.h"

using namespace std;

int main() {
	int n;
	int count = 0,num;
	bool clear_screen, confirm;
	srand(time(NULL));
	bool check;

	cout << "Do you want to clear the screen when updating the board? (Y or N) ";
	clear_screen = y_or_n();
	cout << "Do you want to confirm moves? (Y or N) ";
	confirm = y_or_n();

	Board b;
	while (!b.winner()) {
		b.display(clear_screen);
		b.execute(confirm);
		b.update_score();
	}
	// b.display(clear_screen);
	// // check = b.check_moves();
	// b.execute(confirm);
	// b.display(clear_screen);


	return 0;
}