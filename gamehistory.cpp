#include "gamehistory.h"
#include "choosedifficulty.h"
#include "gameplaywindow.h"
#include "loginpage.h"
#include "mainwindow.h"
#include "playerselection.h"
#include "qlabel.h"
#include "qmessagebox.h"
#include "ui_gamehistory.h"
#include "userprofile.h"
#include<QSqlQuery>
#include<QSqlError>
unsigned char Historyback = 0;
unsigned char Historyplayer = 0;
gameHistory::gameHistory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameHistory)
{
    ui->setupUi(this);
    Initialize();
    fetchGameHistory();
    QString text_buttons;
}
gameHistory::~gameHistory()
{
    delete ui;
}
void gameHistory::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    if(GameMode == MULTIPLAYER_MODE && Historyback == 1)
    {
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/Game History - MP.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_16->show();
    ui->pushButton_17->show();
    ui->pushButton_18->show();
    ui->pushButton_19->show();

    }
    else if(GameMode == SINGLEPLAYER_MODE && Historyback == 1)
    {
        QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/Game History (1).png");
        backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->hide();
    }
    else if( Historyback == 0)
    {
        QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/Game History (1).png");
        backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->hide();
    }
    if (Historyplayer == 1)
    {
        if(Player2State[1] == 1)
        {
        ui->label->setText( " WIN ");
        }
        else if(Player2State[1] == 3)
        {
           ui->label->setText( " LOSE ");
        }
        else if(Player2State[1] == 2)
        {
           ui->label->setText( " DRAW ");
        }
        else
        {
            ui->label->setText( "  ");
        }
        if(Player2State[2] == 1)
        {
            ui->label_2->setText( " WIN ");
        }
        else if(Player2State[2] == 3)
        {
            ui->label_2->setText( " LOSE ");
        }
        else if(Player2State[2] == 2)
        {
            ui->label_2->setText( " DRAW ");
        }
        else
        {
            ui->label_2->setText( "  ");
        }
        if(Player2State[3] == 1)
        {
            ui->label_3->setText( " WIN ");
        }
        else if(Player2State[3] == 3)
        {
            ui->label_3->setText( " LOSE ");
        }
        else if(Player2State[3] == 2)
        {
            ui->label_3->setText( " DRAW ");
        }
        else
        {
            ui->label_3->setText( "  ");
        }
        if(Player2State[4] == 1)
        {
            ui->label_6->setText( " WIN ");
        }
        else if(Player2State[4] == 3)
        {
            ui->label_6->setText( " LOSE ");
        }
        else if(Player2State[4] == 2)
        {
            ui->label_6->setText( " DRAW ");
        }
        else
        {
            ui->label_6->setText( "  ");
        }
        if(Player2State[5] == 1)
        {
            ui->label_5->setText( " WIN ");
        }
        else if(Player2State[5] == 3)
        {
            ui->label_5->setText( " LOSE ");
        }
        else if(Player2State[5] == 2)
        {
            ui->label_5->setText( " DRAW ");
        }
        else
        {
            ui->label_5->setText( "  ");
        }
        if(Player2State[6] == 1)
        {
            ui->label_4->setText( " WIN ");
        }
        else if(Player2State[6] == 3)
        {
            ui->label_4->setText( " LOSE ");
        }
        else if(Player2State[6] == 2)
        {
            ui->label_4->setText( " DRAW ");
        }
        else
        {
            ui->label_4->setText( "  ");
        }


    }
    else
    {
        if(Player1State[1] == 1)
        {
            ui->label->setText( " WIN ");
        }
        else if(Player1State[1] == 3)
        {
            ui->label->setText( " LOSE ");
        }
        else if(Player1State[1] == 2)
        {
            ui->label->setText( " DRAW ");
        }
        else
        {
            ui->label->setText( "  ");
        }
        if(Player1State[2] == 1)
        {
            ui->label_2->setText( " WIN ");
        }
        else if(Player1State[2] == 3)
        {
            ui->label_2->setText( " LOSE ");
        }
        else if(Player1State[2] == 2)
        {
            ui->label_2->setText( " DRAW ");
        }
        else
        {
            ui->label_2->setText( "  ");
        }
        if(Player1State[3] == 1)
        {
            ui->label_3->setText( " WIN ");
        }
        else if(Player1State[3] == 3)
        {
            ui->label_3->setText( " LOSE ");
        }
        else if(Player1State[3] == 2)
        {
            ui->label_3->setText( " DRAW ");
        }
        else
        {
            ui->label_3->setText( "  ");
        }
        if(Player1State[4] == 1)
        {
            ui->label_6->setText( " WIN ");
        }
        else if(Player1State[4] == 3)
        {
            ui->label_6->setText( " LOSE ");
        }
        else if(Player1State[4] == 2)
        {
            ui->label_6->setText( " DRAW ");
        }
        else
        {
            ui->label_6->setText( "  ");
        }
        if(Player1State[5] == 1)
        {
            ui->label_5->setText( " WIN ");
        }
        else if(Player1State[5] == 3)
        {
            ui->label_5->setText( " LOSE ");
        }
        else if(Player1State[5] == 2)
        {
            ui->label_5->setText( " DRAW ");
        }
        else
        {
            ui->label_5->setText( "  ");
        }
        if(Player1State[6] == 1)
        {
            ui->label_4->setText( " WIN ");
        }
        else if(Player1State[6] == 3)
        {
            ui->label_4->setText( " LOSE ");
        }
        else if(Player1State[6] == 2)
        {
            ui->label_4->setText( " DRAW ");
        }
        else
        {
            ui->label_4->setText( "  ");
        }
    }
        // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();

}
void gameHistory::fetchGameHistory()
{
    QSqlQuery query;
    query.prepare("SELECT game_data FROM game_history WHERE username = :username order by id desc Limit 6;");
    //if(GameMode == MULTIPLAYER_MODE && Historyback == 1)
    //{
    //query.bindValue(":username", username1);
    //}
   // else
    //{
    if(GameMode==MULTIPLAYER_MODE&&Historyplayer==0&&Historyback==1)
    {
      query.bindValue(":username", username1);
        qDebug()<<"I am USER 1";
    }
    else if(GameMode==MULTIPLAYER_MODE&&Historyplayer==1&&Historyback==1)
    {
      query.bindValue(":username", username);
        qDebug()<<"I am USER 2";
    }
    else if(first==1)
    {
    query.bindValue(":username", username1);
     qDebug()<<"I am USER 3";
    }
    else if(first==2)
    {
    query.bindValue(":username", username);
    qDebug()<<"I am USER 4";
    }
    if (!query.exec()) {
        qDebug() << "Error: failed to execute query - " << query.lastError();
        return;
    }
    else
        qDebug()<<"Success";
    int index = 0;
    while (query.next()) {
        QString gameData = query.value(0).toString();
        displayGameHistory(index, gameData);
        ++index;
    }

}
void gameHistory::displayGameHistory(int index, const QString& gameData)
{
    QStringList rows = gameData.split(';');
    for (int row = 0; row < rows.size(); ++row) {
        QStringList cols = rows[row].split(',');
        for (int col = 0; col < cols.size(); ++col) {
            if (index < 6 && row < 3 && col < 3) {
                if(index==3)
                    index=5;
                else if(index==5)
                    index=3;
                buttons_history2[index][row][col] = new QPushButton("", this);
                buttons_history2[index][row][col]->setFixedSize(50, 50);
                buttons_history2[index][row][col]->setStyleSheet("background-color: rgba(255, 255, 255,0);");
                buttons_history2[index][row][col]->setText(cols[col]);
                QFont font = buttons_history2[index][row][col]->font();
                font.setPointSize(30);
                buttons_history2[index][row][col]->setFont(font);
                if (index < 3) {
                    buttons_history2[index][row][col]->setGeometry(55 * (row + 1) + 68 + index * 200, 55 * (col + 1) + 115, 50, 30);
                } else if (index >= 3) {
                    buttons_history2[index][row][col]->setGeometry(55 * (row + 1) + 68 + (index - 3) * 200, 55 * (col + 1) + 108 + 200, 50, 30);
                }
                if(index==3)
                    index=5;
                else if(index==5)
                    index=3;
            }
        }
    }
}
void gameHistory::on_pushButton_clicked()
{
    if(GameMode==SINGLEPLAYER_MODE)
    {
        choosedifficulty=new chooseDifficulty;
        choosedifficulty->show();
    }
    else
    {
        playerSelection=new PlayerSelection;
        playerSelection->show();
    }
    this->hide();
}


