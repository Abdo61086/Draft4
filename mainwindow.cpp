#include "mainwindow.h"
#include "loginpage.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initialize();
    setupStartAndExit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    setGeometry(0,0,1200,800);
    setStyleSheet("QMainWindow { background-image: url(D:/TicTacToe_Game-main/Qt_2/00_Main_Menu.png); background-position: center; background-repeat: repeat; }");

}
void MainWindow:: setupStartAndExit()
{
    QPushButton *button_transparent = new QPushButton(this);
    QPushButton *exit_button=new QPushButton(this);
    exit_button->setGeometry(900,550, 200, 50);
    button_transparent->setGeometry(450,550, 200, 50);
    // Set the stylesheet for transparency
    button_transparent->setStyleSheet("QPushButton {"
                                      "background-color: rgba(255, 255, 255,0);"
                                      "border: none;"
                                      "}");
    exit_button->setStyleSheet("QPushButton {"
                               "background-color: rgba(255, 255, 255,0);"
                               "border: none;"
                               "}");
    connect(button_transparent, &QPushButton::pressed, this, &MainWindow::Start_button_clicked);
    connect(exit_button, &QPushButton::pressed, this, &MainWindow::Exit_button_clicked);
}
void MainWindow::Start_button_clicked()
{
    loginPage=new LoginPage;
    loginPage->show();
    this->close();
}
void MainWindow::Exit_button_clicked()
{
    QApplication::quit();
}
