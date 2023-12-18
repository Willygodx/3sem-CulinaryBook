#include "Headers/recipe.h"

// Конструктор для класса рецепта. Уникальный номер рецепта по-умолчанию "-1"
Recipe::Recipe() : recipeId(-1), prepTime(0), servings(0) {}

// Конструктор для класса рецепта со всеми параметрами
Recipe::Recipe(int recipeId, const QString &name, const QString &description, const QString &ingredients, const QString &instruction, int prepTime, int servings, const QByteArray &photo, const QString &category, const QString &kitchen)
    : recipeId(recipeId), name(name), description(description), ingredients(ingredients),instruction(instruction), prepTime(prepTime), servings(servings), photo(photo), category(category), kitchen(kitchen) {}

// Геттер для уникального номера рецепта
int Recipe::getRecipeId() const {
    return recipeId;
}

// Геттер для названия рецепта
QString Recipe::getName() const {
    return name;
}

// Геттер для краткого описания рецепта
QString Recipe::getDescription() const {
    return description;
}

// Геттер для ингредиентов рецепта
QString Recipe::getIngredients() const {
    return ingredients;
}

// Геттер для инструкции по приготовлению
QString Recipe::getInstruction() const {
    return instruction;
}

// Геттер для времени приготовления
int Recipe::getPrepTime() const {
    return prepTime;
}

// Геттер для количества порций
int Recipe::getServings() const {
    return servings;
}

// Геттер для фотографии блюда
QByteArray Recipe::getPhoto() const {
    return photo;
}

// Геттер для категории блюда
QString Recipe::getCategory() const {
    return category;
}

// Геттер для происхождения рецепта
QString Recipe::getKitchen() const {
    return kitchen;
}

// Сеттер для уникального номера рецепта
void Recipe::setRecipeId(int recipeId) {
    this->recipeId = recipeId;
}

// Сеттер для названия рецепта
void Recipe::setName(const QString &name) {
    this->name = name;
}

// Сеттер для краткого описания рецепта
void Recipe::setDescription(const QString &description) {
    this->description = description;
}

// Сеттер для ингредиентов
void Recipe::setIngredients(const QString &ingredients) {
    this->ingredients = ingredients;
}

// Сеттер для инструкции по приготовлению
void Recipe::setInstruction(const QString &instruction) {
    this->instruction = instruction;
}

// Сеттер для времени приготовления
void Recipe::setPrepTime(int prepTime) {
    this->prepTime = prepTime;
}

// Сеттер для количества порций
void Recipe::setServings(int servings) {
    this->servings = servings;
}

// Сеттер для фотографии блюда
void Recipe::setPhoto(const QByteArray &photo) {
    this->photo = photo;
}

// Сеттер для категории блюда
void Recipe::setCategory(const QString &category) {
    this->category = category;
}

// Сеттер для происхождения блюда
void Recipe::setKitchen(const QString &kitchen) {
    this->kitchen = kitchen;
}

// Деструктор
Recipe::~Recipe() {

}