void gameHistory::on_pushButton_2_clicked()
{
    first = 0;
    mainWindow=new MainWindow;
    mainWindow->show();
    this->hide();
}


void gameHistory::on_pushButton_3_clicked()
{
    if (replayindex[0] == 0)
        return;
    replayindex[0]--;
    unsigned char row = replay[1][replayindex[0]] / 3;
    unsigned char col = replay[1][replayindex[0]] % 3;
    buttons_history2[0][row][col]->setText(" ");

}


void gameHistory::on_pushButton_4_clicked()
{
    if (replayindex[0] == numberofplays[0])
        return;

    unsigned char row = replay[1][replayindex[0]] / 3;
    unsigned char col = replay[1][replayindex[0]] % 3;
    buttons_history2[0][row][col]->setText(buttons_history1[0][row][col]);
    replayindex[0]++;

}


void gameHistory::on_pushButton_5_clicked()
{
    if (replayindex[1] == 0)
        return;
    replayindex[1]--;
    unsigned char row = replay[2][replayindex[1]] / 3;
    unsigned char col = replay[2][replayindex[1]] % 3;
    buttons_history2[1][row][col]->setText(" ");
}


void gameHistory::on_pushButton_7_clicked()
{
    if (replayindex[1] == numberofplays[1])
        return;

    unsigned char row = replay[2][replayindex[1]] / 3;
    unsigned char col = replay[2][replayindex[1]] % 3;
    buttons_history2[1][row][col]->setText(buttons_history1[1][row][col]);
    replayindex[1]++;

}


