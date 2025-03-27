#include "mainwindow.h"
#include "aboutdialog.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QContextMenuEvent>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("База данных фильмов");
    resize(800, 600);

    table = new QTableWidget(this);
    table->setColumnCount(4);
    QStringList headers;
    headers << tr("Title") << tr("Director") << tr("Year") << tr("Genre");
    table->setHorizontalHeaderLabels(headers);
    setCentralWidget(table);

    createMenu();
    createToolbar();
    createStatusBar();
    createContextMenu();
}

MainWindow::~MainWindow() {}

void MainWindow::createMenu() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    loadAction = new QAction(tr("Load..."), this);
    loadAction->setToolTip(tr("Load database from file"));
    saveAction = new QAction(tr("Save..."), this);
    saveAction->setToolTip(tr("Save database to file"));
    mergeAction = new QAction(tr("Merge..."), this);
    mergeAction->setToolTip(tr("Merge with another database file"));
    fileMenu->addAction(loadAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(mergeAction);

    connect(loadAction, &QAction::triggered, this, &MainWindow::loadFromFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveToFile);
    connect(mergeAction, &QAction::triggered, this, &MainWindow::mergeWithAnotherDB);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    addAction = new QAction(tr("Add Movie"), this);
    addAction->setToolTip(tr("Add a new movie to the database"));
    removeAction = new QAction(tr("Remove Movie"), this);
    removeAction->setToolTip(tr("Remove a movie by title"));
    searchAction = new QAction(tr("Search Movie"), this);
    searchAction->setToolTip(tr("Search movies by director or year"));
    editAction = new QAction(tr("Edit Movie"), this);
    editAction->setToolTip(tr("Edit an existing movie"));
    editMenu->addAction(addAction);
    editMenu->addAction(removeAction);
    editMenu->addAction(editAction);
    editMenu->addAction(searchAction);

    connect(addAction, &QAction::triggered, this, &MainWindow::addMovie);
    connect(removeAction, &QAction::triggered, this, &MainWindow::removeMovie);
    connect(searchAction, &QAction::triggered, this, &MainWindow::searchMovie);
    connect(editAction, &QAction::triggered, this, &MainWindow::editMovie);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    aboutAction = new QAction(tr("About"), this);
    helpMenu->addAction(aboutAction);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
}

void MainWindow::createToolbar() {
    toolbar = addToolBar(tr("Main Toolbar"));
    toolbar->addAction(addAction);
    toolbar->addAction(removeAction);
    toolbar->addAction(editAction);
    toolbar->addAction(searchAction);
    toolbar->addAction(loadAction);
    toolbar->addAction(saveAction);
    toolbar->addAction(mergeAction);
    toolbar->setToolTip(tr("Use the toolbar to manage movies"));
}

void MainWindow::createContextMenu() {
    setContextMenuPolicy(Qt::DefaultContextMenu);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    QMenu menu(this);
    menu.addAction(addAction);
    menu.addAction(removeAction);
    menu.addAction(editAction);
    menu.addAction(searchAction);
    menu.addAction(loadAction);
    menu.addAction(saveAction);
    menu.addAction(mergeAction);
    menu.exec(event->globalPos());
}

void MainWindow::createStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::showAbout() {
    AboutDialog dlg(this);
    dlg.exec();
}

