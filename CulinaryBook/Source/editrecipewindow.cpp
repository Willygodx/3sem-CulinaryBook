#include "Headers/editrecipewindow.h"

// Конструктор для вызова окна редактирования рецепта
// Данный класс унаследован от класса RecipeWindowBase, следовательно
// в конструкторе автоматически вызывается загрузка интерфейса.
// Также выгружаем данные рецепта, который редактируем, во все поля,
// чтобы пользователь мог отредактировать уже существующие данные
EditRecipeWindow::EditRecipeWindow(int recipeId, QWidget* parent)
    : RecipeWindowBase(parent), recipeId(recipeId)
{
    setWindowTitle("Редактировать рецепт");

    EditRecipeWindow::loadRecipeData();
}

// Переопределенная виртуальная функция для сохранения рецепта в базу данных
void EditRecipeWindow::saveRecipe()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    RecipeManager recipeManager;

    QString name = nameLineEdit->text();
    QString description = descriptionTextEdit->toPlainText();
    QString ingredients = ingredientsTextEdit->toPlainText();
    QString instruction = instructionTextEdit->toPlainText();
    int prepTime = prepTimeSpinBox->value();
    int servings = servingsSpinBox->value();
    QString category = categoryComboBox->currentText();
    QString kitchen = kitchenComboBox->currentText();
    QByteArray newPhotoData;
    QByteArray oldPhotoData;

    Recipe recipe;
    recipe.setName(name);
    recipe.setDescription(description);
    recipe.setIngredients(ingredients);
    recipe.setInstruction(instruction);
    recipe.setPrepTime(prepTime);
    recipe.setServings(servings);
    recipe.setCategory(category);
    recipe.setKitchen(kitchen);

    if (name.isEmpty() || prepTime == 0 || servings == 0) {
        QMessageBox::warning(this, "Ошибка", "Заполните все обязательные поля!");
        return;
    }

    if (!selectedPhotoPath.isEmpty()) {
        QFile photoFile(selectedPhotoPath);
        if (photoFile.open(QIODevice::ReadOnly)) {
            newPhotoData = photoFile.readAll();
            photoFile.close();
        }

    } else {
        query.prepare("SELECT photo FROM RecipesInfo WHERE recipeId = :recipeId");
        query.bindValue(":recipeId", recipeId);

        if (query.exec() && query.next()) {
            oldPhotoData = query.value("photo").toByteArray();
        }
    }

    query.prepare("UPDATE RecipesInfo SET photo = :photo WHERE recipeId = :recipeId");

    if (newPhotoData.isEmpty()) {
        query.bindValue(":photo", oldPhotoData);
    } else {
        query.bindValue(":photo", newPhotoData);
    }
    query.bindValue(":recipeId", recipeId);

    if (!query.exec()) {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
        db.rollback();
    }

    if (recipeManager.updateRecipe(recipeId, recipe)) {
        accept();
    }

}

// Функция для выгрузки данных рецепта, который редактируем, во все поля,
// чтобы пользователь мог отредактировать уже существующие данные
// Используется в конструкторе
void EditRecipeWindow::loadRecipeData()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    query.prepare("SELECT name, description, ingredients, instruction, prepTime, servings, photo, category, kitchen FROM RecipesInfo WHERE recipeId = :recipeId");
    query.bindValue(":recipeId", recipeId);

    if (query.exec() && query.next()) {
        QString name = query.value("name").toString();
        QString description = query.value("description").toString();
        QString ingredients = query.value("ingredients").toString();
        QString instruction = query.value("instruction").toString();
        int prepTime = query.value("prepTime").toInt();
        int servings = query.value("servings").toInt();
        QString category = query.value("category").toString();
        QString kitchen = query.value("kitchen").toString();
        nameLineEdit->setText(name);
        descriptionTextEdit->setPlainText(description);
        ingredientsTextEdit->setPlainText(ingredients);
        instructionTextEdit->setPlainText(instruction);
        prepTimeSpinBox->setValue(prepTime);
        servingsSpinBox->setValue(servings);
        categoryComboBox->setCurrentText(category);
        kitchenComboBox->setCurrentText(kitchen);
    }
}