void gameHistory::on_pushButton_8_clicked()
{
    if (replayindex[2] == 0)
        return;
    replayindex[2]--;
    unsigned char row = replay[3][replayindex[2]] / 3;
    unsigned char col = replay[3][replayindex[2]] % 3;
    buttons_history2[2][row][col]->setText(" ");
}


void gameHistory::on_pushButton_6_clicked()
{
    if (replayindex[2] == numberofplays[2])
        return;

    unsigned char row = replay[3][replayindex[2]] / 3;
    unsigned char col = replay[3][replayindex[2]] % 3;
    buttons_history2[2][row][col]->setText(buttons_history1[2][row][col]);
    replayindex[2]++;
}




void gameHistory::on_pushButton_11_clicked()
{
    if (replayindex[3] == 0)
        return;
    replayindex[3]--;
    unsigned char row = replay[4][replayindex[3]] / 3;
    unsigned char col = replay[4][replayindex[3]] % 3;
    buttons_history2[3][row][col]->setText(" ");
}


void gameHistory::on_pushButton_13_clicked()
{
    if (replayindex[3] == numberofplays[3])
        return;

    unsigned char row = replay[4][replayindex[3]] / 3;
    unsigned char col = replay[4][replayindex[3]] % 3;
    buttons_history2[3][row][col]->setText(buttons_history1[3][row][col]);
    replayindex[3]++;
}


void gameHistory::on_pushButton_9_clicked()
{
    if (replayindex[4] == 0)
        return;
    replayindex[4]--;
    unsigned char row = replay[5][replayindex[4]] / 3;
    unsigned char col = replay[5][replayindex[4]] % 3;
    buttons_history2[4][row][col]->setText(" ");
}


void gameHistory::on_pushButton_10_clicked()
{
    if (replayindex[4] == numberofplays[4])
        return;

    unsigned char row = replay[5][replayindex[4]] / 3;
    unsigned char col = replay[5][replayindex[4]] % 3;
    buttons_history2[4][row][col]->setText(buttons_history1[4][row][col]);
    replayindex[4]++;
}


void gameHistory::on_pushButton_14_clicked()
{
    if (replayindex[5] == 0)
        return;
    replayindex[5]--;
    unsigned char row = replay[6][replayindex[5]] / 3;
    unsigned char col = replay[6][replayindex[5]] % 3;
    buttons_history2[5][row][col]->setText(" ");
}


void gameHistory::on_pushButton_12_clicked()
{
    if (replayindex[5] == numberofplays[5])
        return;

    unsigned char row = replay[6][replayindex[5]] / 3;
    unsigned char col = replay[6][replayindex[5]] % 3;
    buttons_history2[5][row][col]->setText(buttons_history1[5][row][col]);
    replayindex[5]++;

}


void gameHistory::on_pushButton_15_clicked()
{
    if(Historyback == 1)
    {
        gameplayWindow = new GameplayWindow;
        gameplayWindow ->show();
        this->close();
    }
    else if(Historyback == 0)
    {
        userprofile=new userProfile;
        userprofile->show();
        this->hide();
    }
}


void gameHistory::on_pushButton_19_clicked()
{
    first = 0;
    mainWindow=new MainWindow;
    mainWindow->show();
    this->hide();
}


void gameHistory::on_pushButton_17_clicked()
{
    if(GameMode==SINGLEPLAYER_MODE)
    {
        choosedifficulty=new chooseDifficulty;
        choosedifficulty->show();
    }
    else
    {
        playerSelection=new PlayerSelection;
        playerSelection->show();
    }
    this->hide();
}


void gameHistory::on_pushButton_18_clicked()
{
    if (Historyplayer == 0)
        return;
    Historyplayer=0;
    gamehistory=new gameHistory;
    gamehistory->show();
    this->close();
}


void gameHistory::on_pushButton_16_clicked()
{
    if (Historyplayer == 1)
        return;
    Historyplayer=1;
    gamehistory=new gameHistory;
    gamehistory->show();
    this->close();
}

