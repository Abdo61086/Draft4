#include <QtTest/QtTest>
#include "../App.h"


class TestTicTacToe : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Unit tests for key functionalities
    void testGameInitialization();
    void testMakeMove();
    void testIsWinner();
    void testIsBoardFull();
    void testClearBoard();
    void testFindBestMove();
};

void TestTicTacToe::initTestCase() {
    // Initialization before all tests
}

void TestTicTacToe::cleanupTestCase() {
    // Cleanup after all tests
}

void TestTicTacToe::testGameInitialization() {
    TicTacToe game;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            QCOMPARE(game.board[i][j], (unsigned char)EMPTY_CELL);
        }
    }
}

void TestTicTacToe::testMakeMove() {
    TicTacToe game;
    game.humanMove(game.board, PLAYER_X, 0, 0);
    QCOMPARE(game.board[0][0], (unsigned char)PLAYER_X);
}

void TestTicTacToe::testIsWinner() {
    TicTacToe game;
    game.humanMove(game.board, PLAYER_X, 0, 0);
    game.humanMove(game.board, PLAYER_X, 0, 1);
    game.humanMove(game.board, PLAYER_X, 0, 2);
    QVERIFY(game.isWinner(game.board, PLAYER_X));
}

void TestTicTacToe::testIsBoardFull() {
    TicTacToe game;
    game.humanMove(game.board, PLAYER_X, 0, 0);
    game.humanMove(game.board, PLAYER_X, 0, 1);
    game.humanMove(game.board, PLAYER_X, 0, 2);
    game.humanMove(game.board, PLAYER_X, 1, 0);
    game.humanMove(game.board, PLAYER_X, 1, 1);
    game.humanMove(game.board, PLAYER_X, 1, 2);
    game.humanMove(game.board, PLAYER_X, 2, 0);
    game.humanMove(game.board, PLAYER_X, 2, 1);
    game.humanMove(game.board, PLAYER_X, 2, 2);
    QVERIFY(game.isBoardFull(game.board));
}

void TestTicTacToe::testClearBoard() {
    TicTacToe game;
    game.humanMove(game.board, PLAYER_X, 0, 0);
    game.clearBoard(game.board);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            QCOMPARE(game.board[i][j], (unsigned char)EMPTY_CELL);
        }
    }
}

void TestTicTacToe::testFindBestMove() {
    TicTacToe game;
    game.humanMove(game.board, PLAYER_X, 0, 0);
    game.humanMove(game.board, PLAYER_O, 1, 1);
    Move bestMove = game.findBestMove(game.board, PLAYER_X);
    QVERIFY(bestMove.row >= 0 && bestMove.row < BOARD_SIZE);
    QVERIFY(bestMove.col >= 0 && bestMove.col < BOARD_SIZE);
}





// The following line includes the MOC-generated file, usually done in the cpp file
#include "tst_test1.moc"

QTEST_MAIN(TestTicTacToe)

