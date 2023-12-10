/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionAddCategory;
    QAction *actionDeleteCategory;
    QAction *actionAddKitchen;
    QAction *actionDeleteKitchen;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *searchLineEdit;
    QPushButton *buttonFind;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QTableView *tableView1;
    QLabel *label_3;
    QTableView *tableView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonEdit;
    QPushButton *buttonAdd;
    QPushButton *buttonDelete;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(778, 719);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        actionAddCategory = new QAction(MainWindow);
        actionAddCategory->setObjectName("actionAddCategory");
        actionDeleteCategory = new QAction(MainWindow);
        actionDeleteCategory->setObjectName("actionDeleteCategory");
        actionAddKitchen = new QAction(MainWindow);
        actionAddKitchen->setObjectName("actionAddKitchen");
        actionDeleteKitchen = new QAction(MainWindow);
        actionDeleteKitchen->setObjectName("actionDeleteKitchen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        searchLineEdit = new QLineEdit(groupBox_2);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout_2->addWidget(searchLineEdit);

        buttonFind = new QPushButton(groupBox_2);
        buttonFind->setObjectName("buttonFind");

        horizontalLayout_2->addWidget(buttonFind);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_2);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");

        verticalLayout->addWidget(comboBox_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        tableView1 = new QTableView(centralwidget);
        tableView1->setObjectName("tableView1");

        verticalLayout->addWidget(tableView1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        buttonEdit = new QPushButton(groupBox);
        buttonEdit->setObjectName("buttonEdit");

        horizontalLayout->addWidget(buttonEdit);

        buttonAdd = new QPushButton(groupBox);
        buttonAdd->setObjectName("buttonAdd");

        horizontalLayout->addWidget(buttonAdd);

        buttonDelete = new QPushButton(groupBox);
        buttonDelete->setObjectName("buttonDelete");

        horizontalLayout->addWidget(buttonDelete);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 778, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action);
        menu_2->addAction(actionAddCategory);
        menu_2->addAction(actionDeleteCategory);
        menu_3->addAction(actionAddKitchen);
        menu_3->addAction(actionDeleteKitchen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
        actionAddCategory->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        actionDeleteCategory->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        actionAddKitchen->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\321\203\321\205\320\275\321\216", nullptr));
        actionDeleteKitchen->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\321\203\321\205\320\275\321\216", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        buttonFind->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262", nullptr));
        groupBox->setTitle(QString());
        buttonEdit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\261\320\273\321\216\320\264\320\276", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\261\320\273\321\216\320\264\320\276", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\261\320\273\321\216\320\264\320\276", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\205\320\275\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
