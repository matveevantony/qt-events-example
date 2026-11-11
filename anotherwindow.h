#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>
#include <QCloseEvent>

class AnotherWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AnotherWindow(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;
};

#endif // ANOTHERWINDOW_H
