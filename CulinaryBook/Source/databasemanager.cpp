#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString &databasePath) : databasePath(databasePath) {}

DatabaseManager::~DatabaseManager() {
    closeDatabase();
}

bool DatabaseManager::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath);
    return db.open();
}

void DatabaseManager::closeDatabase() {
    db.close();
}

QSqlTableModel* DatabaseManager::createRecipeModel() {
    QSqlTableModel *model = new QSqlTableModel(nullptr, db);
        model->setTable("RecipesInfo");
        model->select();
        model->setHeaderData(1, Qt::Horizontal, "Название рецепта", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Краткое описание", Qt::DisplayRole);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    return model;
}

QSqlTableModel* DatabaseManager::createRecipeModelForSearch() {
    QSqlTableModel *model = new QSqlTableModel(nullptr, db);
        model->setTable("RecipesInfo");
        model->setFilter("1 = 0");
        model->select();
        model->setHeaderData(1, Qt::Horizontal, "Название рецепта", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Краткое описание", Qt::DisplayRole);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    return model;
}

QSqlQuery DatabaseManager::executeQuery(const QString &queryString, const QMap<QString, QVariant> &bindValues) {
    QSqlQuery query;
    query.prepare(queryString);

    for (auto it = bindValues.constBegin(); it != bindValues.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    query.exec();
    return query;
}
