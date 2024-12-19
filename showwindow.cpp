#include "showwindow.h"
#include <QHeaderView>

ShowWindow::ShowWindow(std::list<Pathient> &pthntQueue, QWidget* parent = nullptr) :
    QTableWidget(parent),
    pathientQueue(&pthntQueue)
{
    int queueSize = pathientQueue->size();

    this->setWindowFlag(Qt::Window);
    this->setWindowModality(Qt::WindowModality::WindowModal);

    this->setWindowTitle("Очередь");
    this->setMinimumWidth(300);
    this->setMinimumHeight(100);
    this->setWindowIcon(QIcon(":/icons/queue.ico"));

    this->setColumnCount(2);
    this->setRowCount(queueSize);
    this->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("ID")));
    this->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("ФИО")));

    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int i = 0;
    for(auto itr = pathientQueue->begin(), end = pathientQueue->end(); itr != end; itr++){
        this->setItem(i,0, new QTableWidgetItem(QString::number(itr->id)));
        this->setItem(i,1, new QTableWidgetItem(itr->fullName));
        i++;
    }

    this->horizontalHeader()->setStretchLastSection(true);
}

ShowWindow::~ShowWindow(){}
