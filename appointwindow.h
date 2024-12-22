#ifndef APPOINTWINDOW_H
#define APPOINTWINDOW_H

#include "Pathient.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <list>

class AppointWindow : public QWidget{

    Q_OBJECT

public:
    AppointWindow(std::list<Pathient>& pthntQueue, QWidget* parent);
    ~AppointWindow();

private:
    std::list<Pathient> *pathientQueue;
    QLabel *text;
    QLineEdit *pathientOnAppoint;
    QPushButton *appointButton, *closeButton;
    QVBoxLayout *layout;

private slots:
    void appointPathient();

    void closeWindow();
};

#endif // APPOINTWINDOW_H
