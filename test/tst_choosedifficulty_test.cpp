#include <QtTest/QtTest>
#include <QPushButton>
#include "../choosedifficulty.h"
#include "../playerselection.h"
#include <QLabel>

class ChooseDifficultyTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInitialize();
    void testEasyButtonClicked();
    void testHardButtonClicked();

private:
    chooseDifficulty *difficultyWindow;
};

void ChooseDifficultyTest::initTestCase()
{
    difficultyWindow = new chooseDifficulty();
    difficultyWindow->show();
}

void ChooseDifficultyTest::cleanupTestCase()
{
    difficultyWindow->close();
    delete difficultyWindow;
}

void ChooseDifficultyTest::testInitialize()
{
    // Verify the window geometry
    QRect geometry = difficultyWindow->geometry();
    QCOMPARE(geometry, QRect(100, 100, 800, 600));

    // Verify the background image
    QLabel *backgroundLabel = difficultyWindow->findChild<QLabel *>();
    QVERIFY(backgroundLabel != nullptr);
    QPixmap backgroundPixmap = backgroundLabel->pixmap(Qt::ReturnByValue);
    QVERIFY(!backgroundPixmap.isNull());
}

void ChooseDifficultyTest::testEasyButtonClicked()
{
    QPushButton *easyButton = difficultyWindow->findChild<QPushButton *>("easyButton");
    QVERIFY(easyButton != nullptr);

    // Simulate button click
    QTest::mouseClick(easyButton, Qt::LeftButton);

    // Verify that the difficulty is set to EASY
    QCOMPARE(difficulty, EASY);

    // Verify that the player selection window is opened
    auto topLevelWidgets = QApplication::topLevelWidgets();
    bool playerSelectionOpened = false;
    for (QWidget *widget : topLevelWidgets) {
        if (dynamic_cast<PlayerSelection *>(widget)) {
            playerSelectionOpened = true;
            widget->close(); // Close the window after test
            break;
        }
    }
    QVERIFY(playerSelectionOpened);
}

void ChooseDifficultyTest::testHardButtonClicked()
{
    QPushButton *hardButton = difficultyWindow->findChild<QPushButton *>("hardButton");
    QVERIFY(hardButton != nullptr);

    // Simulate button click
    QTest::mouseClick(hardButton, Qt::LeftButton);

    // Verify that the difficulty is set to HARD
    QCOMPARE(difficulty, HARD);

    // Verify that the player selection window is opened
    auto topLevelWidgets = QApplication::topLevelWidgets();
    bool playerSelectionOpened = false;
    for (QWidget *widget : topLevelWidgets) {
        if (dynamic_cast<PlayerSelection *>(widget)) {
            playerSelectionOpened = true;
            widget->close(); // Close the window after test
            break;
        }
    }
    QVERIFY(playerSelectionOpened);
}

QTEST_MAIN(ChooseDifficultyTest)
#include "tst_choosedifficulty_test.moc"