void MainWindow::addMovie() {
    bool ok;
    QString title = QInputDialog::getText(this, tr("Add Movie"), tr("Title:"), QLineEdit::Normal, "", &ok);
    if (!ok || title.isEmpty()) return;
    QString director = QInputDialog::getText(this, tr("Add Movie"), tr("Director:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;
    int year = QInputDialog::getInt(this, tr("Add Movie"), tr("Year:"), 2000, 1800, 2100, 1, &ok);
    if (!ok) return;
    QString genre = QInputDialog::getText(this, tr("Add Movie"), tr("Genre:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;

    Movie m(title, director, year, genre);
    movieDB.addMovie(m);
    refreshTable();
    statusBar()->showMessage(tr("Movie added"), 2000);
}

void MainWindow::removeMovie() {
    bool ok;
    QString title = QInputDialog::getText(this, tr("Remove Movie"), tr("Title:"), QLineEdit::Normal, "", &ok);
    if (!ok || title.isEmpty()) return;
    movieDB.removeMovie(title);
    refreshTable();
    statusBar()->showMessage(tr("Movie removed"), 2000);
}

void MainWindow::editMovie() {
    bool ok;
    QString oldTitle = QInputDialog::getText(this, tr("Edit Movie"), tr("Title of movie to edit:"), QLineEdit::Normal, "", &ok);
    if (!ok || oldTitle.isEmpty()) return;

    QString newTitle = QInputDialog::getText(this, tr("Edit Movie"), tr("New Title:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;
    QString newDirector = QInputDialog::getText(this, tr("Edit Movie"), tr("New Director:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;
    int newYear = QInputDialog::getInt(this, tr("Edit Movie"), tr("New Year:"), 2000, 1800, 2100, 1, &ok);
    if (!ok) return;
    QString newGenre = QInputDialog::getText(this, tr("Edit Movie"), tr("New Genre:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;

    Movie m(newTitle, newDirector, newYear, newGenre);
    if (movieDB.editMovie(oldTitle, m)) {
        refreshTable();
        statusBar()->showMessage(tr("Movie edited"), 2000);
    } else {
        QMessageBox::warning(this, tr("Edit Movie"), tr("Movie not found"));
    }
}

void MainWindow::searchMovie() {
    QStringList options;
    options << tr("By Director") << tr("By Year");
    bool ok;
    QString choice = QInputDialog::getItem(this, tr("Search Movie"), tr("Search criteria:"), options, 0, false, &ok);
    if (!ok || choice.isEmpty()) return;

    if (choice == tr("By Director")) {
        QString director = QInputDialog::getText(this, tr("Search by Director"), tr("Director:"), QLineEdit::Normal, "", &ok);
        if (!ok) return;
        MyContainer<Movie> result = movieDB.searchByDirector(director);
        table->clearContents();
        table->setRowCount(result.size());
        int row = 0;
        for (auto it = result.begin(); it != result.end(); ++it) {
            table->setItem(row, 0, new QTableWidgetItem(it->getTitle()));
            table->setItem(row, 1, new QTableWidgetItem(it->getDirector()));
            table->setItem(row, 2, new QTableWidgetItem(QString::number(it->getYear())));
            table->setItem(row, 3, new QTableWidgetItem(it->getGenre()));
            row++;
        }
        statusBar()->showMessage(tr("Search completed"), 2000);
    } else {
        int year = QInputDialog::getInt(this, tr("Search by Year"), tr("Year:"), 2000, 1800, 2100, 1, &ok);
        if (!ok) return;
        MyContainer<Movie> result = movieDB.searchByYear(year);
        table->clearContents();
        table->setRowCount(result.size());
        int row = 0;
        for (auto it = result.begin(); it != result.end(); ++it) {
            table->setItem(row, 0, new QTableWidgetItem(it->getTitle()));
            table->setItem(row, 1, new QTableWidgetItem(it->getDirector()));
            table->setItem(row, 2, new QTableWidgetItem(QString::number(it->getYear())));
            table->setItem(row, 3, new QTableWidgetItem(it->getGenre()));
            row++;
        }
        statusBar()->showMessage(tr("Search completed"), 2000);
    }
}

void MainWindow::loadFromFile() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Load Database"), "", tr("Database Files (*.dat)"));
    if (filename.isEmpty()) return;
    if (movieDB.loadFromFile(filename)) {
        refreshTable();
        statusBar()->showMessage(tr("Database loaded"), 2000);
    } else {
        QMessageBox::warning(this, tr("Load Database"), tr("Cannot load the file"));
    }
}

void MainWindow::saveToFile() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Database"), "", tr("Database Files (*.dat)"));
    if (filename.isEmpty()) return;
    if (movieDB.saveToFile(filename)) {
        statusBar()->showMessage(tr("Database saved"), 2000);
    } else {
        QMessageBox::warning(this, tr("Save Database"), tr("Cannot save the file"));
    }
}

void MainWindow::mergeWithAnotherDB() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Merge with Database"), "", tr("Database Files (*.dat)"));
    if (filename.isEmpty()) return;
    MovieContainer temp;
    if (temp.loadFromFile(filename)) {
        movieDB.mergeWith(temp);
        refreshTable();
        statusBar()->showMessage(tr("Databases merged"), 2000);
    } else {
        QMessageBox::warning(this, tr("Merge Database"), tr("Cannot load the file to merge"));
    }
}

void MainWindow::refreshTable() {
    table->clearContents();
    auto all = movieDB.getAllMovies();
    table->setRowCount(all.size());
    int row = 0;
    for (auto it = all.begin(); it != all.end(); ++it) {
        table->setItem(row, 0, new QTableWidgetItem(it->getTitle()));
        table->setItem(row, 1, new QTableWidgetItem(it->getDirector()));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(it->getYear())));
        table->setItem(row, 3, new QTableWidgetItem(it->getGenre()));
        row++;
    }
}

bool MainWindow::maybeSave() {
    // Можно реализовать проверку, нужно ли сохранять перед выходом.
    // В данном примере метод всегда возвращает true.
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

