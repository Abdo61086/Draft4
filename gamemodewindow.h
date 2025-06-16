#ifndef GAMEMODEWINDOW_H
#define GAMEMODEWINDOW_H
#include"gameplaywindow.h"
#include <QWidget>
class LoginPage;
class chooseDifficulty;
class PlayerSelection;
namespace Ui {
class GameModeWindow;
}

class GameModeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameModeWindow(QWidget *parent = nullptr);
    ~GameModeWindow();

private slots:
    void on_singlePlayerButton_clicked();
    void on_multiPlayerButton_clicked();
    void Initialize();

private:
    Ui::GameModeWindow *ui;
    GameplayWindow *gameplayWindow;  // Single instance of GameplayWindow
    LoginPage* loginPage;
    PlayerSelection *playerSelection;
    chooseDifficulty * choosedifficulty;
};

#endif // GAMEMODEWINDOW_H
