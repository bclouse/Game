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


//===========================
// Board Class
//===========================

Board::Board() {
	red.reset('R');
	blue.reset('B');

	if (rand()%2 == 0) 	player_turn = 'R';
	else						player_turn = 'B';

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
	for (int i = 0; i < 7; i++) {
		if (i != 3) {
			red.pieces[i].pos = 2*(i+1);
			blue.pieces[i].pos = (2*i)+1;
		}
	}
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
				} else {
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

void Board::check_moves() {
	if (player_turn == 'R') {

	} else {

	}
}

void Board::execute(bool ask_move) {
	int dice = roll();

}

int roll() {
	int count = 0;
	for (int i = 0; i < 4; i++) count += rand()%2;
	return count;
}

bool Board::winner() {

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
