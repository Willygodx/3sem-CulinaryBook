#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Кулинарный справочник");

    dbManager = new DatabaseManager("/Users/willygodx/Qt/qt projets/3sem-CulinaryBook-C++/DataBase/RecipeNames.db");
    if (dbManager->openDatabase()) {
        model = dbManager->createRecipeModel();

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

        modelForSearch = dbManager->createRecipeModelForSearch();

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
    comboBoxLoader->loadComboBoxItems(ui->comboBox, categoryPath);
    comboBoxLoader->loadComboBoxItems(ui->comboBox_2, kitchenPath);
}

MainWindow::~MainWindow()
{
    dbManager->closeDatabase();
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
    QString kitchen = ui->comboBox_2->currentText();
    QString queryStr = "SELECT * FROM RecipesInfo WHERE ";

    if (!searchText.isEmpty()) {
        queryStr += "(name LIKE :searchText)";
    } else {
        queryStr += "1";
    }

    if (category != "Все категории") {
        queryStr += " AND category = :category";
    }

    if (kitchen != "Все кухни") {
        queryStr += " AND kitchen = :kitchen";
    }

    QSqlQuery query;
    query.prepare(queryStr);

    if (!searchText.isEmpty()) {
        query.bindValue(":searchText", "%" + searchText + "%");
    }
    if (category != "Все категории") {
        query.bindValue(":category", category);
    }
    if (kitchen != "Все кухни") {
        query.bindValue(":kitchen", kitchen);
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
    model->select();
    modelForSearch->select();
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
    QString kitchen = ui->comboBox_2->currentText();
    updateRecipeView(category, kitchen);
}


void MainWindow::on_comboBox_2_currentIndexChanged()
{
    QString kitchen = ui->comboBox_2->currentText();
    QString category = ui->comboBox->currentText();
    updateRecipeView(category, kitchen);
}

void MainWindow::updateRecipeView(const QString& category, const QString& kitchen)
{
    QString queryString = "SELECT * FROM RecipesInfo WHERE ";

    if (category == "Все категории" && kitchen == "Все кухни") {
        queryString = "SELECT * FROM RecipesInfo";
    } else if (category == "Все категории") {
        queryString += "kitchen = :kitchen";
    } else if (kitchen == "Все кухни") {
        queryString += "category = :category";
    } else {
        queryString += "category = :category AND kitchen = :kitchen";
    }

    QSqlQuery query;
    query.prepare(queryString);

    if (category != "Все категории") {
        query.bindValue(":category", category);
    }
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


void MainWindow::on_actionAddCategory_triggered()
{
    bool ok;
    QString newItem = QInputDialog::getText(this, tr("Добавление"), tr("Введите новую категорию:"), QLineEdit::Normal, "", &ok);
    if (ok && !newItem.isEmpty())
    {
        ui->comboBox->addItem(newItem);
        comboBoxLoader->saveComboBoxItems(ui->comboBox, categoryPath);
    }
}

void MainWindow::on_actionDeleteCategory_triggered()
{
    int currentIndex = ui->comboBox->currentIndex();
    if (currentIndex != -1)
    {
        QString currentItemText = ui->comboBox->itemText(currentIndex);
        if (currentItemText != "Все категории")
        {
            ui->comboBox->removeItem(currentIndex);
            comboBoxLoader->saveComboBoxItems(ui->comboBox, categoryPath);
        }
        else
        {
            QMessageBox::warning(this, tr("Предупреждение"), tr("Нельзя удалить выбранную категорию."), QMessageBox::Ok);
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Предупреждение"), tr("Выберите категорию для удаления."), QMessageBox::Ok);
    }
}

void MainWindow::on_actionAddKitchen_triggered()
{
    bool ok;
    QString newItem = QInputDialog::getText(this, tr("Добавление"), tr("Введите новую кухню:"), QLineEdit::Normal, "", &ok);
    if (ok && !newItem.isEmpty())
    {
        ui->comboBox_2->addItem(newItem);
        comboBoxLoader->saveComboBoxItems(ui->comboBox_2, kitchenPath);
    }
}


void MainWindow::on_actionDeleteKitchen_triggered()
{
    int currentIndex = ui->comboBox_2->currentIndex();
    if (currentIndex != -1)
    {
        QString currentItemText = ui->comboBox_2->itemText(currentIndex);
        if (currentItemText != "Все кухни" || currentItemText != "Неопределенная кухня")
        {
            ui->comboBox_2->removeItem(currentIndex);
            comboBoxLoader->saveComboBoxItems(ui->comboBox_2, kitchenPath);
        }
        else
        {
            QMessageBox::warning(this, tr("Предупреждение"), tr("Нельзя удалить выбранную кухню."), QMessageBox::Ok);
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Предупреждение"), tr("Выберите кухню для удаления."), QMessageBox::Ok);
    }
}

