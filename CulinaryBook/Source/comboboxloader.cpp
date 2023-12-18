#include "Headers/comboboxloader.h"

// Функция для выгрузки данных из .txt файла в виджет ComboBox
void ComboBoxLoader::loadComboBoxItems(QComboBox* comboBox, const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            comboBox->addItem(line);
        }

        file.close();
    }
}

// Функция для сохранения данных в .txt файл из виджета ComboBox
void ComboBoxLoader::saveComboBoxItems(QComboBox* comboBox, const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (int i = 0; i < comboBox->count(); ++i) {
            out << comboBox->itemText(i) << "\n";
        }

        file.close();
    }
}
