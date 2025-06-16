#ifndef GAMECHOICES_H
#define GAMECHOICES_H
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class gameChoices;
}
QT_END_NAMESPACE

class gameChoices : public gameChoices
{
    Q_OBJECT

public:
    gameChoices(QWidget *parent = nullptr);
    ~gameChoices();

private slots:
    void on_pushButton_clicked();
    void goToChoices();
private:
    Ui::gameChoices *ui;
};
#endif // GAMECHOICES_H
