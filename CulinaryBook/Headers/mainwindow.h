#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipemanager.h"
#include "databasemanager.h"
#include "Headers/recipedetailswindow.h"
#include "Headers/addrecipewindow.h"
#include "Headers/editrecipewindow.h"
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_buttonAdd_clicked();

    void on_buttonDelete_clicked();

    void on_buttonFind_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView1_doubleClicked(const QModelIndex &index);

    void on_buttonEdit_clicked();

    void on_tableView_clicked();

    void on_tableView1_clicked();

    void on_comboBox_currentIndexChanged();

    void on_comboBox_2_currentIndexChanged();

    void updateRecipeView(const QString& category, const QString& kitchen);

    void on_actionAddCategory_triggered();

    void on_actionDeleteCategory_triggered();

    void on_actionAddKitchen_triggered();

    void on_actionDeleteKitchen_triggered();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlTableModel *modelForSearch;
    int currentRow;
    DatabaseManager *dbManager;
    ComboBoxLoader *comboBoxLoader;

    // ДЛЯ СБОРКИ ПРОЕКТА НА ДРУГОМ УСТРОЙСТВЕ НЕОБХОДИМО ПОМЕНЯТЬ ПУТИ
    const QString categoryPath = "/Users/willygodx/Qt/qt projets/3sem-CulinaryBook-C++/DataBase/comboBoxCategoryInfo.txt";
    const QString kitchenPath = "/Users/willygodx/Qt/qt projets/3sem-CulinaryBook-C++/DataBase/comboBoxKitchenInfo.txt";
};
#endif // MAINWINDOW_H
