#include "Classes.h"

using namespace std;

//===========================
// Piece Class
//===========================

Piece::Piece() {
	pos = 0;
}

void Piece::update_print(int num) {
	string n_print;

	if (color == 'R') n_print = RED_BACK;
	else 					n_print = BLUE_BACK;

	if (num != 0) 	n_print += ('0' + num);
	else 				n_print += "*";

	n_print += WHITE_BACK;
	// cout << n_print;

	print = n_print;
}

//===========================
// Player Class
//===========================

Player::Player() {
	Piece dummy;

	score = 0;
	pieces.clear();
	for (int i = 0; i < 7; i++) {
		dummy.num = i+1;
		pieces.push_back(dummy);
	}
}

void Player::reset(char c) {
	Piece dummy;

	score = 0;
	pieces.clear();
	dummy.color = c;
	for (int i = 0; i < 7; i++) {
		dummy.num = i+1;
		pieces.push_back(dummy);
	}
}

void Player::display() {
	for (int i = 0; i < 7; i++) {
		cout << '\t' << i+1 << ") pos = " << pieces[i].pos;
	}
	cout << endl;
}


//===========================
// Board Class
//===========================

Board::Board() {
	red.reset('R');
	blue.reset('B');

	if (rand()%2 == 0) 	{
		player_turn = 'R';
		current = &red;
	} else {
		player_turn = 'B';
		current = &blue;
	}

	for (int i = 0; i <= 15; i++) {

		if (i < 5 || i > 12) {						//map the x values
			rx.insert(pair <int,int> (i,0));
			bx.insert(pair <int,int> (i,2));	
		} else {
			rx.insert(pair <int,int> (i,1));
			bx.insert(pair <int,int> (i,1));
		}

		if (i < 5) {									//map the y values
			ry.insert(pair <int,int> (i,4-i));
			by.insert(pair <int,int> (i,4-i));
		} else if (i < 13) {
			ry.insert(pair <int,int> (i,i-5));
			by.insert(pair <int,int> (i,i-5));
		// } else if (i == 13) {
		// 	ry.insert(pair <int,int> (i,7));
		// 	by.insert(pair <int,int> (i,7));
		} else {
			ry.insert(pair <int,int> (i,20-i));
			by.insert(pair <int,int> (i,20-i));
		}
		
	}
}

void Board::reset() {
	red.reset('R');
	blue.reset('B');
	for (int i = 0; i = 3; i++) {
		for (int j = 0; j < 8; j++) {
			full_board[i][j];
		}
	}
	if (rand()%2 == 0) 	player_turn = 'R';
	else						player_turn = 'B';
}

void Board::display(bool clear_screen) {
	if (clear_screen) system("clear");

	cout << WHITE_BACK << BLACK_TEXT << " =============== " << endl;
	cout << " == Score " << RED_TEXT << red.score << BLACK_TEXT;
	cout << '/' << BLUE_TEXT << blue.score << BLACK_TEXT << " == " << endl;
	cout << " =============== \n                 " << endl;
	cout << WHITE_TEXT;

	update_board();
	for (int j = 0; j < 8; j++) {
		cout << WHITE_BACK << "    ";
		for (int i = 0; i < 5; i++) {
			switch (color[i][j]) {
				case 'W': cout << WHITE_BACK; break;
				case 'Y': cout << YELLOW_BACK; break;
				case 'R': cout << RED_BACK; break;
				case 'B': cout << BLUE_BACK; break;
			}
			cout << symbol[i][j];
			if (i == 0 || i == 3) {
				cout << WHITE_BACK << "  ";
			}
		}
		cout << WHITE_BACK << "    " << endl;
	}

	cout << "                 \n" << DEFAULT_BACK << DEFAULT_TEXT << endl;

}

