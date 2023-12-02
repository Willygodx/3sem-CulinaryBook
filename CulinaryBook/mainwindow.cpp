#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipedetailswindow.h"
#include "addrecipewindow.h"
#include "editrecipewindow.h"
#include <QSqlRecord>
#include <QSqlField>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Кулинарный справочник");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/willygodx/Qt/qt projets/3sem-CulinaryBook-C++/DataBase/RecipeNames.db");
    if (db.open()) {

        model = new QSqlTableModel(this, db);
        model->setTable("RecipesInfo");
        model->select();
        model->setHeaderData(1, Qt::Horizontal, "Название рецепта", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Краткое описание", Qt::DisplayRole);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setColumnHidden(3, true);
        ui->tableView->setColumnHidden(4, true);
        ui->tableView->setColumnHidden(5, true);
        ui->tableView->setColumnHidden(6, true);
        ui->tableView->setColumnHidden(7, true);
        ui->tableView->setColumnHidden(8, true);
        ui->tableView->setColumnHidden(9, true);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        modelForSearch = new QSqlTableModel(this, db);
        modelForSearch->setTable("RecipesInfo");
        modelForSearch->setFilter("1 = 0");
        modelForSearch->select();
        modelForSearch->setHeaderData(1, Qt::Horizontal, "Название рецепта", Qt::DisplayRole);
        modelForSearch->setHeaderData(2, Qt::Horizontal, "Краткое описание", Qt::DisplayRole);
        modelForSearch->setEditStrategy(QSqlTableModel::OnManualSubmit);

        ui->tableView1->setModel(modelForSearch);
        ui->tableView1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView1->setColumnHidden(0, true);
        ui->tableView1->setColumnHidden(3, true);
        ui->tableView1->setColumnHidden(4, true);
        ui->tableView1->setColumnHidden(5, true);
        ui->tableView1->setColumnHidden(6, true);
        ui->tableView1->setColumnHidden(7, true);
        ui->tableView1->setColumnHidden(8, true);
        ui->tableView1->setColumnHidden(9, true);
        ui->tableView1->setSortingEnabled(true);
        ui->tableView1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    } else {
        ui->statusbar->showMessage("Error! Database not found!");
    }

}


MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_action_triggered()
{
    QApplication::quit();
}

void MainWindow::on_buttonDelete_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    QModelIndex index1 = ui->tableView1->currentIndex();

    if (index.isValid()) {
        int recipeId = model->data(model->index(index.row(), 0)).toInt();

        RecipeManager recipeManager(model);
        if (recipeManager.deleteRecipeById(recipeId)) {
            QMessageBox::information(this, "Успех", "Рецепт удален.");
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при удалении рецепта.");
        }
    } else if (index1.isValid()) {
        int recipeId = modelForSearch->data(model->index(index1.row(), 0)).toInt();

        RecipeManager recipeManager(modelForSearch);
        if (recipeManager.deleteRecipeById(recipeId)) {
            QMessageBox::information(this, "Успех", "Рецепт удален.");
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при удалении рецепта.");
        }
    }

    ui->tableView1->selectionModel()->clear();
    ui->tableView->selectionModel()->clear();
}

void MainWindow::on_buttonFind_clicked()
{
    QString searchText = ui->searchLineEdit->text().trimmed();
    QString category = ui->comboBox->currentText();
    QString queryStr = "SELECT * FROM RecipesInfo WHERE ";

    if (!searchText.isEmpty()) {
        queryStr += "(name LIKE :searchText)";
    } else {
        queryStr += "1";
    }

    if (category != "Все категории") {
        queryStr += " AND ";
        queryStr += "category = :category";
    }

    QSqlQuery query;
    query.prepare(queryStr);

    if (!searchText.isEmpty()) {
        query.bindValue(":searchText", "%" + searchText + "%");
    }
    if (category != "Все категории") {
        query.bindValue(":category", category);
    }

    if (query.exec()) {
        modelForSearch->setQuery(query);
        ui->tableView1->setModel(modelForSearch);
    } else {
        qDebug() << "SQL Query Error:" << query.lastError().text();
    }

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int recipeId = model->data(model->index(index.row(), 0)).toInt();
    RecipeManager recipeManager(model);
    Recipe recipe = recipeManager.getRecipeById(recipeId);
        RecipeDetailsWindow *detailsWindow = new RecipeDetailsWindow(recipe, this);
        detailsWindow->exec();
}


