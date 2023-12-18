#include "Headers/recipemanager.h"

// Конструктор класса
RecipeManager::RecipeManager() {

}

// Деструктор
RecipeManager::RecipeManager(QSqlTableModel *model) : model(model) {

}

// Функция для удаления рецепта из базы данных по уникальному номеру
// Здесь используется SQL-запрос "DELETE FROM" для удаления определенного
// рецепта из базы данных
bool RecipeManager::deleteRecipeById(int recipeId) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    db.transaction();

    query.prepare("DELETE FROM RecipesInfo WHERE recipeId = :recipeId");
    query.bindValue(":recipeId", recipeId);

    if (!query.exec()) {
        qDebug() << "Ошибка при удалении рецепта: " << query.lastError().text();
        db.rollback();
        return false;
    }

    if (model->removeRow(getRecipeRowById(recipeId))) {
        if (model->submitAll()) {
            db.commit();
            return true;
        }
    }

    db.rollback();
    return false;
}

// Функция для получения номера строки рецепта в таблице всех рецептов
int RecipeManager::getRecipeRowById(int recipeId) {
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
        if (model->data(index).toInt() == recipeId) {
            return row;
        }
    }
    return -1;
}

// Функция для получения рецепта из базы данных по уникальному номеру. Здесь
// используется SQL-запрос "SELECT * FROM" по всем полям для выбора рецепта
// из базы данных
Recipe RecipeManager::getRecipeById(int recipeId) {

    QSqlQuery query;
    query.prepare("SELECT * FROM RecipesInfo WHERE recipeId = :recipeId");
    query.bindValue(":recipeId", recipeId);

    if (query.exec() && query.next()) {
        Recipe recipe;
        recipe.setRecipeId(query.value(0).toInt());
        recipe.setName(query.value(1).toString());
        recipe.setDescription(query.value(2).toString());
        recipe.setIngredients(query.value(3).toString());
        recipe.setInstruction(query.value(4).toString());
        recipe.setPrepTime(query.value(5).toInt());
        recipe.setServings(query.value(6).toInt());
        recipe.setPhoto(query.value(7).toByteArray());
        recipe.setCategory(query.value(8).toString());
        recipe.setKitchen(query.value(9).toString());
        return recipe;
    } else {
        return Recipe();
    }
}

// Функция получения уникального номера рецепта по индексу в модели таблицы базы данных
int RecipeManager::getRecipeIdFromIndex(const QModelIndex &index, QSqlQueryModel *model) {
    if (index.isValid()) {
        return model->data(model->index(index.row(), 0)).toInt();
    } else {
        return -1;
    }
}

// Функция добавления рецепта в базу данных. Здесь используется SQL-запрос "INSERT INTO"
// по всем полям для занесения рецепта в базу данных
void RecipeManager::addRecipeToDatabase(const Recipe& recipe, const QString& photoPath) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("INSERT INTO RecipesInfo (name, description, ingredients, instruction, prepTime, servings, photo, category, kitchen) "
                  "VALUES (:name, :description, :ingredients, :instruction, :prepTime, :servings, :photo, :category, :kitchen)");

    query.bindValue(":name", recipe.getName());
    query.bindValue(":description", recipe.getDescription());
    query.bindValue(":ingredients", recipe.getIngredients());
    query.bindValue(":instruction", recipe.getInstruction());
    query.bindValue(":prepTime", recipe.getPrepTime());
    query.bindValue(":servings", recipe.getServings());
    query.bindValue(":category", recipe.getCategory());
    query.bindValue(":kitchen", recipe.getKitchen());

    QFile photoFile(photoPath);
    if (photoFile.open(QIODevice::ReadOnly)) {
        QByteArray photoData = photoFile.readAll();
        query.bindValue(":photo", photoData);
        photoFile.close();
    }
    if (!query.exec()) {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
        db.rollback();
    }

    db.commit();
}

// Функция для обновления данных рецепта в базе данных. Здесь используется
// SQL-запрос "UPDATE" для реализации обновления данных
bool RecipeManager::updateRecipeInfo(int recipeId, const Recipe& recipe) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    query.prepare("UPDATE RecipesInfo SET name = :name, description = :description, ingredients = :ingredients, "
                  "instruction = :instruction, prepTime = :prepTime, servings = :servings, category = :category, kitchen = :kitchen "
                  "WHERE recipeId = :recipeId");

    query.bindValue(":name", recipe.getName());
    query.bindValue(":description", recipe.getDescription());
    query.bindValue(":ingredients", recipe.getIngredients());
    query.bindValue(":instruction", recipe.getInstruction());
    query.bindValue(":prepTime", recipe.getPrepTime());
    query.bindValue(":servings", recipe.getServings());
    query.bindValue(":recipeId", recipeId);
    query.bindValue(":category", recipe.getCategory());
    query.bindValue(":kitchen", recipe.getKitchen());

    if (!query.exec()) {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
        db.rollback();
        return false;
    }

    return true;
}

bool RecipeManager::updateRecipe(int recipeId, const Recipe& recipe) {
    if (updateRecipeInfo(recipeId, recipe)) {
        return true;
    }

    return false;
}

RecipeManager::~RecipeManager() {

}
