/********************************************************************************
** Form generated from reading UI file 'addrecipewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECIPEWINDOW_H
#define UI_ADDRECIPEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AddRecipeWindow
{
public:

    void setupUi(QDialog *AddRecipeWindow)
    {
        if (AddRecipeWindow->objectName().isEmpty())
            AddRecipeWindow->setObjectName("AddRecipeWindow");
        AddRecipeWindow->resize(622, 471);

        retranslateUi(AddRecipeWindow);

        QMetaObject::connectSlotsByName(AddRecipeWindow);
    } // setupUi

    void retranslateUi(QDialog *AddRecipeWindow)
    {
        AddRecipeWindow->setWindowTitle(QCoreApplication::translate("AddRecipeWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRecipeWindow: public Ui_AddRecipeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECIPEWINDOW_H
