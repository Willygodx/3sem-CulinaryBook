#include "Headers/recipedetailswindow.h"
#include "ui_recipedetailswindow.h"

RecipeDetailsWindow::RecipeDetailsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipeDetailsWindow)
{
    ui->setupUi(this);
}

RecipeDetailsWindow::~RecipeDetailsWindow()
{
    delete ui;
}

RecipeDetailsWindow::RecipeDetailsWindow(const Recipe &recipe, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(recipe.getName());

    QVBoxLayout *layout = new QVBoxLayout(this);

    kitchenLabel = new QLabel(recipe.getKitchen(), this);
    layout->addWidget(kitchenLabel);

    recipeNameLabel = new QLabel("Название рецепта: " + recipe.getName() + " (" + recipe.getCategory() + ")", this);
    layout->addWidget(recipeNameLabel);

    if (!recipe.getDescription().isEmpty()) {
        descriptionLabel = new QLabel("Описание: " + recipe.getDescription(), this);
        layout->addWidget(descriptionLabel);
    }

    if (!recipe.getIngredients().isEmpty()) {
        ingredientsLabel = new QLabel("Ингредиенты:\n" + recipe.getIngredients(), this);
        layout->addWidget(ingredientsLabel);
    }

    if (!recipe.getInstruction().isEmpty()) {
        instructionLabel = new QLabel("Инструкция:\n" + recipe.getInstruction(), this);
        layout->addWidget(instructionLabel);
    }

    prepTimeLabel = new QLabel("Время приготовления: " + QString::number(recipe.getPrepTime()) + " мин", this);
    layout->addWidget(prepTimeLabel);

    servingsLabel = new QLabel("Порции: " + QString::number(recipe.getServings()), this);
    layout->addWidget(servingsLabel);

    if (!recipe.getPhoto().isEmpty()) {
        QLabel *photoLabel = new QLabel(this);
        QPixmap photo;
        photo.loadFromData(recipe.getPhoto());
        photoLabel->setPixmap(photo);
        QPixmap resizedPhoto = photo.scaled(540, 340, Qt::KeepAspectRatio);
        photoLabel->setPixmap(resizedPhoto);
        layout->addWidget(photoLabel);
    }

    exitButton = new QPushButton("Закрыть");
    connect(exitButton, &QPushButton::clicked, this, &RecipeDetailsWindow::close);
    layout->addWidget(exitButton);

}
