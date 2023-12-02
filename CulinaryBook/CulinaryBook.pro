QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Source/addrecipewindow.cpp \
    Source/editrecipewindow.cpp \
    Source/main.cpp \
    Source/mainwindow.cpp \
    Source/recipe.cpp \
    Source/recipedetailswindow.cpp \
    Source/recipemanager.cpp

HEADERS += \
   Headers/addrecipewindow.h \
   Headers/editrecipewindow.h \
   Headers/mainwindow.h \
   Headers/recipe.h \
   Headers/recipedetailswindow.h \
   Headers/recipemanager.h

FORMS += \
    FORMS/addrecipewindow.ui \
    FORMS/editrecipewindow.ui \
    FORMS/mainwindow.ui \
    FORMS/recipedetailswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
