#include <QCoreApplication>
#include <QtTest>
#include <QMainWindow>
#include <QPushButton>
#include "../mainwindow.h"
#include "../loginpage.h" // Include loginpage.h to access the complete definition of LoginPage

class MainWindowTest : public QObject
{
    Q_OBJECT

public:
    MainWindowTest();
    ~MainWindowTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInitialization();
    void testStartButtonClicked();
    void testExitButtonClicked();

private:
    MainWindow *mainWindow;
};

MainWindowTest::MainWindowTest() {}

MainWindowTest::~MainWindowTest() {}

void MainWindowTest::initTestCase()
{
    // Initialize any resources needed for tests
    mainWindow = new MainWindow();
}

void MainWindowTest::cleanupTestCase()
{
    // Clean up resources after all tests are executed
    delete mainWindow;
}

void MainWindowTest::testInitialization()
{
    // Test initialization of MainWindow
    QCOMPARE(mainWindow->geometry(), QRect(0, 0, 1200, 800)); // Check initial geometry
    QVERIFY(mainWindow->centralWidget() != nullptr); // Ensure central widget is set
    // Add more initialization checks as needed
}

void MainWindowTest::testStartButtonClicked()
{
    // Test Start_button_clicked() functionality
    QPushButton *startButton = nullptr;

    // Find the start button by object name
    const QObjectList children = mainWindow->children();
    for (QObject *child : children) {
        startButton = qobject_cast<QPushButton*>(child);
        if (startButton && startButton->objectName() == "button_transparent") {
            break;
        }
    }

    // Verify that the start button is found
    QVERIFY2(startButton != nullptr, "Start button not found");

    // Simulate button click
    QTest::mouseClick(startButton, Qt::LeftButton);

    // Wait for the loginPage to be created and shown
    QCoreApplication::processEvents(); // Process pending events

    // Access loginPage using the accessor function
    LoginPage *page = mainWindow->getLoginPage();

    // Verify that loginPage is created and visible
    QVERIFY2(page != nullptr, "LoginPage object is null");
    QVERIFY2(page->isVisible(), "LoginPage is not visible");
}



void MainWindowTest::testExitButtonClicked()
{
    // Test Exit_button_clicked() functionality
    QPushButton *exitButton = nullptr;
    const QObjectList children = mainWindow->children();
    for (QObject *child : children) {
        exitButton = qobject_cast<QPushButton*>(child);
        if (exitButton && exitButton->objectName() == "exit_button") {
            break;
        }
    }
    QVERIFY(exitButton != nullptr); // Ensure exit button is found
    // Simulate button click
    QTest::mouseClick(exitButton, Qt::LeftButton);
    QVERIFY(!mainWindow->isVisible()); // Verify that mainWindow is closed
}

QTEST_MAIN(MainWindowTest)
#include "tst_mainwindow_test.moc"
