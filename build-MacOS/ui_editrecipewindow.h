/********************************************************************************
** Form generated from reading UI file 'editrecipewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRECIPEWINDOW_H
#define UI_EDITRECIPEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_EditRecipeWindow
{
public:

    void setupUi(QDialog *EditRecipeWindow)
    {
        if (EditRecipeWindow->objectName().isEmpty())
            EditRecipeWindow->setObjectName("EditRecipeWindow");
        EditRecipeWindow->resize(615, 473);

        retranslateUi(EditRecipeWindow);

        QMetaObject::connectSlotsByName(EditRecipeWindow);
    } // setupUi

    void retranslateUi(QDialog *EditRecipeWindow)
    {
        EditRecipeWindow->setWindowTitle(QCoreApplication::translate("EditRecipeWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRecipeWindow: public Ui_EditRecipeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRECIPEWINDOW_H
