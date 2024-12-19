#ifndef INSERTWINDOW_H
#define INSERTWINDOW_H

#include "Pathient.h"
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <list>

class InsertWindow : public QWidget
{
    Q_OBJECT

private:
    std::list<Pathient>* pathientQueue;
    QLineEdit *insertLine;
    QPushButton *insertButton, *closeButton;
    QVBoxLayout *insertView;
    QLabel *label;

public:
    InsertWindow(std::list<Pathient>& pthntQueue, QWidget* parent);
    ~InsertWindow();

private slots:
    void insertPathient();

    void closeWindow();
};

#endif
