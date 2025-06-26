#include <QtTest/QtTest>
#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QSignalSpy>
#include "../loginpage.h"

// Declare extern for the global variables to avoid multiple definitions
extern QString username, password, username1, password1;
extern unsigned char first;

class TestLoginPage : public QObject
{
    Q_OBJECT

public:
    TestLoginPage();
    ~TestLoginPage();

private slots:
    void testInitialize();
    void testOnPushButtonClicked();
    void testOnPushButton2Clicked();

private:
    LoginPage* loginPage;
};

TestLoginPage::TestLoginPage()
{
    loginPage = new LoginPage();
}

TestLoginPage::~TestLoginPage()
{
    delete loginPage;
}

void TestLoginPage::testInitialize()
{
    // Verify that the window is properly sized
    QCOMPARE(loginPage->geometry(), QRect(100, 100, 800, 600));

    // Verify UI elements exist
    QVERIFY(loginPage->findChild<QLineEdit*>("lineEdit_user"));
    QVERIFY(loginPage->findChild<QLineEdit*>("lineEdit_pass"));
    QVERIFY(loginPage->findChild<QPushButton*>("pushButton"));
    QVERIFY(loginPage->findChild<QPushButton*>("pushButton_2"));
}

void TestLoginPage::testOnPushButtonClicked()
{
    // Set up test data
    QLineEdit* usernameEdit = loginPage->findChild<QLineEdit*>("lineEdit_user");
    QLineEdit* passwordEdit = loginPage->findChild<QLineEdit*>("lineEdit_pass");
    QPushButton* loginButton = loginPage->findChild<QPushButton*>("pushButton");

    // Test case 1: Empty fields
    usernameEdit->clear();
    passwordEdit->clear();
    QTest::mouseClick(loginButton, Qt::LeftButton);
    // Should show error message

    // Test case 2: Invalid credentials
    usernameEdit->setText("invaliduser");
    passwordEdit->setText("wrongpass");
    QTest::mouseClick(loginButton, Qt::LeftButton);
    // Should show error message

    // Note: Actual database tests would require mocking QSqlDatabase
}

void TestLoginPage::testOnPushButton2Clicked()
{
    QPushButton* signupButton = loginPage->findChild<QPushButton*>("pushButton_2");

    // Spy on the button click
    QSignalSpy spy(signupButton, &QPushButton::clicked);
    QTest::mouseClick(signupButton, Qt::LeftButton);

    QCOMPARE(spy.count(), 1); // Verify button was clicked
    // Should open signup form (would need to verify in integration test)
}

QTEST_MAIN(TestLoginPage)
#include "test_loginpage.moc"