void Board::update_board() {
	int x,y;
	// for (int i = 0; i < 7; i++) {
	// 	if (i != 3) {
	// 		red.pieces[i].pos = 2*(i+1);
	// 		blue.pieces[i].pos = (2*i)+1;
	// 	}
	// }
	// cout << "start reset" << endl;
	for (int i = 0; i < 5; i++) {
		// cout << "\t column #" << i << endl;
		for (int j = 0; j < 8; j++) {
			// cout << "\t\trow #" << j << endl;
			if ((i > 0 && i < 4) && ((i != 1 && i != 3) ||  (j != 4 && j != 5))) {
				color[i][j] = 'Y';
				if ((i == 1 || i == 3) && (j == 0 || j == 6) || (i == 2 && j == 3)) {
					symbol[i][j] = 'x';
				} else {
					symbol[i][j] = ' '; 
				}
			} else {
				color[i][j] = 'W';
				symbol[i][j] = ' ';
			}
		}
	}
	// cout << "start reassign" << endl;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 7; i++) {
			if (k == 0) {
				x = rx[red.pieces[i].pos]+1;
				y = ry[red.pieces[i].pos];
				if (red.pieces[i].pos == 0) {
					color[0][i] = 'R';
					if (player_turn == 'R') 	symbol[0][i] = '1'+i;
					else								symbol[0][i] = '*';
				} else if (red.pieces[i].pos != 15) {
					color[x][y] = 'R';
					if (player_turn == 'R') 	symbol[x][y] = '1'+i;
					else								symbol[x][y] = '*';
				}
			} else {
				x = bx[blue.pieces[i].pos]+1;
				y = by[blue.pieces[i].pos];
				if (blue.pieces[i].pos == 0) {
					color[4][i] = 'B';
					if (player_turn == 'B') symbol[4][i] = '1'+i;
					else							symbol[4][i] = '*';
				} else if (blue.pieces[i].pos != 15) {
					color[x][y] = 'B';
					if (player_turn == 'B') symbol[x][y] = '1'+i;
					else							symbol[x][y] = '*';
				}
			}
		}
	}
	// // cout << "start print" << endl;
	// for (int k = 0; k < 2; k++) {
	// 	for (int j = 0; j < 8; j++) {
	// 		for (int i = 0; i < 5; i++) {
	// 			if (k == 0)	cout << color[i][j] << '\t';
	// 			else			cout << symbol[i][j] << '\t';
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
}

bool Board::check_moves() {
	vector<int> valid;
	roll = roll_dice();
	// cout << "Roll: " << roll << endl;

	if (player_turn == 'R') other = &blue;
	else	 						other = &red;

	for (int i = 0; i < 7; i++) {
		valid.push_back(i);
		current->pieces[i].n_pos = current->pieces[i].pos+roll;
		// printf("%d) current: %2d\tnew: %2d\n", i, current->pieces[i].pos, current->pieces[i].n_pos);
	}


	for (int i = 6; i >= 0; i--) {
		for (int j = 6; j >= 0; j--) {
			if (i != j) {
				if ((current->pieces[i].n_pos == current->pieces[j].pos) && (current->pieces[j].pos != 15)) {
					valid.erase(valid.begin()+i);
					current->pieces[i].n_pos = current->pieces[i].pos;
					break;
				} else if (current->pieces[i].n_pos > 15) {
					valid.erase(valid.begin()+i);
					current->pieces[i].n_pos = current->pieces[i].pos;
					break;
				}
				for (int k = 0; k < 7; k++) {
					if (other->pieces[k].pos == 8 && current->pieces[i].n_pos == 8) {
						valid.erase(valid.begin()+i);
						current->pieces[i].n_pos = current->pieces[i].pos;
						break;
					}
				}
			}
		}
	}
	// cout << "Number of valid moves: " << valid.size() << endl;
	return (valid.size() != 0);
}

