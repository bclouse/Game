#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <assert.h>
#include <map>

using namespace std;

#ifndef CLASSES_H
#define CLASSES_H

#define COLOR_RESET "\033[0m"
#define COLOR_BOLD "\033[1m"

#define BLACK_TEXT "\033[30m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"
#define DEFAULT_TEXT "\033[39m"

#define BLACK_BACK "\033[40m"
#define RED_BACK "\033[41m"
#define GREEN_BACK "\033[42m"
#define YELLOW_BACK "\033[43m"
#define BLUE_BACK "\033[44m"
#define MAGENTA_BACK "\033[45m"
#define CYAN_BACK "\033[46m"
#define WHITE_BACK "\033[47m"
#define DEFAULT_BACK "\033[49m"

//===========================
// Piece Class
//===========================

class Piece{
private:
	int pos;
	int n_pos;
	char color;
	string print;
	int num;
public:
	Piece();
	void update_print(int);
	friend class Player;
	friend class Board;
	// friend class std::ostream;// operator << (std::ostream & os, Piece & other);

};

//===========================
// Player Class
//===========================

class Player{
private:
	vector<Piece> pieces;
	int score;
public:
	friend class Board;
	Player();
	void reset(char);
	void display();
	// friend std::ostream operator << (std::ostream & os, Player & other);
};

//===========================
// Board Class
//===========================

class Board {
private:
	char player_turn;
	map<int,int> rx, ry, bx, by;
	string full_board[3][8];
	char color[5][8];
	char symbol[5][8];
	Player red, blue, *current, *other;
	int roll;
public:
	Board();
	void reset();
	void display(bool);
	void update_board();
	bool check_moves();
	void execute(bool);
	bool winner();
	void test_map();
	void run_move();
	void update_score();
};



//===========================
// Functions
//===========================

int roll_dice();
bool y_or_n();

#endif