#include "addrecipewindow.h"

AddRecipeWindow::AddRecipeWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Добавить рецепт");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *formLayout = new QVBoxLayout();

    titleLabel = new QLabel("Введите данные о рецепте.");
    formLayout->addWidget(titleLabel);

    categoryLabel = new QLabel("Категория:");
    categoryComboBox = new QComboBox();
    categoryComboBox->addItem("Все категории");
    categoryComboBox->addItem("Закуски");
    categoryComboBox->addItem("Салаты");
    categoryComboBox->addItem("Супы");
    categoryComboBox->addItem("Холодные блюда");
    categoryComboBox->addItem("Горячие блюда");
    categoryComboBox->addItem("Десерты");
    categoryComboBox->addItem("Выпечка");
    categoryComboBox->addItem("Напитки");
    formLayout->addWidget(categoryLabel);
    formLayout->addWidget(categoryComboBox);

    kitchenLabel = new QLabel("Кухня: ");
    kitchenComboBox = new QComboBox();
    kitchenComboBox->addItem("Все кухни");
    kitchenComboBox->addItem("Российская кухня");
    kitchenComboBox->addItem("Французская кухня");
    kitchenComboBox->addItem("Японская кухня");
    kitchenComboBox->addItem("Грузинская кухня");
    kitchenComboBox->addItem("Белорусская кухня");
    kitchenComboBox->addItem("Неопределенная кухня");
    formLayout->addWidget(kitchenLabel);
    formLayout->addWidget(kitchenComboBox);

    nameLabel = new QLabel("Название:");
    nameLineEdit = new QLineEdit();
    formLayout->addWidget(nameLabel);
    formLayout->addWidget(nameLineEdit);

    descriptionLabel = new QLabel("Краткое описание:");
    descriptionTextEdit = new QTextEdit();
    formLayout->addWidget(descriptionLabel);
    formLayout->addWidget(descriptionTextEdit);

    ingredientsLabel = new QLabel("Ингредиенты:");
    ingredientsTextEdit = new QTextEdit();
    formLayout->addWidget(ingredientsLabel);
    formLayout->addWidget(ingredientsTextEdit);

    instructionLabel = new QLabel("Инструкция:");
    instructionTextEdit = new QTextEdit();
    formLayout->addWidget(instructionLabel);
    formLayout->addWidget(instructionTextEdit);

    prepTimeLabel = new QLabel("Время приготовления (минуты):");
    prepTimeLabel->setMinimumWidth(200);
    prepTimeLabel->setMaximumWidth(200);
    prepTimeSpinBox = new QSpinBox();
    prepTimeSpinBox->setMinimumWidth(50);
    prepTimeSpinBox->setMaximumWidth(50);
    prepTimeSpinBox->setMaximum(999);
    formLayout->addWidget(prepTimeLabel);
    formLayout->addWidget(prepTimeSpinBox);

    servingsLabel = new QLabel("Количество порций:");
    servingsLabel->setMinimumWidth(200);
    servingsLabel->setMaximumWidth(200);
    servingsSpinBox = new QSpinBox();
    servingsSpinBox->setMinimumWidth(50);
    servingsSpinBox->setMaximumWidth(50);
    servingsSpinBox->setMaximum(999);
    formLayout->addWidget(servingsLabel);
    formLayout->addWidget(servingsSpinBox);

    photoLabel = new QLabel("Фото:");
    selectedPhotoLabel = new QLabel("Нет выбранного фото");
    browsePhotoButton = new QPushButton("Выбрать фото");
    connect(browsePhotoButton, &QPushButton::clicked, this, &AddRecipeWindow::browsePhoto);

    QHBoxLayout *photoLayout = new QHBoxLayout();
    photoLayout->addWidget(photoLabel);
    photoLayout->addWidget(selectedPhotoLabel);
    photoLayout->addWidget(browsePhotoButton);

    formLayout->addLayout(photoLayout);
    mainLayout->addLayout(formLayout);

    saveButton = new QPushButton("Сохранить");
    connect(saveButton, &QPushButton::clicked, this, &AddRecipeWindow::saveRecipe);
    mainLayout->addWidget(saveButton);

    exitButton = new QPushButton("Закрыть");
    connect(exitButton, &QPushButton::clicked, this, &AddRecipeWindow::close);
    mainLayout->addWidget(exitButton);
}

void AddRecipeWindow::browsePhoto()
{
    selectedPhotoPath = QFileDialog::getOpenFileName(this, "Выберите фото", "", "Images (*.png *.jpg)");
    if (!selectedPhotoPath.isEmpty()) {
        selectedPhotoLabel->setText("Фото выбрано: " + selectedPhotoPath);
    }
}

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
