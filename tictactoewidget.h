#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class TicTacToeWidget : public QWidget {
    Q_OBJECT // This macro marks the class as a Qt object and enables signal/slot mechanism

public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);

private slots:
    void handleButtonClick(int row, int col);

private:
    QGridLayout *gridLayout;
    QPushButton *buttons[3][3];
};

#endif // TICTACTOEWIDGET_H
