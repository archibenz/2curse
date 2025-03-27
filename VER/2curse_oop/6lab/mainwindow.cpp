#include "mainwindow.h"

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , lineEditLeft(nullptr)
    , lineEditRight(nullptr)
    , btnReverseLeft(nullptr)
    , btnReverseRight(nullptr)
    , btnReverseAll(nullptr)
    , btnSwap(nullptr)
    , btnCopyLtoR(nullptr)
    , btnCopyRtoL(nullptr)
{
    // Центральный виджет для QMainWindow
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    // Создадим два QLineEdit
    lineEditLeft = new QLineEdit(this);
    lineEditRight = new QLineEdit(this);

    // Создадим кнопки
    btnReverseLeft = new QPushButton("Reverse Left", this);
    btnReverseRight = new QPushButton("Reverse Right", this);
    btnReverseAll = new QPushButton("Reverse All", this);
    btnSwap = new QPushButton("Swap", this);
    btnCopyLtoR = new QPushButton("Copy L->R", this);
    btnCopyRtoL = new QPushButton("Copy R->L", this);

    // Подключаем слоты
    connect(btnReverseLeft,  &QPushButton::clicked, this, &MainWindow::onReverseLeft);
    connect(btnReverseRight, &QPushButton::clicked, this, &MainWindow::onReverseRight);
    connect(btnReverseAll,   &QPushButton::clicked, this, &MainWindow::onReverseAll);
    connect(btnSwap,         &QPushButton::clicked, this, &MainWindow::onSwap);
    connect(btnCopyLtoR,     &QPushButton::clicked, this, &MainWindow::onCopyLeftToRight);
    connect(btnCopyRtoL,     &QPushButton::clicked, this, &MainWindow::onCopyRightToLeft);

    // Макет для двух QLineEdit горизонтально
    QHBoxLayout* lineEditsLayout = new QHBoxLayout;
    lineEditsLayout->addWidget(lineEditLeft);
    lineEditsLayout->addWidget(lineEditRight);

    // Макет для кнопок (располагаем их в два ряда для удобства)
    QVBoxLayout* buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(btnReverseLeft);
    buttonsLayout->addWidget(btnReverseRight);
    buttonsLayout->addWidget(btnReverseAll);
    buttonsLayout->addWidget(btnSwap);
    buttonsLayout->addWidget(btnCopyLtoR);
    buttonsLayout->addWidget(btnCopyRtoL);

    // Общий вертикальный макет
    QVBoxLayout* mainLayout = new QVBoxLayout(central);
    mainLayout->addLayout(lineEditsLayout);
    mainLayout->addLayout(buttonsLayout);

    // Устанавливаем окно в разумные размеры
    resize(400, 200);
    setWindowTitle("Lab 6, Task 7 (No STL)");
}

MainWindow::~MainWindow()
{
    // Все динамически созданные объекты с родителем удаляются Qt автоматически
}

// --- Методы-обработчики ---

void MainWindow::onReverseLeft()
{
    QString text = lineEditLeft->text();
    lineEditLeft->setText(reverseString(text));
}

void MainWindow::onReverseRight()
{
    QString text = lineEditRight->text();
    lineEditRight->setText(reverseString(text));
}

void MainWindow::onReverseAll()
{
    // Переворачиваем обе строки
    QString leftText = lineEditLeft->text();
    QString rightText = lineEditRight->text();

    lineEditLeft->setText(reverseString(leftText));
    lineEditRight->setText(reverseString(rightText));
}

void MainWindow::onSwap()
{
    QString temp = lineEditLeft->text();
    lineEditLeft->setText(lineEditRight->text());
    lineEditRight->setText(temp);
}

void MainWindow::onCopyLeftToRight()
{
    lineEditRight->setText(lineEditLeft->text());
}

void MainWindow::onCopyRightToLeft()
{
    lineEditLeft->setText(lineEditRight->text());
}

// --- Вспомогательная функция переворота строки ---
QString MainWindow::reverseString(const QString &input)
{
    // Ручной разворот строки без std::reverse и других контейнеров STL
    QString result;
    result.reserve(input.length()); // Оптимизация: сразу резервируем память

    for (int i = input.length() - 1; i >= 0; --i) {
        result.append(input.at(i));
    }
    return result;
}
