#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

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
#include "recipe.h"
#include <QMessageBox>
#include <QBuffer>
#include "recipemanager.h"
#include <QSqlError>
#include <QComboBox>

class AddRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    AddRecipeWindow(QWidget *parent = nullptr);

private slots:
    void browsePhoto();
    void saveRecipe();

private:
    QLabel *titleLabel;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *descriptionLabel;
    QTextEdit *descriptionTextEdit;
    QLabel *ingredientsLabel;
    QTextEdit *ingredientsTextEdit;
    QLabel *instructionLabel;
    QTextEdit *instructionTextEdit;
    QLabel *prepTimeLabel;
    QSpinBox *prepTimeSpinBox;
    QLabel *servingsLabel;
    QSpinBox *servingsSpinBox;
    QLabel *photoLabel;
    QLabel *selectedPhotoLabel;
    QPushButton *browsePhotoButton;
    QPushButton *saveButton;
    QPushButton *exitButton;
    QString selectedPhotoPath;
    QLabel *categoryLabel;
    QComboBox *categoryComboBox;
    QLabel *kitchenLabel;
    QComboBox *kitchenComboBox;
};

#endif // ADDRECIPEWINDOW_H
