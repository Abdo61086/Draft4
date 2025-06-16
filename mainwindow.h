#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemodewindow.h"
#include<QPushButton>
class LoginPage;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reopen()
    {
        this->show();
    }
private slots:
    void Start_button_clicked();
    void Exit_button_clicked();
    void Initialize();
    void setupStartAndExit();
private:
    Ui::MainWindow *ui;
    GameModeWindow *gameModeWindow;
    LoginPage *loginPage;
};

#endif // MAINWINDOW_H
