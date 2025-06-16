#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QWidget>
#include<QCryptographicHash>
class gameHistory;
class MainWindow;
class GameModeWindow;
class PlayerSelection;
class statisticsWindow;
namespace Ui {
class userProfile;
}

class userProfile : public QWidget
{
    Q_OBJECT

public:
    explicit userProfile(QWidget *parent = nullptr);
    ~userProfile();
   void Initialize();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::userProfile *ui;
    GameModeWindow *GamemodeWindow;
    MainWindow *mainWindow;
    gameHistory *gamehistory;
    PlayerSelection *playerSelection;
    statisticsWindow *statisticswindow;
};

extern QString password,password1;

#endif // USERPROFILE_H
