#ifndef RECIPEWINDOWBASE_H
#define RECIPEWINDOWBASE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFileDialog>
#include "comboboxloader.h"

class RecipeWindowBase : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeWindowBase(QWidget *parent = nullptr);
    ~RecipeWindowBase();

private:
    const QString categoryPath = "/Users/willygodx/Qt/qt projets/3sem-CulinaryBook-C++/DataBase/comboBoxCategoryInfo.txt";
    const QString kitchenPath = "/Users/willygodx/Qt/qt projets/3sem-CulinaryBook-C++/DataBase/comboBoxKitchenInfo.txt";

private slots:
    void browsePhoto();
    virtual void saveRecipe() = 0;

protected:
    void setupUI();
    void loadComboBoxItems(QComboBox *comboBox, const QString &filePath);

    QLabel *titleLabel;
    QLabel *categoryLabel;
    QComboBox *categoryComboBox;
    QLabel *kitchenLabel;
    QComboBox *kitchenComboBox;
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
};

#endif // RECIPEWINDOWBASE_H
