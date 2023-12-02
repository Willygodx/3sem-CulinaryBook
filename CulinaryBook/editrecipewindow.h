#ifndef EDITRECIPEWINDOW_H
#define EDITRECIPEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlRecord>
#include <QSqlError>
#include "recipe.h"
#include "recipemanager.h"
#include <QMessageBox>
#include <QComboBox>

class EditRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    EditRecipeWindow(int recipeId, QWidget* parent = nullptr);

private slots:
    void browsePhoto();
    void saveRecipe();
    void loadRecipeData();

private:
    QLabel* titleLabel;
    QLabel* nameLabel;
    QLineEdit* nameLineEdit;
    QLabel* descriptionLabel;
    QTextEdit* descriptionTextEdit;
    QLabel* ingredientsLabel;
    QTextEdit* ingredientsTextEdit;
    QLabel* instructionLabel;
    QTextEdit* instructionTextEdit;
    QLabel* prepTimeLabel;
    QSpinBox* prepTimeSpinBox;
    QLabel* servingsLabel;
    QSpinBox* servingsSpinBox;
    QLabel* photoLabel;
    QLabel* selectedPhotoLabel;
    QPushButton* browsePhotoButton;
    QPushButton* saveButton;
    QPushButton *exitButton;
    QString selectedPhotoPath;
    int recipeId;
    QLabel *categoryLabel;
    QComboBox *categoryComboBox;
    QLabel *kitchenLabel;
    QComboBox *kitchenComboBox;
};

#endif // EDITRECIPEWINDOW_H
