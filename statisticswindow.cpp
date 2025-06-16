#include "statisticswindow.h"
#include "loginpage.h"
#include "ui_statisticswindow.h"
#include "gameplaywindow.h"
#include "qlabel.h"
#include "userprofile.h"

int wins;
int losses;
int ties;
statisticsWindow::statisticsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::statisticsWindow)
{
    ui->setupUi(this);
    Initialize();
    statisticsWindowShow();
    QString wins_string=QString::number(wins);
    QString losses_string=QString::number(losses);
    QString ties_string=QString::number(ties);
    ui->wins->setText(wins_string);
    ui->losses->setText(losses_string);
    ui->ties->setText(ties_string);
}

void statisticsWindow::statisticsWindowShow()
{
    QSqlQuery query;
    query.prepare("SELECT wins, losses, ties FROM game_history WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Error retrieving record:" << query.lastError();
    }

    if (query.next()) {
        wins = query.value(0).toInt();
        losses = query.value(1).toInt();
        ties = query.value(2).toInt();
    } else {
        qDebug() << "No record found with username:" << username;
    }
}

void statisticsWindow::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/statistics.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));

    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();

}
statisticsWindow::~statisticsWindow()
{
    delete ui;
}

void statisticsWindow::on_pushButton_clicked()
{
    userprofile=new userProfile;
    userprofile->show();
    this->close();
}

