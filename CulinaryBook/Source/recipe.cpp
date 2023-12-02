#include "Headers/recipe.h"

Recipe::Recipe() : recipeId(-1), prepTime(0), servings(0) {}

Recipe::Recipe(int recipeId, const QString &name, const QString &description, const QString &ingredients, const QString &instruction, int prepTime, int servings, const QByteArray &photo, const QString &category, const QString &kitchen)
    : recipeId(recipeId), name(name), description(description), ingredients(ingredients),instruction(instruction), prepTime(prepTime), servings(servings), photo(photo), category(category), kitchen(kitchen) {}

int Recipe::getRecipeId() const {
    return recipeId;
}

QString Recipe::getName() const {
    return name;
}

QString Recipe::getDescription() const {
    return description;
}

QString Recipe::getIngredients() const {
    return ingredients;
}

QString Recipe::getInstruction() const {
    return instruction;
}

int Recipe::getPrepTime() const {
    return prepTime;
}

int Recipe::getServings() const {
    return servings;
}

QByteArray Recipe::getPhoto() const {
    return photo;
}

QString Recipe::getCategory() const {
    return category;
}

QString Recipe::getKitchen() const {
    return kitchen;
}

void Recipe::setRecipeId(int recipeId) {
    this->recipeId = recipeId;
}

void Recipe::setName(const QString &name) {
    this->name = name;
}

void Recipe::setDescription(const QString &description) {
    this->description = description;
}

void Recipe::setIngredients(const QString &ingredients) {
    this->ingredients = ingredients;
}

void Recipe::setInstruction(const QString &instruction) {
    this->instruction = instruction;
}

void Recipe::setPrepTime(int prepTime) {
    this->prepTime = prepTime;
}

void Recipe::setServings(int servings) {
    this->servings = servings;
}

void Recipe::setPhoto(const QByteArray &photo) {
    this->photo = photo;
}

void Recipe::setCategory(const QString &category) {
    this->category = category;
}

void Recipe::setKitchen(const QString &kitchen) {
    this->kitchen = kitchen;
}

Recipe::~Recipe() {

}
