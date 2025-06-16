#include "choosedifficulty.h"
#include "ui_choosedifficulty.h"
#include "qlabel.h"
chooseDifficulty::chooseDifficulty(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chooseDifficulty)
{
    ui->setupUi(this);
    Initialize();
}

chooseDifficulty::~chooseDifficulty()
{
    delete ui;
}


void chooseDifficulty::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/choose_difficulty.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));

    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();

}
void chooseDifficulty::on_easyButton_clicked()
{
    difficulty=EASY;
    playerSelection=new PlayerSelection;
    playerSelection->show();
    this->hide();
}


void chooseDifficulty::on_hardButton_clicked()
{
    difficulty=HARD;
    playerSelection=new PlayerSelection;
    playerSelection->show();
    this->hide();
}


