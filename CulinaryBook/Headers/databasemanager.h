#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

class DatabaseManager
{
private:
    QSqlDatabase db;
    QString databasePath;

public:
    DatabaseManager(const QString &databasePath);
    ~DatabaseManager();

    bool openDatabase();
    void closeDatabase();
    QSqlTableModel* createRecipeModel();
    QSqlTableModel* createRecipeModelForSearch();
    QSqlQuery executeQuery(const QString &queryString, const QMap<QString, QVariant> &bindValues);
};

#endif // DATABASEMANAGER_H
