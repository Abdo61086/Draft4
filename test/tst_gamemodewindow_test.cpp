#include <QtTest/QtTest>
#include <QPushButton>
#include "../gamemodewindow.h"
#include "../choosedifficulty.h" // Include the header for chooseDifficulty
#include "../loginpage.h" // Include the header for LoginPage

class GameModeWindowTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testSinglePlayerButton();
    void testMultiPlayerButton();

private:
    GameModeWindow *gameModeWindow;
};

void GameModeWindowTest::initTestCase()
{
    gameModeWindow = new GameModeWindow();
    gameModeWindow->show();
}

void GameModeWindowTest::cleanupTestCase()
{
    gameModeWindow->close();
    delete gameModeWindow;
}

void GameModeWindowTest::testSinglePlayerButton()
{
    // Find the single player button
    QPushButton *singlePlayerButton = gameModeWindow->findChild<QPushButton *>("singlePlayerButton");
    QVERIFY(singlePlayerButton != nullptr);

    // Simulate button click
    QTest::mouseClick(singlePlayerButton, Qt::LeftButton);

    // Verify that the game mode is set to SINGLEPLAYER_MODE
    QCOMPARE(GameMode, SINGLEPLAYER_MODE);

    // Verify that the choose difficulty window is opened
    auto topLevelWidgets = QApplication::topLevelWidgets();
    bool chooseDifficultyOpened = false;
    for (QWidget *widget : topLevelWidgets) {
        if (dynamic_cast<chooseDifficulty *>(widget)) {
            chooseDifficultyOpened = true;
            widget->close(); // Close the window after test
            break;
        }
    }
    QVERIFY(chooseDifficultyOpened);
}

void GameModeWindowTest::testMultiPlayerButton()
{
    // Find the multi player button
    QPushButton *multiPlayerButton = gameModeWindow->findChild<QPushButton *>("multiPlayerButton");
    QVERIFY(multiPlayerButton != nullptr);

    // Simulate button click
    QTest::mouseClick(multiPlayerButton, Qt::LeftButton);

    // Verify that the game mode is set to MULTIPLAYER_MODE
    QCOMPARE(GameMode, MULTIPLAYER_MODE);

    // Verify that the login page window is opened
    auto topLevelWidgets = QApplication::topLevelWidgets();
    bool loginPageOpened = false;
    for (QWidget *widget : topLevelWidgets) {
        if (dynamic_cast<LoginPage *>(widget)) {
            loginPageOpened = true;
            widget->close(); // Close the window after test
            break;
        }
    }
    QVERIFY(loginPageOpened);
}

QTEST_MAIN(GameModeWindowTest)
#include "tst_gamemodewindow_test.moc"
