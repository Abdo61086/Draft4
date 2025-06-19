#include <QApplication>
#include <QtTest>
#include <QLabel>
#include <QPushButton>
#include "../userprofile.h"
#include "../ui_userprofile.h"

class TestUserProfile : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testInitialize();
    void testButtonClick();
    void cleanupTestCase();

private:
    userProfile *profileWindow;
};

void TestUserProfile::initTestCase()
{
    profileWindow = new userProfile;
    profileWindow->show();
}

void TestUserProfile::testInitialize()
{
    profileWindow->Initialize();
    QCOMPARE(profileWindow->geometry(), QRect(100, 100, 800, 600));

    QLabel *backgroundLabel = profileWindow->findChild<QLabel *>();
    QVERIFY(backgroundLabel != nullptr);
    QCOMPARE(backgroundLabel->geometry(), QRect(0, 0, 800, 600));
}

void TestUserProfile::testButtonClick()
{
    // Test pushButton click
    QPushButton *button1 = profileWindow->findChild<QPushButton *>("pushButton");
    QVERIFY(button1 != nullptr);

    QSignalSpy spy1(button1, &QPushButton::clicked);
    QTest::mouseClick(button1, Qt::LeftButton);
    QCOMPARE(spy1.count(), 1);
    QVERIFY(profileWindow->isHidden());

    profileWindow->show(); // Show again for the next button test

    // Test pushButton_2 click
    QPushButton *button2 = profileWindow->findChild<QPushButton *>("pushButton_2");
    QVERIFY(button2 != nullptr);

    QSignalSpy spy2(button2, &QPushButton::clicked);
    QTest::mouseClick(button2, Qt::LeftButton);
    QCOMPARE(spy2.count(), 1);
    QVERIFY(profileWindow->isHidden());

    profileWindow->show(); // Show again for the next button test

    // Test pushButton_3 click
    QPushButton *button3 = profileWindow->findChild<QPushButton *>("pushButton_3");
    QVERIFY(button3 != nullptr);

    QSignalSpy spy3(button3, &QPushButton::clicked);
    QTest::mouseClick(button3, Qt::LeftButton);
    QCOMPARE(spy3.count(), 1);
    QVERIFY(profileWindow->isHidden());

    profileWindow->show(); // Show again for the next button test

    // Test pushButton_4 click
    QPushButton *button4 = profileWindow->findChild<QPushButton *>("pushButton_4");
    QVERIFY(button4 != nullptr);

    QSignalSpy spy4(button4, &QPushButton::clicked);
    QTest::mouseClick(button4, Qt::LeftButton);
    QCOMPARE(spy4.count(), 1);
    QVERIFY(profileWindow->isHidden());
}

void TestUserProfile::cleanupTestCase()
{
    delete profileWindow;
}

QTEST_MAIN(TestUserProfile)
#include "tst_userprofile_test.moc"
