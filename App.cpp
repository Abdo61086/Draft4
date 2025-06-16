#include "App.h"
Move Current_Move;
unsigned char RemPlays = 9;
unsigned char difficulty;
TicTacToe::TicTacToe() {
    board = {
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    };
}

void TicTacToe::printBoard(const vector<vector<unsigned char>>& board) const {
    for (unsigned char i = 0; i < BOARD_SIZE; ++i) {
        for (unsigned char j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool TicTacToe::isWinner(const vector<vector<unsigned char>>& board, unsigned char player) const {
    if (board[currentMove.row][0] == player && board[currentMove.row][1] == player && board[currentMove.row][2] == player) return true;
    if (board[0][currentMove.col] == player && board[1][currentMove.col] == player && board[2][currentMove.col] == player) return true;

    if (currentMove.row == currentMove.col) {
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    }

    if ((currentMove.row == 0 && currentMove.col == 2) || (currentMove.row == 1 && currentMove.col == 1) || (currentMove.row == 2 && currentMove.col == 0)) {
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    }

    return false;
}

int TicTacToe::evaluate(const vector<vector<unsigned char>>& board, char state_F) const {
    if (state_F == PLAYER_O) {
        if (isWinner(board, PLAYER_O)) return 100;
        if (isWinner(board, PLAYER_X)) return 0;
        return 50;
    }

    if (state_F == PLAYER_X) {
        if (isWinner(board, PLAYER_X)) return 100;
        if (isWinner(board, PLAYER_O)) return 0;
        return 50;
    }

    return 50;
}

Move TicTacToe::findBestMove(vector<vector<unsigned char>>& board, unsigned char state_2) {
    int bestScore = INT_MIN;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL) {
                board[i][j] = state_2;
                int moveScore = minimax(board, RemPlays - 1, false, INT_MIN, INT_MAX, state_2);
                board[i][j] = EMPTY_CELL;
                if (moveScore >= bestScore) {
                    bestScore = moveScore;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }

    return bestMove;
}

void TicTacToe::humanMove(vector<vector<unsigned char>>& board, unsigned char player, int row, int col) {
    board[row][col] = player;
    currentMove = {row, col};
    currentPlayerClass = (currentPlayerClass == PLAYER_X) ? PLAYER_O : PLAYER_X;
    RemPlays--;
}

void TicTacToe::computerMove(unsigned char state) {
    Move bestMove = findBestMove(board, state);
    board[bestMove.row][bestMove.col] = currentPlayerClass;
    currentMove = bestMove;
    currentPlayerClass = (currentPlayerClass == PLAYER_X) ? PLAYER_O : PLAYER_X;
    RemPlays--;
}

bool TicTacToe::isBoardFull(const vector<vector<unsigned char>>& board) const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL) return false;
        }
    }
    return true;
}

void TicTacToe::setCurrentPlayer() {
    currentPlayerClass = StartPLayer ;
}

unsigned char TicTacToe::getCurrentPlayer() const{
    return currentPlayerClass ;
}


unsigned char TicTacToe::getCell(unsigned char row, unsigned char col) const {
    return board[row][col];
}

int TicTacToe::minimax(vector<vector<unsigned char>>& board, int depth, bool isMaximizing, int alpha, int beta, unsigned char state_F) {
    unsigned char opponent = (state_F == PLAYER_X) ? PLAYER_O : PLAYER_X;
    if(difficulty==EASY)
    {
        if (isBoardFull(board)) {
            return 0;
        }

        if (isMaximizing) {
            int bestScore = INT_MIN;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] == EMPTY_CELL) {
                        board[i][j] = state_F;
                        int score = minimax(board, depth + 1, false, alpha, beta, state_F);
                        board[i][j] = EMPTY_CELL;
                        bestScore = max(bestScore, score);
                        alpha = max(alpha, score);
                        if (beta <= alpha) {
                            return bestScore;
                        }
                    }
                }
            }
            return bestScore;
        } else {
            int bestScore = INT_MAX;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] == EMPTY_CELL) {
                        board[i][j] = opponent;
                        int score = minimax(board, depth + 1, true, alpha, beta, state_F);
                        board[i][j] = EMPTY_CELL;
                        bestScore = min(bestScore, score);
                        beta = min(beta, score);
                        if (beta <= alpha) {
                            return bestScore;
                        }
                    }
                }
            }
            return bestScore;
        }
    }
    else if(difficulty==HARD)
    {
        int boardVal = evaluateBoard(board, state_F);
        if (boardVal == 10 || boardVal == -10) {
            return boardVal;
        }
        if (isBoardFull(board)) {
            return 0;
        }

        if (isMaximizing) {
            int bestScore = INT_MIN;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] == EMPTY_CELL) {
                        board[i][j] = state_F;
                        int score = minimax(board, depth + 1, false, alpha, beta, state_F);
                        board[i][j] = EMPTY_CELL;
                        bestScore = max(bestScore, score);
                        alpha = max(alpha, score);
                        if (beta <= alpha) {
                            return bestScore;
                        }
                    }
                }
            }
            return bestScore;
        } else {
            int bestScore = INT_MAX;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] == EMPTY_CELL) {
                        board[i][j] = opponent;
                        int score = minimax(board, depth + 1, true, alpha, beta, state_F);
                        board[i][j] = EMPTY_CELL;
                        bestScore = min(bestScore, score);
                        beta = min(beta, score);
                        if (beta <= alpha) {
                            return bestScore;
                        }
                    }
                }
            }
            return bestScore;
        }
    }
}
int TicTacToe::evaluateBoard(const vector<vector<unsigned char>> &board, unsigned char state_F) {
    // Evaluate rows, columns, and diagonals for wins
    // Return +10 if 'state_F' wins, -10 if opponent wins, and 0 for no win
    unsigned char opponent = (state_F == PLAYER_X) ? PLAYER_O : PLAYER_X;

    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == state_F) return 10;
            else if (board[row][0] == opponent) return -10;
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == state_F) return 10;
            else if (board[0][col] == opponent) return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == state_F) return 10;
        else if (board[0][0] == opponent) return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == state_F) return 10;
        else if (board[0][2] == opponent) return -10;
    }

    return 0;
}

void TicTacToe::clearBoard(vector<vector<unsigned char>>& board) const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = EMPTY_CELL;
        }
    }
    RemPlays = 9;
}

int gameSetting() {
    int choice;
    std::cout << "Choose mode: \n1. Play against computer\n2. Play against friend\n";
    std::cin >> choice;
    return choice;
}

int replayChoice() {
    std::cout << "Do you want to replay? Yes:1 No: 0";
    int num;
    std::cin >> num;
    return num;
}
