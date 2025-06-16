#ifndef GAMEPLAYWINDOW_H
#define GAMEPLAYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include<QMessageBox>
#include "App.h"
#include "gamehistory.h"
#include<QThread>

#define SINGLEPLAYER_MODE (0U)
#define MULTIPLAYER_MODE  (1U)
#define GAME_RUNNING      (0U)
#define GAME_ENDED        (1U)


class MainWindow;
class PlayerSelection;
class chooseDifficulty;
class GameModeWindow;
class gameHistory;

namespace Ui {
class GameplayWindow;
}
class GameplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameplayWindow(QWidget *parent = nullptr);
    ~GameplayWindow();

private slots:
    void onButtonClick(int row, int col);
    void Initialize();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();

    void ClearBoard();
    void setHistory();
    void storeGameHistory(const QString& username1, const QString& gameData,const QString& replayData);
    void setStats();
    void on_pushButton_5_clicked();

private:
    Ui::GameplayWindow *ui;
    TicTacToe game;
    MainWindow *mainWindow;
    PlayerSelection *playerSelection;
    GameModeWindow *gameModeWindow;
    chooseDifficulty *choosedifficulty;
    gameHistory *gamehistory;

};
extern unsigned char GameMode;
extern unsigned char StartPLayer;
extern unsigned char playerstarted;
extern QString username;
extern QString username1;


#endif // GAMEPLAYWINDOW_H
