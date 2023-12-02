#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "recipe.h"


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

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlTableModel *modelForSearch;
    QSqlTableModel *modelForDelete;
    int currentRow;

protected:
    bool isRecipeEdited;
};
#endif // MAINWINDOW_H
