#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QMainWindow>
#include <QtSql>
#include <QCryptographicHash>
#include"loginpage.h"
class LoginPage;
namespace Ui {
class SignupForm;
}

class SignupForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignupForm(QWidget *parent = nullptr);
    ~SignupForm();

private slots:
    void Initialize();
    void on_signupButton_clicked();
    
private:
    Ui::SignupForm *ui;
    void clearFields();
    LoginPage* loginPage;
};

#endif // SIGNUPFORM_H
