#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Pathient.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <list>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:

    std::list<Pathient> pathientQueue;

    QPushButton* registerButton;
    QPushButton* appointButton;
    QPushButton* showButton;

    QHBoxLayout* buttonLayout;

private slots:
    void insertHandler();

    void appointHandler();

    void showHandler();
};
#endif
