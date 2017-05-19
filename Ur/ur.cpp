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

	srand(time(NULL));
	// for (int i = 0; i < 20; i++) {
	// 	num = rand()%2;
	// 	count += num;
	// 	cout << num << " ";
	// }
	// cout << endl;
	// cout << (float) count/20 << endl;
	Board b;

	// srand(time(NULL));
	// // b.test_map();
	// b.update_board();
	// b.display(true);
	// // char str[] = "This is a string";
	// cout << "How many rolls? ";
	// cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	cout << roll() << endl;
	// }
	// b.update_board();
	b.display(true);

	// cout << DEFAULT_TEXT << DEFAULT_BACK;

	return 0;
}