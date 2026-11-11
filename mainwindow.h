#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCloseEvent>
#include <QKeyEvent>
#include "anotherwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPushButton* btn;
    AnotherWindow* otherWin;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    ~MainWindow() override;
};
#endif // MAINWINDOW_H
