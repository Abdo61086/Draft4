#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QWidget>
#include<QPushButton>
#include<QMessageBox>
class chooseDifficulty;
class PlayerSelection;
class GameplayWindow;
class MainWindow;
class userProfile;
namespace Ui {
class gameHistory;
}

class gameHistory : public QWidget
{
    Q_OBJECT

public:
    explicit gameHistory(QWidget *parent = nullptr);
    ~gameHistory();
    void Initialize();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();
    void fetchGameHistory();
    void displayGameHistory(int index, const QString& gameData);
    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::gameHistory *ui;
    chooseDifficulty  *choosedifficulty;
    PlayerSelection *playerSelection;
    QPushButton *buttons_history2[6][3][3];
    MainWindow *mainWindow;
    userProfile *userprofile;
    GameplayWindow *gameplayWindow;
    gameHistory *gamehistory;


};
extern QString buttons_history1[6][3][3];
extern unsigned char replay[7][9];
extern unsigned char numberofplays[6];
extern unsigned char Player1State[7];
extern unsigned char Player2State[7];
extern unsigned char replayindex[6];
extern unsigned char Historyback;

#endif // GAMEHISTORY_H
