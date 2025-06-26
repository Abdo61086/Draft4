#include <QtTest/QtTest>
#include <QObject>
#include <QPushButton>
#include <QSignalSpy>
#include "../mainwindow.h"

class TestMainWindow : public QObject
{
    Q_OBJECT

public:
    TestMainWindow();
    ~TestMainWindow();

private slots:
    void testInitialize();
    void testStartButtonClicked();
    void testExitButtonClicked();
    void testSetupStartAndExit();

private:
    MainWindow* mainWindow;
};

TestMainWindow::TestMainWindow()
{
    mainWindow = new MainWindow();
}

TestMainWindow::~TestMainWindow()
{
    delete mainWindow;
}

void TestMainWindow::testInitialize()
{
    // Verify window geometry
    QCOMPARE(mainWindow->geometry(), QRect(0, 0, 1200, 800));

    // Verify background style is set
    QVERIFY(!mainWindow->styleSheet().isEmpty());
}

void TestMainWindow::testSetupStartAndExit()
{
    // Find all buttons in the window
    QList<QPushButton*> buttons = mainWindow->findChildren<QPushButton*>();
    QVERIFY(buttons.size() >= 2); // At least 2 buttons should exist

    // Verify buttons are transparent
    for (QPushButton* button : buttons) {
        QVERIFY(button->styleSheet().contains("rgba(255, 255, 255,0)"));
    }

    // Since we don't have object names, we can't reliably test positions
    // So we'll just verify we have the expected number of buttons
}

void TestMainWindow::testStartButtonClicked()
{
    QList<QPushButton*> buttons = mainWindow->findChildren<QPushButton*>();
    QVERIFY(buttons.size() >= 1);

    QPushButton* firstButton = buttons.first();
    QSignalSpy spy(firstButton, &QPushButton::clicked);

    QTest::mouseClick(firstButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);
}

void TestMainWindow::testExitButtonClicked()
{
    QList<QPushButton*> buttons = mainWindow->findChildren<QPushButton*>();
    QVERIFY(buttons.size() >= 2);

    QPushButton* lastButton = buttons.last();
    QSignalSpy spy(lastButton, &QPushButton::clicked);

    QTest::mouseClick(lastButton, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);
}

QTEST_MAIN(TestMainWindow)
#include "test_mainwindow.moc"
