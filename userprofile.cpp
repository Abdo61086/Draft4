#include "userprofile.h"
#include "gamehistory.h"
#include "gamemodewindow.h"
#include "loginpage.h"
#include "mainwindow.h"
#include "playerselection.h"
#include "qlabel.h"
#include "statisticswindow.h"
#include "ui_userprofile.h"

userProfile::userProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userProfile)
{
    ui->setupUi(this);
    Initialize();
}

userProfile::~userProfile()
{
    delete ui;
}

void userProfile::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    if(first == 1)
    {
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/1st_User_profile.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
    ui->label->setText(username1);
    QByteArray hashedPassword = QCryptographicHash::hash(password1.toUtf8(), QCryptographicHash::Sha256);
    ui->label_2->setText(hashedPassword);
    }
    else if(first == 2)
    {
        QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/2nd_User_profile.png");
        backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
        ui->label->setText(username);
        QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
        ui->label_2->setText(hashedPassword);
    }

    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();

}

void userProfile::on_pushButton_clicked()
{
    if(first == 1)
    {
    GamemodeWindow=new GameModeWindow;
    GamemodeWindow->show();
    this->hide();
    }
    else
    {
    playerSelection=new PlayerSelection;
    playerSelection->show();
    this->hide();
    }
}

void userProfile::on_pushButton_2_clicked()
{
    first = 0;
    mainWindow=new MainWindow;
    mainWindow->show();
    this->hide();
}


void userProfile::on_pushButton_4_clicked()
{
    Historyback=0;
    gamehistory=new gameHistory;
    gamehistory->show();
    this->hide();
}


void userProfile::on_pushButton_3_clicked()
{
    statisticswindow=new statisticsWindow;
    statisticswindow->show();
    this->hide();
}

