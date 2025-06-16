#ifndef CHOOSEDIFFICULTY_H
#define CHOOSEDIFFICULTY_H
#include <QWidget>
#include"playerselection.h"
class PlayerSelection;
namespace Ui {
class chooseDifficulty;
}

class chooseDifficulty : public QWidget
{
    Q_OBJECT

public:
    explicit chooseDifficulty(QWidget *parent = nullptr);
    void Initialize();
    ~chooseDifficulty();

private slots:
    void on_easyButton_clicked();
    void on_hardButton_clicked();

private:
    Ui::chooseDifficulty *ui;
    PlayerSelection *playerSelection;
};

#endif // CHOOSEDIFFICULTY_H
