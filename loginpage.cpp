#include "loginpage.h"
#include "gamemodewindow.h"
#include"gameplaywindow.h"
#include "playerselection.h"
#include "qlabel.h"
#include "signupform.h"
#include "ui_loginpage.h"
#include "userprofile.h"

QString username,password,username1,password1;
unsigned char first =0;

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    Initialize();
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/TicTacToe_Game-main/Qt_2/TicTacBoom.db");
    mydb.open();
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_2_clicked()
{
    signupForm=new SignupForm;
    signupForm->show();
    this->close();
}
void LoginPage::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/01_Login.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));

    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();
}

void LoginPage::on_pushButton_clicked()
{
    username=ui->lineEdit_user->text();
    password=ui->lineEdit_pass->text();
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Players WHERE username = :username AND password = :password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", hashedPassword.toHex());
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox::information(this, "Success", "SignIn successful,Hello "+username);

            if(first==1)
            {
                first = 2;
            }
            if (first ==0)
            {
                username1 = username;
                password1 = password;
                first = 1;
            }
            userprofile=new userProfile;
            userprofile->show();

        }
        if(count<1)
            QMessageBox::critical(this, "Error", "username or password is incorrect.");
    }
    this->close();
}

