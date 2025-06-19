#include <QtTest/QtTest>
#include "../gamehistory.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSignalSpy>
#include <QLabel>

class TestGameHistory : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        // Initialize any necessary setup before tests run
        // For example, setting up a test database
        QSqlDatabase testDb = QSqlDatabase::addDatabase("QSQLITE", "testConnection");
        testDb.setDatabaseName(":memory:"); // Use in-memory database for testing
        QVERIFY(testDb.open());

        // Create necessary tables or insert initial data if needed for testing
        QSqlQuery query(testDb);
        QVERIFY(query.exec("CREATE TABLE game_history (id INTEGER PRIMARY KEY, username TEXT, game_data TEXT)"));
        QVERIFY(query.exec("INSERT INTO game_history (username, game_data) VALUES ('testuser', 'X,O,X;O,X,O;X,X,O')"));
    }

    void cleanupTestCase()
    {
        // Cleanup any resources after all tests finish
        QSqlDatabase::database("testConnection").close();
    }

    void testInitialization()
    {
        gameHistory historyPage;
        QVERIFY(historyPage.findChild<QLabel*>("backgroundLabel") != nullptr);
        QVERIFY(historyPage.findChild<QPushButton*>("pushButton") != nullptr);
    }

    void testFetchGameHistory()
    {
        gameHistory historyPage;

        // Ensure the test database connection is used
        QSqlDatabase::database("testConnection");

        // Simulate fetching game history
        historyPage.fetchGameHistory();

        // Verify the game history was fetched and displayed correctly
        // This depends on your actual UI setup and labels/buttons in the game history
        // For example:
        QVERIFY(historyPage.findChild<QPushButton*>("buttons_history2[0][0][0]") != nullptr);
    }

    void testButtonActions()
    {
        gameHistory historyPage;

        // Connect signals and slots for testing button actions
        QSignalSpy spy(historyPage.findChild<QPushButton*>("pushButton"), SIGNAL(clicked()));
        QSignalSpy spy2(historyPage.findChild<QPushButton*>("pushButton_2"), SIGNAL(clicked()));

        // Simulate button clicks
        QMetaObject::invokeMethod(historyPage.findChild<QPushButton*>("pushButton"), "click", Qt::DirectConnection);
        QMetaObject::invokeMethod(historyPage.findChild<QPushButton*>("pushButton_2"), "click", Qt::DirectConnection);

        QCOMPARE(spy.count(), 1); // Ensure the pushButton clicked signal is emitted once
        QCOMPARE(spy2.count(), 1); // Ensure the pushButton_2 clicked signal is emitted once
    }

    // Additional test cases can be added for edge cases, different scenarios, etc.
};

#include "tst_gamehistory_test.moc"
QTEST_MAIN(TestGameHistory)