void MainWindow::on_tableView1_doubleClicked(const QModelIndex &index)
{
    int recipeId = modelForSearch->data(model->index(index.row(), 0)).toInt();
    RecipeManager recipeManager(modelForSearch);
    Recipe recipe = recipeManager.getRecipeById(recipeId);
    RecipeDetailsWindow *detailsWindow = new RecipeDetailsWindow(recipe, this);
    detailsWindow->exec();
}

void MainWindow::on_buttonEdit_clicked()
{
    RecipeManager recipeManager;
    int recipeId = recipeManager.getRecipeIdFromIndex(ui->tableView->selectionModel()->currentIndex(), model);
    int recipeIdForSearch = recipeManager.getRecipeIdFromIndex(ui->tableView1->selectionModel()->currentIndex(), modelForSearch);

    if (recipeId != -1) {
        EditRecipeWindow *editWindow = new EditRecipeWindow(recipeId, this);
        editWindow->exec();
    } else if (recipeIdForSearch != -1) {
        EditRecipeWindow *editWindow = new EditRecipeWindow(recipeIdForSearch, this);
        editWindow->exec();
    } else {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите рецепт для редактирования.");
    }

    ui->tableView1->selectionModel()->clear();
    ui->tableView->selectionModel()->clear();
}

void MainWindow::on_buttonAdd_clicked()
{
    AddRecipeWindow *addingWindow = new AddRecipeWindow(this);
    addingWindow->exec();
}

void MainWindow::on_tableView_clicked()
{
    ui->tableView1->selectionModel()->clear();
}


void MainWindow::on_tableView1_clicked()
{
    ui->tableView->selectionModel()->clear();
}


void MainWindow::on_comboBox_currentIndexChanged()
{
    QString category = ui->comboBox->currentText();
    QString queryString;
    if (category == "Все категории") {
        queryString = "SELECT * FROM RecipesInfo";
    } else {
        queryString = "SELECT * FROM RecipesInfo WHERE category = :category";
    }

    QSqlQuery query;
    query.prepare(queryString);

    if (category != "Все категории") {
        query.bindValue(":category", category);
    }

    if (query.exec()) {
        model->setQuery(query);
        modelForSearch->setQuery(query);
        modelForSearch->setFilter("1 = 0");
        modelForSearch->select();
        ui->tableView->setModel(model);
        ui->tableView1->setModel(modelForSearch);
    } else {
        qDebug() << "SQL Query Error: " << query.lastError().text();
    }
}


void MainWindow::on_comboBox_2_currentIndexChanged()
{
    QString kitchen = ui->comboBox_2->currentText();
    QString queryString;
    if (kitchen == "Все кухни") {
        queryString = "SELECT * FROM RecipesInfo";
    } else {
        queryString = "SELECT * FROM RecipesInfo WHERE kitchen = :kitchen";
    }

    QSqlQuery query;
    query.prepare(queryString);

    if (kitchen != "Все кухни") {
        query.bindValue(":kitchen", kitchen);
    }

    if (query.exec()) {
        model->setQuery(query);
        modelForSearch->setQuery(query);
        modelForSearch->setFilter("1 = 0");
        modelForSearch->select();
        ui->tableView->setModel(model);
        ui->tableView1->setModel(modelForSearch);
    } else {
        qDebug() << "SQL Query Error: " << query.lastError().text();
    }
}

