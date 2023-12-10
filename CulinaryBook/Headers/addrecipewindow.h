#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

#include "recipemanager.h"
#include "recipewindowbase.h"

class AddRecipeWindow : public RecipeWindowBase
{
    Q_OBJECT

public:
    explicit AddRecipeWindow(QWidget *parent = nullptr);

private slots:
    virtual void saveRecipe() override;

};

#endif // ADDRECIPEWINDOW_H
