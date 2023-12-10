#include "recipewindowbase.h"

RecipeWindowBase::RecipeWindowBase(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

RecipeWindowBase::~RecipeWindowBase()
{

}

void RecipeWindowBase::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *formLayout = new QVBoxLayout();

    titleLabel = new QLabel("Введите данные о рецепте.");
    formLayout->addWidget(titleLabel);

    categoryLabel = new QLabel("Категория:");
    categoryComboBox = new QComboBox();
    formLayout->addWidget(categoryLabel);
    formLayout->addWidget(categoryComboBox);
    loadComboBoxItems(categoryComboBox, categoryPath);

    kitchenLabel = new QLabel("Кухня: ");
    kitchenComboBox = new QComboBox();
    formLayout->addWidget(kitchenLabel);
    formLayout->addWidget(kitchenComboBox);
    loadComboBoxItems(kitchenComboBox, kitchenPath);

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
    connect(browsePhotoButton, &QPushButton::clicked, this, &RecipeWindowBase::browsePhoto);

    QHBoxLayout *photoLayout = new QHBoxLayout();
    photoLayout->addWidget(photoLabel);
    photoLayout->addWidget(selectedPhotoLabel);
    photoLayout->addWidget(browsePhotoButton);

    formLayout->addLayout(photoLayout);
    mainLayout->addLayout(formLayout);

    saveButton = new QPushButton("Сохранить");
    connect(saveButton, &QPushButton::clicked, this, &RecipeWindowBase::saveRecipe);
    mainLayout->addWidget(saveButton);

    exitButton = new QPushButton("Закрыть");
    connect(exitButton, &QPushButton::clicked, this, &RecipeWindowBase::close);
    mainLayout->addWidget(exitButton);
}

void RecipeWindowBase::browsePhoto()
{
    selectedPhotoPath = QFileDialog::getOpenFileName(this, "Выберите фото", "", "Images (*.png *.jpg)");
    if (!selectedPhotoPath.isEmpty()) {
        selectedPhotoLabel->setText("Фото выбрано: " + selectedPhotoPath);
    }
}

void RecipeWindowBase::loadComboBoxItems(QComboBox *comboBox, const QString &filePath)
{
    ComboBoxLoader comboBoxLoader;
    comboBoxLoader.loadComboBoxItems(comboBox, filePath);
}
