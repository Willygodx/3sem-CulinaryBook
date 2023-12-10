/********************************************************************************
** Form generated from reading UI file 'recipedetailswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEDETAILSWINDOW_H
#define UI_RECIPEDETAILSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_RecipeDetailsWindow
{
public:

    void setupUi(QDialog *RecipeDetailsWindow)
    {
        if (RecipeDetailsWindow->objectName().isEmpty())
            RecipeDetailsWindow->setObjectName("RecipeDetailsWindow");
        RecipeDetailsWindow->resize(602, 454);

        retranslateUi(RecipeDetailsWindow);

        QMetaObject::connectSlotsByName(RecipeDetailsWindow);
    } // setupUi

    void retranslateUi(QDialog *RecipeDetailsWindow)
    {
        RecipeDetailsWindow->setWindowTitle(QCoreApplication::translate("RecipeDetailsWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecipeDetailsWindow: public Ui_RecipeDetailsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEDETAILSWINDOW_H
