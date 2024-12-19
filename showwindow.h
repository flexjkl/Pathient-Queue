#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include "Pathient.h"
#include <QTableWidget>
#include <QPushButton>
#include <list>

class ShowWindow : public QTableWidget
{

    Q_OBJECT

public:
    ShowWindow(std::list<Pathient> &pathientQueue, QWidget* parent);

    ~ShowWindow();

private:
    std::list<Pathient> *pathientQueue;

};
#endif
