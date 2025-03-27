#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;  // forward declaration
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onReverseLeft();
    void onReverseRight();
    void onReverseAll();
    void onSwap();
    void onCopyLeftToRight();
    void onCopyRightToLeft();

private:
    // Метод для переворота строки без использования STL
    QString reverseString(const QString &input);

private:
    // Поля для UI
    QLineEdit* lineEditLeft;
    QLineEdit* lineEditRight;

    // Кнопки
    QPushButton* btnReverseLeft;
    QPushButton* btnReverseRight;
    QPushButton* btnReverseAll;
    QPushButton* btnSwap;
    QPushButton* btnCopyLtoR;
    QPushButton* btnCopyRtoL;
};

#endif // MAINWINDOW_H
