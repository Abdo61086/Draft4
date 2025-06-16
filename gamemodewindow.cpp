#include "gamemodewindow.h"
#include "choosedifficulty.h"
#include "loginpage.h"
#include "playerselection.h"
#include "ui_gamemodewindow.h"
unsigned char GameMode = SINGLEPLAYER_MODE;
GameModeWindow::GameModeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameModeWindow),
    gameplayWindow(nullptr)  // Initialize pointer to nullptr
{
    ui->setupUi(this);
    Initialize();
    //ui->label->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

GameModeWindow::~GameModeWindow()
{
    delete ui;
    if (gameplayWindow) {
        delete gameplayWindow;
    }
}
void GameModeWindow::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/ChooseMode.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));

    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();
}

void GameModeWindow::on_singlePlayerButton_clicked()
{
    if (!gameplayWindow) {
        gameplayWindow = new GameplayWindow();
    }
     GameMode =  SINGLEPLAYER_MODE ;
      // Close the GameModeWindow
   choosedifficulty=new chooseDifficulty;
    choosedifficulty->show();
    this->close();
}

void GameModeWindow::on_multiPlayerButton_clicked()
{
    GameMode = MULTIPLAYER_MODE;
    loginPage = new LoginPage();
    loginPage->show();
    this->close();  // Close the GameModeWindow
}
