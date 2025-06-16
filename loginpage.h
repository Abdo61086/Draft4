#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
#include<QPixmap>
#include<QLabel>
#include<QCryptographicHash>
class SignupForm;
class userProfile;
class GameplayWindow;
class PlayerSelection;
namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void Initialize();

private:
    Ui::LoginPage *ui;
    LoginPage *loginPage;
    QSqlDatabase mydb;
    SignupForm *signupForm;
    userProfile *userprofile;
    GameplayWindow *gameplayWindow;
    PlayerSelection *playerSelection;
};

extern unsigned char first;

#endif // LOGINPAGE_H
