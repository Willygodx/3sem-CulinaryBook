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
    bool updateRecipeInfo(int recipeId, const Recipe& recipe);

public:
    RecipeManager();
    RecipeManager(QSqlTableModel *model);
    ~RecipeManager();

    bool deleteRecipeById(int recipeId);
    int getRecipeRowById(int recipeId);
    Recipe getRecipeById(int recipeId);
    int getRecipeIdFromIndex(const QModelIndex &index, QSqlQueryModel *model);
    void addRecipeToDatabase(const Recipe& recipe, const QString& photoPath);
    bool updateRecipe(int recipeId, const Recipe& recipe);
};

#endif // RECIPEMANAGER_H
