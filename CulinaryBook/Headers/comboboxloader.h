#ifndef COMBOBOXLOADER_H
#define COMBOBOXLOADER_H

#include <QComboBox>
#include <QFile>
#include <QTextStream>

class ComboBoxLoader
{
public:
    ComboBoxLoader() = default;
    void loadComboBoxItems(QComboBox* comboBox, const QString& filePath);
    void saveComboBoxItems(QComboBox* comboBox, const QString& filePath);
};

#endif // COMBOBOXLOADER_H
