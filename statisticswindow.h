#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include<QSqlQuery>
#include<QSqlError>
class userProfile;
namespace Ui {
class statisticsWindow;
}

class statisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit statisticsWindow(QWidget *parent = nullptr);
    ~statisticsWindow();
    void Initialize();
    void statisticsWindowShow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::statisticsWindow *ui;
    userProfile *userprofile;
};

#endif // STATISTICSWINDOW_H
