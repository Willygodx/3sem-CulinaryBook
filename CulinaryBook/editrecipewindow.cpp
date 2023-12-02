#include "editrecipewindow.h"

EditRecipeWindow::EditRecipeWindow(int recipeId, QWidget* parent)
    : QDialog(parent), recipeId(recipeId)
{
    setWindowTitle("Редактировать рецепт");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QVBoxLayout* formLayout = new QVBoxLayout();

    titleLabel = new QLabel("Редактировать данные о рецепте.");
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
    selectedPhotoLabel = new QLabel("Фото не изменено");
    browsePhotoButton = new QPushButton("Выбрать новое фото");
    connect(browsePhotoButton, &QPushButton::clicked, this, &EditRecipeWindow::browsePhoto);

    QHBoxLayout* photoLayout = new QHBoxLayout();
    photoLayout->addWidget(photoLabel);
    photoLayout->addWidget(selectedPhotoLabel);
    photoLayout->addWidget(browsePhotoButton);

    formLayout->addLayout(photoLayout);
    mainLayout->addLayout(formLayout);

    saveButton = new QPushButton("Сохранить");
    connect(saveButton, &QPushButton::clicked, this, &EditRecipeWindow::saveRecipe);
    mainLayout->addWidget(saveButton);

    exitButton = new QPushButton("Закрыть");
    connect(exitButton, &QPushButton::clicked, this, &EditRecipeWindow::close);
    mainLayout->addWidget(exitButton);

    EditRecipeWindow::loadRecipeData();
}

void EditRecipeWindow::browsePhoto()
{
    selectedPhotoPath = QFileDialog::getOpenFileName(this, "Выберите новое фото", "", "Images (*.png *.jpg)");
    if (!selectedPhotoPath.isEmpty()) {
        selectedPhotoLabel->setText("Новое фото выбрано: " + selectedPhotoPath);
    }
}

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

    if (recipeManager.updateRecipe(recipeId, name, description, ingredients, instruction, prepTime, servings, category, kitchen)) {
        accept();
    }

}

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
