#ifndef RECIPEDETAILSWINDOW_H
#define RECIPEDETAILSWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "recipe.h"


namespace Ui {
class RecipeDetailsWindow;
}

class RecipeDetailsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeDetailsWindow(QWidget *parent = nullptr);
    RecipeDetailsWindow(const Recipe &recipe, QWidget *parent);
    ~RecipeDetailsWindow();

private:
    Ui::RecipeDetailsWindow *ui;
    QLabel *recipeNameLabel;
    QLabel *descriptionLabel;
    QLabel *ingredientsLabel;
    QLabel *instructionLabel;
    QLabel *prepTimeLabel;
    QLabel *servingsLabel;
    QLabel *photoLabel;
    QLabel *kitchenLabel;
    QPushButton *exitButton;
};

#endif // RECIPEDETAILSWINDOW_H
