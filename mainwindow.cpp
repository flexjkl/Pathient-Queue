#include "mainwindow.h"
#include "insertwindow.h"
#include "showwindow.h"
#include "appointwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow() :
    QWidget(nullptr)
{
    this->setMinimumHeight(300);
    this->setMinimumWidth(300);
    this->setWindowTitle("Очередь пациентов");
    this->setWindowIcon(QIcon(":/icons/cross.ico"));

    registerButton = new QPushButton("Регистрация", this);
    appointButton = new QPushButton("Приём", this);
    showButton = new QPushButton("Очередь", this);

    buttonLayout = new QHBoxLayout(this);

    buttonLayout->addWidget(registerButton);
    buttonLayout->addWidget(appointButton);
    buttonLayout->addWidget(showButton);

    connect(registerButton, &QPushButton::clicked, this, &insertHandler);
    connect(appointButton, &QPushButton::clicked, this, &appointHandler);
    connect(showButton, &QPushButton::clicked, this, &showHandler);
}

void MainWindow::insertHandler(){
    InsertWindow* insertWindow = new InsertWindow(pathientQueue, this);
    insertWindow->show();
}

void MainWindow::appointHandler(){
    AppointWindow* appointWindow = new AppointWindow(pathientQueue, this);
    appointWindow->show();
}

void MainWindow::showHandler(){
    ShowWindow* showWindow = new ShowWindow(pathientQueue, this);
    showWindow->show();
}

MainWindow::~MainWindow() {}
