#ifndef APP_H_
#define APP_H_

#include <iostream>
#include <vector>
#include <climits>
#include<QTimer>
#include<QThread>
using namespace std;

#define BOARD_SIZE   3
#define EMPTY_CELL  '-'
#define PLAYER_X    'X'
#define PLAYER_O    'O'
#define EASY  0
#define MEDIUM 1
#define HARD 2
struct Move {
    int row, col;
};

class TicTacToe {
    unsigned char currentPlayerClass = PLAYER_X;

public:
    Move currentMove;
    TicTacToe();
    void printBoard(const vector<vector<unsigned char>>& board) const;
    bool isWinner(const vector<vector<unsigned char>>& board, unsigned char player) const;
    int evaluate(const vector<vector<unsigned char>>& board, char state_F) const;
    Move findBestMove(vector<vector<unsigned char>>& board, unsigned char state_2);
    void humanMove(vector<vector<unsigned char>>& board, unsigned char player, int row, int col);
    bool isBoardFull(const vector<vector<unsigned char>>& board) const;
    void computerMove(unsigned char state);
    void setCurrentPlayer() ;
    unsigned char getCurrentPlayer() const;    unsigned char getCell(unsigned char row, unsigned char col) const;
    vector<vector<unsigned char>> board;
    int minimax(vector<vector<unsigned char>>& board, int depth, bool isMaximizing, int alpha, int beta, unsigned char state_F);
    void clearBoard(vector<vector<unsigned char>>& board) const;
    int evaluateBoard(const vector<vector<unsigned char>> &board, unsigned char state_F);
};

int gameSetting();
int replayChoice();

extern unsigned char StartPLayer;
extern Move Current_Move;
extern unsigned char difficulty;
#endif /* APP_H_ */
