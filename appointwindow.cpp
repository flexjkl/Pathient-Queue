#include "appointwindow.h"
#include <QMessageBox>

AppointWindow::AppointWindow(std::list<Pathient>& pthntQueue, QWidget* parent) :
    pathientQueue(&pthntQueue),
    QWidget(parent)
{
    this->setWindowFlag(Qt::Window);

    this->setMinimumWidth(300);
    this->setWindowTitle("Приём пациентов");
    this->setWindowIcon(QIcon(":/icons/appoint.ico"));

    text = new QLabel("Пациент на приёме:", this);
    pathientOnAppoint = new QLabel(this);

    appointButton = new QPushButton("Следующий", this);
    closeButton = new QPushButton("Закрыть", this);

    layout = new QVBoxLayout(this);
    layout->addWidget(text);
    layout->addWidget(pathientOnAppoint);
    layout->addWidget(appointButton);
    layout->addWidget(closeButton);

    connect(appointButton, &QPushButton::clicked, this, &appointPathient);
    connect(closeButton, &QPushButton::clicked, this, &closeWindow);
}

AppointWindow::~AppointWindow(){}

void AppointWindow::appointPathient(){
    if(pathientQueue->empty()){
        pathientOnAppoint->clear();
        QMessageBox* errorMessage = new QMessageBox(this);
        errorMessage->critical(errorMessage, "Ошибка!", "Очередь пуста!");
        return;
    }
    auto itr = pathientQueue->begin();
    pathientOnAppoint->setText(QString::number(itr->id) + " " + itr->fullName);
    pathientQueue->pop_front();
}

void AppointWindow::closeWindow(){
    this->close();
}
