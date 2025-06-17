#include <QtTest>
#include "../playerselection.h"
#include "../ui_playerselection.h"

// Declare external variables
extern unsigned char Choice1;
extern unsigned char Choice2;
extern unsigned char playerstarted;
extern unsigned char GameMode;
extern QString username;
extern QString username1;

// Define constants for game modes
const unsigned char SINGLEPLAYER_MODE = 1;
const unsigned char MULTIPLAYER_MODE = 2;

class PlayerSelectionTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testInitialization();
    void testSinglePlayerMode();
    void testMultiPlayerMode();
    void testButtonClicks();
    void cleanupTestCase();

private:
    PlayerSelection *playerSelection;
};

void PlayerSelectionTest::initTestCase()
{
    playerSelection = new PlayerSelection;
    playerSelection->show();
}

void PlayerSelectionTest::testInitialization()
{
    QVERIFY(playerSelection != nullptr);
    QVERIFY(playerSelection->isVisible());

    QLabel *label3 = playerSelection->findChild<QLabel*>("label_3");
    QLabel *label4 = playerSelection->findChild<QLabel*>("label_4");
    QVERIFY(label3 != nullptr);
    QVERIFY(label4 != nullptr);
    QCOMPARE(label3->alignment(), Qt::AlignCenter);
    QCOMPARE(label4->alignment(), Qt::AlignCenter);
}

void PlayerSelectionTest::testSinglePlayerMode()
{
    GameMode = SINGLEPLAYER_MODE;
    playerSelection->Initialize();

    QVERIFY(!playerSelection->ui->pushButton->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_2->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_3->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_4->isVisible());
    QVERIFY(!playerSelection->ui->label_4->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_5->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_6->isVisible());
    QVERIFY(playerSelection->ui->pushButton_7->isVisible());
    QVERIFY(playerSelection->ui->pushButton_8->isVisible());
    QVERIFY(playerSelection->ui->pushButton_9->isVisible());
}

void PlayerSelectionTest::testMultiPlayerMode()
{
    GameMode = MULTIPLAYER_MODE;
    playerSelection->Initialize();

    QVERIFY(playerSelection->ui->pushButton->isVisible());
    QVERIFY(playerSelection->ui->pushButton_2->isVisible());
    QVERIFY(playerSelection->ui->pushButton_3->isVisible());
    QVERIFY(playerSelection->ui->pushButton_4->isVisible());
    QVERIFY(playerSelection->ui->label_4->isVisible());
    QVERIFY(playerSelection->ui->pushButton_5->isVisible());
    QVERIFY(playerSelection->ui->pushButton_6->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_7->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_8->isVisible());
    QVERIFY(!playerSelection->ui->pushButton_9->isVisible());
}

void PlayerSelectionTest::testButtonClicks()
{
    // Test setting Choice1 to 'X' and 'O' in both single-player and multi-player modes
    GameMode = SINGLEPLAYER_MODE;
    playerSelection->Initialize();

    QTest::mouseClick(playerSelection->ui->pushButton_7, Qt::LeftButton);
    QCOMPARE(Choice1, 'X');
    QTest::mouseClick(playerSelection->ui->pushButton_8, Qt::LeftButton);
    QCOMPARE(Choice1, 'O');

    GameMode = MULTIPLAYER_MODE;
    playerSelection->Initialize();

    QTest::mouseClick(playerSelection->ui->pushButton, Qt::LeftButton);
    QCOMPARE(Choice1, 'X');
    QTest::mouseClick(playerSelection->ui->pushButton_2, Qt::LeftButton);
    QCOMPARE(Choice1, 'O');

    QTest::mouseClick(playerSelection->ui->pushButton_3, Qt::LeftButton);
    QCOMPARE(Choice2, 'X');
    QTest::mouseClick(playerSelection->ui->pushButton_4, Qt::LeftButton);
    QCOMPARE(Choice2, 'O');
}

void PlayerSelectionTest::cleanupTestCase()
{
    delete playerSelection;
}
QTEST_MAIN(PlayerSelectionTest)

#include "tst_playerselection_test.moc"