void Board::execute(bool ask_move) {
	/*	TODO:
	//	[_] Move pieces back to position 0 if they were attacked.
	//	[_] Rerolls
	//	[_] score
	*/	
	int move;
	bool valid = false;
	bool can_move = check_moves();
	char c;
	bool confirm = true;
	int dummy;

	if (ask_move)	confirm = false;

	// if (can_move)	cout << "VALID!" << endl;
	// else				cout << "NO MOVES!" << endl;

	cout << ">> It is ";
	if (player_turn == 'R')	cout << RED_TEXT << "Red's " << DEFAULT_TEXT;
	else							cout << BLUE_TEXT << "Blue's " << DEFAULT_TEXT;
	cout << "turn. \n>> Their roll is " << roll << ".\n";

	if (can_move && roll > 0) {
		cout << ">> Which piece do you want to move " << roll << " spaces?" << endl;
		cout << ">> ";
		do {
			cin >> move;
			if (move == 69) {
				cout << "RED:" << endl;
				red.display();
				cout << "BLUE:" << endl;
				blue.display();
				cout << ">> ";
				cin >> move;
			}
			move -= 1;
			if (move >= 0 && move < 7) {
				if (current->pieces[move].n_pos != current->pieces[move].pos) {
					if (ask_move) {
						cout << "Are you sure that you want to move piece #" << move+1 << " " << roll << " spaces? (Y or N) ";
						confirm = y_or_n();
					}
					if (confirm) {
						current->pieces[move].pos = current->pieces[move].n_pos;
						valid = true;
					} else {
						cout << ">> Please choose a different move." << endl;
						cout << ">> ";
					}
				} else {
					cout << ">> Invalid move. Try again." << endl;
					cout << ">> ";
				}
			} else {
				cout << ">> Invalid move. Try again." << endl;
				cout << ">> ";
			}
		} while (!valid);
	} else {
		cout << ">> Player has no moves..." << endl;
		cout << ">> Type Y to continue. ";
		cin >> c;
		move = 0;
		while (c != 'Y') {
			cout << ">> Please press Y. ";
			cin >> c;
		}
	}
	dummy = current->pieces[move].pos;
	for (int i = 0; i < 7; i++) {
		if (dummy == other->pieces[i].pos && (dummy > 4 && dummy < 13)) {

			other->pieces[i].pos = 0;
			break;
		}
	}
	if (dummy != 4 && dummy != 8 && dummy != 14 || !(can_move && roll > 0)) {
		Player *temp = current;
		current = other;
		other = temp;
		if (player_turn == 'R') {
			player_turn = 'B';
		} else {
			player_turn = 'R';
		}
	}

}

bool Board::winner() {
	return (red.score == 7 || blue.score == 7);
}

void Board::test_map() {
	int board[3][8] = {0};
	int i,j,k;

	for (k = 0; k < 2; k++) {

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 8; j++) {
				board[i][j] = -1;
			}
		}

		for (i = 0; i < 16; i++) {
			if (k == 0) {					//red
				board[rx[i]][ry[i]] = i;
			} else {							//blue
				board[bx[i]][by[i]] = i;
			}
		}

		for (j = 0; j < 8; j++) {
			for (i = 0; i < 3; i++) {
				cout << board[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;

	}
}

void Board::update_score() {
	red.score = 0;
	blue.score = 0;
	for (int i = 0; i < 7; i++) {
		if (red.pieces[i].pos == 15)	red.score++;
		if (blue.pieces[i].pos == 15)	blue.score++;
	}
}

//===========================
// Functions
//===========================

int roll_dice() {
	int count = 0;
	for (int i = 0; i < 4; i++) count += rand()%2;
	return count;
}

bool y_or_n() {
	char c;

	cin >> c;
	while ((c != 'Y') && (c != 'y') && (c != 'N') && (c != 'n')) {
		cout << "Invalid answer! Please enter Y or N. ";
		cin >> c;
	}
	if (c == 'Y' || c == 'y')	return true;
	else								return false;
}

//===========================
// Color Codes
//===========================

// "\033[" Starts the color code
// 0		= reset
// 1		= bold/bright
// 30 	= black
// 31 	= red
// 32 	= green
// 33 	= yellow
// 34 	= blue
// 35 	= magenta
// 36 	= cyan
// 37 	= white
// 40-47 = background
// *code must end with "m"
