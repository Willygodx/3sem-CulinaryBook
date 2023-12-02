#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H
#include "recipe.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QMessageBox>

class RecipeManager
{

private:
    QSqlTableModel *model;
    bool updateRecipeInfo(int recipeId, const QString& name, const QString& description, const QString& ingredients, const QString& instruction, int prepTime, int servings, const QString& category, const QString& kitchen);

public:
    RecipeManager();
    RecipeManager(QSqlTableModel *model);
    ~RecipeManager();

    bool deleteRecipeById(int recipeId);
    int getRecipeRowById(int recipeId);
    Recipe getRecipeById(int recipeId);
    int getRecipeIdFromIndex(const QModelIndex &index, QSqlQueryModel *model);
    void addRecipeToDatabase(const Recipe& recipe, const QString& photoPath);
    bool updateRecipe(int recipeId, const QString& name, const QString& description, const QString& ingredients, const QString& instruction, int prepTime, int servings, const QString& category, const QString& kitchen);
};

#endif // RECIPEMANAGER_H
