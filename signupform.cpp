#include "signupform.h"
#include "qlabel.h"
#include "ui_signupform.h"
#include <QMessageBox>

SignupForm::SignupForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignupForm)
{
    ui->setupUi(this);
    Initialize();
}

SignupForm::~SignupForm()
{
    delete ui;
}
void SignupForm::Initialize()
{
    setGeometry(100, 100, 800, 600);

    // Create a QLabel and set it as the central widget
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 800, 600); // Adjust dimensions as needed

    // Set the background image using QPixmap
    QPixmap backgroundImage("D:/TicTacToe_Game-main/Qt_2/02_SignUP.png");
    backgroundLabel->setPixmap(backgroundImage.scaled(backgroundLabel->size(), Qt::IgnoreAspectRatio));

    // Ensure the label resizes with the window
    backgroundLabel->setScaledContents(true);

    // Make the label transparent so other widgets (if any) can be shown on top
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Ensure the label is stacked behind other widgets
    backgroundLabel->lower();
}
void SignupForm::clearFields()
{
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}

void SignupForm::on_signupButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirm = ui->confirmEdit->text();

    // Check if password matches confirm password
    if (password != confirm) {
        QMessageBox::warning(this, "Error", "Passwords do not match.");
        return;
    }

    // Check if username already exists in database
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM Players WHERE username = ?");
    checkQuery.bindValue(0, username);
    if (checkQuery.exec() && checkQuery.next()) {
        QMessageBox::warning(this, "Error", "Username already exists in database.");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Insert new user into database
    QSqlQuery query;
    query.prepare("INSERT INTO Players (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword.toHex());
    if (!query.exec()) {
        qDebug() << "Error inserting data:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to insert data into database.");
    } else {
        QMessageBox::information(this, "Success", "Signup successful!");
        clearFields();
        loginPage=new LoginPage;
        loginPage->show();
        this->close();
    }
}
