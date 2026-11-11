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
    btn->installEventFilter(this);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    otherWin->show();
    hide();
    event->ignore();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == btn && event->type() == QEvent::KeyPress) {
        auto *keyEvent = static_cast<QKeyEvent *>(event);
        return moveButton(keyEvent->key());
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (!moveButton(event->key())) {
        QMainWindow::keyPressEvent(event);
    }
}

bool MainWindow::moveButton(int key) {
    QPoint P = btn->geometry().topLeft();
    switch(key) {
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
        return false;
    }
    btn->setGeometry(P.x(), P.y(), 100, 100);
    return true;
}

MainWindow::~MainWindow() = default;
