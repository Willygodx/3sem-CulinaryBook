#ifndef RECIPE_H
#define RECIPE_H
#include <QString>

class Recipe
{
private:
    int recipeId;
    QString name;
    QString description;
    QString ingredients;
    QString instruction;
    int prepTime;
    int servings;
    QByteArray photo;
    QString category;
    QString kitchen;

public:
    Recipe();
    Recipe(int recipeId, const QString &name, const QString &description, const QString &ingredients, const QString &instruction, int prepTime, int servings, const QByteArray &photo, const QString &category, const QString &kitchen);
    ~Recipe();

    int getRecipeId() const;
    QString getName() const;
    QString getDescription() const;
    QString getIngredients() const;
    QString getInstruction() const;
    int getPrepTime() const;
    int getServings() const;
    QByteArray getPhoto() const;
    QString getCategory() const;
    QString getKitchen() const;

    void setRecipeId(int recipeId);
    void setName(const QString &name);
    void setDescription(const QString &description);
    void setIngredients(const QString &ingredients);
    void setInstruction(const QString &instruction);
    void setPrepTime(int prepTime);
    void setServings(int servings);
    void setPhoto(const QByteArray &photo);
    void setCategory(const QString &category);
    void setKitchen(const QString &kitchen);

};

#endif // RECIPE_H
