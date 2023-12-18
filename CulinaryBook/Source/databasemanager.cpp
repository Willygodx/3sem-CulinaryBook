#include "Headers/databasemanager.h"

// Конструктор класса
DatabaseManager::DatabaseManager(const QString &databasePath) : databasePath(databasePath) {}

// Деструктор. Закрывает базу данных
DatabaseManager::~DatabaseManager() {
    closeDatabase();
}

// Функция для открытия базы данных типа "SQLite"
bool DatabaseManager::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath);
    return db.open();
}

// Функция для закрытия базы данных.
// Используется в деструкторе
void DatabaseManager::closeDatabase() {
    db.close();
}

// Функция для настройки модели таблицы рецептов базы данных для отображения в приложении
QSqlTableModel* DatabaseManager::createRecipeModel() {
    QSqlTableModel *model = new QSqlTableModel(nullptr, db);
        model->setTable("RecipesInfo");
        model->select();
        model->setHeaderData(1, Qt::Horizontal, "Название рецепта", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Краткое описание", Qt::DisplayRole);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    return model;
}

// Функция для настройки модели таблицы найденных рецептов базы данных для отображения в приложении
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

// Функция для реализации SQL-запроса.
QSqlQuery DatabaseManager::executeQuery(const QString &queryString, const QMap<QString, QVariant> &bindValues) {
    QSqlQuery query;
    query.prepare(queryString);

    for (auto it = bindValues.constBegin(); it != bindValues.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    query.exec();
    return query;
}
