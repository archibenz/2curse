#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QTableWidget>
#include "moviecontainer.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void showAbout();
    void addMovie();
    void removeMovie();
    void searchMovie();
    void editMovie();
    void loadFromFile();
    void saveToFile();
    void mergeWithAnotherDB();

private:
    void createMenu();
    void createToolbar();
    void createContextMenu();
    void createStatusBar();
    void refreshTable();
    bool maybeSave();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *aboutAction;
    QAction *addAction;
    QAction *removeAction;
    QAction *searchAction;
    QAction *editAction;
    QAction *loadAction;
    QAction *saveAction;
    QAction *mergeAction;

    QToolBar *toolbar;
    QTableWidget *table;

    MovieContainer movieDB;
};

#endif // MAINWINDOW_H

