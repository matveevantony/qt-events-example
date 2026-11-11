#include "mainwindow.h"
#include <QPushButton>
#include <QCloseEvent>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800, 800);
    setWindowTitle("Первое окно");

    otherWin = new AnotherWindow(this);

    btn = new QPushButton("Жмак", this);
    btn->setGeometry(350, 350, 100, 100);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    otherWin->show();
    hide();
    event->ignore();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QPoint P = btn->geometry().topLeft();
    switch(event->key()) {
    case Qt::Key_Up:
        P.setY(P.y() - 10);
        break;
    case Qt::Key_Down:
        P.setY(P.y() + 10);
        break;
    case Qt::Key_Left:
        P.setX(P.x() - 10);
        break;
    case Qt::Key_Right:
        P.setX(P.x() + 10);
        break;
    default:
        return;
    }
    btn->setGeometry(P.x(), P.y(), 100, 100);
}

MainWindow::~MainWindow() = default;
