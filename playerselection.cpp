#include "playerselection.h"
#include "gameplaywindow.h"
#include "ui_playerselection.h"
#include "App.h"

unsigned char Choice1 = 0,Choice2 = 0,playerstarted = 1;

PlayerSelection::PlayerSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerSelection)
{
    ui->setupUi(this);
    Initialize();
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_3->setText(username1 + " Selection:");
    ui->label_4->setText(username + " Selection:");

    if (GameMode ==  SINGLEPLAYER_MODE)
    {
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->label_4->hide();
        ui->pushButton_5->hide();
        ui->pushButton_6->hide();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
    }
    else
    {
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->pushButton_4->show();
        ui->label_4->show();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
    }

    // Connect combo box signal to slot for changing style
   // connect(ui->comboBox, &QComboBox::currentTextChanged, this, &PlayerSelection::changeButtonStyle);
}

void PlayerSelection::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    if (GameMode == MULTIPLAYER_MODE)
    {
        QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/05_Multiplayer_WhoisX.png");
        backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
    }else
    {
        QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/07_Singleplayer_WhoisX.png");
        backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
    }
    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();
}

PlayerSelection::~PlayerSelection()
{
    delete ui;
}

void PlayerSelection::on_pushButton_clicked()
{
     Choice1 ='X';
}

void PlayerSelection::on_pushButton_2_clicked()
{
     Choice1 ='O';
}

void PlayerSelection::changeButtonStyle(const QString &styleName)
{
    if (styleName == "Style 1") {
        ui->pushButton->setStyleSheet(style1);
        ui->pushButton_2->setStyleSheet(style1);
    } else if (styleName == "Style 2") {
        ui->pushButton->setStyleSheet(style2);
        ui->pushButton_2->setStyleSheet(style2);
    }
}

void PlayerSelection::on_pushButton_3_clicked()
{
    Choice2 ='X';
}

void PlayerSelection::on_pushButton_4_clicked()
{
    Choice2 ='O';
}

void PlayerSelection::on_pushButton_5_clicked()
{
    if(Choice1 == 'X' ||Choice1 == 'O')
    {
        StartPLayer = Choice1;
        playerstarted =1;
        Player1 = Choice1;
        Player2 = (Choice1 == PLAYER_X) ? 'O' : 'X';
        gameplayWindow = new GameplayWindow;
        gameplayWindow ->show();
        this->close();  // Close the GameModeWindow
    }
    Choice2 =0;
    Choice1 =0;
}


void PlayerSelection::on_pushButton_6_clicked()
{
    if(Choice2 == 'X' ||Choice2 == 'O')
    {
        StartPLayer = Choice2;
         playerstarted =2;
        Player2 =  Choice2;
        Player1 =  (Choice2 == PLAYER_X) ? 'O' : 'X';
        gameplayWindow = new GameplayWindow;
        gameplayWindow ->show();

        this->close();  // Close the GameModeWindow
    }
    Choice2 =0;
    Choice1 =0;
}


void PlayerSelection::on_pushButton_7_clicked()
{
    Choice1 ='X';
}


void PlayerSelection::on_pushButton_8_clicked()
{
    Choice1 ='O';
}


void PlayerSelection::on_pushButton_9_clicked()
{
    if(Choice1 == 'X' ||Choice1 == 'O')
    {
        StartPLayer = Choice1;
        Player1 = Choice1;
        Player2 = (Choice1 == PLAYER_X) ? 'O' : 'X';
        gameplayWindow = new GameplayWindow;
        gameplayWindow ->show();
        this->close();  // Close the GameModeWindow
    }
    Choice1 =0;
}

