# project.pro

QT += core gui widgets

CONFIG += c++17
CONFIG += release
# Если нужен отладочный вариант:
# CONFIG += debug

# Путь к исходникам и заголовочным файлам
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    moviecontainer.cpp \
    aboutdialog.cpp

HEADERS += \
    mainwindow.h \
    movie.h \
    moviecontainer.h \
    aboutdialog.h \
    mycontainer.h

# Если у вас нет форм (UI файлов), этот раздел можно пропустить.
# FORMS +=

# Дополнительные пути к включаемым заголовкам, если нужны
# INCLUDEPATH += /some/custom/path

# Дополнительные библиотеки, если нужны:
# LIBS += -L/some/lib/path -lmylib

