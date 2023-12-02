#include "Headers/recipemanager.h"

RecipeManager::RecipeManager() {

}

RecipeManager::RecipeManager(QSqlTableModel *model) : model(model) {

}

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

int RecipeManager::getRecipeRowById(int recipeId) {
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
        if (model->data(index).toInt() == recipeId) {
            return row;
        }
    }
    return -1;
}

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

int RecipeManager::getRecipeIdFromIndex(const QModelIndex &index, QSqlQueryModel *model) {
    if (index.isValid()) {
        return model->data(model->index(index.row(), 0)).toInt();
    } else {
        return -1;
    }
}

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

bool RecipeManager::updateRecipeInfo(int recipeId, const QString& name, const QString& description, const QString& ingredients, const QString& instruction, int prepTime, int servings, const QString& category, const QString& kitchen) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    query.prepare("UPDATE RecipesInfo SET name = :name, description = :description, ingredients = :ingredients, "
                  "instruction = :instruction, prepTime = :prepTime, servings = :servings, category = :category, kitchen = :kitchen "
                  "WHERE recipeId = :recipeId");

    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.bindValue(":ingredients", ingredients);
    query.bindValue(":instruction", instruction);
    query.bindValue(":prepTime", prepTime);
    query.bindValue(":servings", servings);
    query.bindValue(":recipeId", recipeId);
    query.bindValue(":category", category);
    query.bindValue(":kitchen", kitchen);

    if (!query.exec()) {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
        db.rollback();
        return false;
    }

    return true;
}

bool RecipeManager::updateRecipe(int recipeId, const QString& name, const QString& description, const QString& ingredients, const QString& instruction, int prepTime, int servings, const QString& category, const QString& kitchen) {
    if (updateRecipeInfo(recipeId, name, description, ingredients, instruction, prepTime, servings, category, kitchen)) {
        return true;
    }

    return false;
}

RecipeManager::~RecipeManager() {

}
