#include "Headers/addrecipewindow.h"

// Конструктор для вызова окна добавления рецепта
// Данный класс унаследован от класса RecipeWindowBase, следовательно
// в конструкторе автоматически вызывается загрузка интерфейса.
AddRecipeWindow::AddRecipeWindow(QWidget *parent)
    : RecipeWindowBase(parent)
{
    setWindowTitle("Добавить рецепт");

}

// Переопределенная виртуальная функция для сохранения рецепта в базу данных
void AddRecipeWindow::saveRecipe()
{
    RecipeManager recipeManager;
    Recipe recipe;

    QString name = nameLineEdit->text();
    QString description = descriptionTextEdit->toPlainText();
    QString ingredients = ingredientsTextEdit->toPlainText();
    QString instruction = instructionTextEdit->toPlainText();
    int prepTime = prepTimeSpinBox->value();
    int servings = servingsSpinBox->value();
    QString category = categoryComboBox->currentText();
    QString kitchen = kitchenComboBox->currentText();

    if (name.isEmpty() || prepTime == 0 || servings == 0) {
        QMessageBox::warning(this, "Ошибка", "Заполните все обязательные поля!");
        return;
    }

    recipe.setName(name);
    recipe.setDescription(description);
    recipe.setIngredients(ingredients);
    recipe.setInstruction(instruction);
    recipe.setPrepTime(prepTime);
    recipe.setServings(servings);
    recipe.setCategory(category);
    recipe.setKitchen(kitchen);

    recipeManager.addRecipeToDatabase(recipe, selectedPhotoPath);

    accept();
}
