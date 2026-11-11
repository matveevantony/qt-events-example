#include "anotherwindow.h"

#include <QLabel>
#include <QCloseEvent>

AnotherWindow::AnotherWindow(QWidget *parent)
    : QWidget{parent}
{
    setWindowFlag(Qt::Window);
    setFixedSize(400, 400);
    setWindowTitle("Второе окно");

    QLabel* lbl = new QLabel("Немного текста");
    lbl->setGeometry(0, 0, 400, 400);
    lbl->setAlignment(Qt::AlignCenter);
}

void AnotherWindow::closeEvent(QCloseEvent *event) {
    parentWidget()->show();
    hide();
    event->ignore();
}