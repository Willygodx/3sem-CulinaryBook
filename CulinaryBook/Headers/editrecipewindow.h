#ifndef EDITRECIPEWINDOW_H
#define EDITRECIPEWINDOW_H

#include "recipemanager.h"
#include "recipewindowbase.h"

class EditRecipeWindow : public RecipeWindowBase
{
    Q_OBJECT

public:
    explicit EditRecipeWindow(int recipeId, QWidget* parent = nullptr);

private slots:
    virtual void saveRecipe() override;
    void loadRecipeData();

private:
    int recipeId;
};

#endif // EDITRECIPEWINDOW_H
