#include <QApplication>
#include <QtTest>
#include "../gameplaywindow.h"
#include <QLabel>

class TestGameplayWindow : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testInitialize();
    void testButtonClick();
    void testClearBoard();
    void testSetHistory();
    void testSetStats();
    void cleanupTestCase();

private:
    GameplayWindow *gameplayWindow;
    void simulateButtonClick(int row, int col);
    QPushButton* getButton(int row, int col);
};

void TestGameplayWindow::initTestCase()
{
    gameplayWindow = new GameplayWindow;
    gameplayWindow->show();
}

void TestGameplayWindow::testInitialize()
{
    gameplayWindow->Initialize();
    QCOMPARE(gameplayWindow->geometry(), QRect(100, 100, 800, 600));
    QLabel *backgroundLabel = gameplayWindow->findChild<QLabel *>();
    QVERIFY(backgroundLabel != nullptr);
    QCOMPARE(backgroundLabel->geometry(), QRect(0, 0, 800, 600));
}

void TestGameplayWindow::testButtonClick()
{
    simulateButtonClick(0, 0);
    QCOMPARE(getButton(0, 0)->text(), QString("X"));

    simulateButtonClick(0, 1);
    QCOMPARE(getButton(0, 1)->text(), QString("O"));

    simulateButtonClick(1, 0);
    QCOMPARE(getButton(1, 0)->text(), QString("X"));

    simulateButtonClick(1, 1);
    QCOMPARE(getButton(1, 1)->text(), QString("O"));
}

void TestGameplayWindow::simulateButtonClick(int row, int col)
{
    QPushButton *button = getButton(row, col);
    QVERIFY(button != nullptr);
    QTest::mouseClick(button, Qt::LeftButton);
}

QPushButton* TestGameplayWindow::getButton(int row, int col)
{
    QString buttonName = QString("button_%1_%2").arg(row).arg(col);
    return gameplayWindow->findChild<QPushButton *>(buttonName);
}

void TestGameplayWindow::testClearBoard()
{
    gameplayWindow->on_pushButton_clicked();
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            QCOMPARE(getButton(row, col)->text(), QString(""));
        }
    }
}

void TestGameplayWindow::testSetHistory()
{
    // Test setHistory logic here
    // Ensure game data and replay data are correctly stored
}

void TestGameplayWindow::testSetStats()
{
    // Test setStats logic here
    // Ensure player statistics are correctly updated in the database
}

void TestGameplayWindow::cleanupTestCase()
{
    delete gameplayWindow;
}

QTEST_MAIN(TestGameplayWindow)
#include "tst_gameplaywindow_test.moc"
