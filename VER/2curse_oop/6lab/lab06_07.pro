#-------------------------------------------------
# Проект для сборки при помощи qmake
# Запуск в терминале:
#   qmake
#   make
#   ./lab06_07
#-------------------------------------------------

QT       += core gui       # Подключение QtCore и QtGui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  # Подключение модуля Widgets (с Qt5+)

TARGET = lab06_07
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h
