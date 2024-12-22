#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include "Pathient.h"
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>
#include <list>

class ShowWindow : public QTableWidget
{

    Q_OBJECT

public:
    ShowWindow(std::list<Pathient> &pathientQueue, QWidget* parent);

    ~ShowWindow();

private:
    std::list<Pathient> *pathientQueue;
    QPushButton *importButton, *exportButton;
    QHBoxLayout* layout;

private slots:
    void importQueue();

    void exportQueue();
};
#endif
