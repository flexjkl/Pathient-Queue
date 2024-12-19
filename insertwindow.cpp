#include "insertwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

InsertWindow::InsertWindow(std::list<Pathient>& pthntQueue, QWidget* parent = nullptr) :
    QWidget(parent),
    pathientQueue(&pthntQueue)
{
    this->setWindowFlag(Qt::Window);
    this->setWindowModality(Qt::WindowModality::WindowModal);

    this->setMinimumWidth(300);
    this->setMinimumHeight(100);
    this->setWindowTitle("Регистрация пациента");
    this->setWindowIcon(QIcon(":/icons/regist.ico"));

    label = new QLabel("Введите ФИО пациента", this);

    insertLine = new QLineEdit(this);
    insertLine->setMinimumWidth(250);

    insertButton = new QPushButton("Зарегистрировать", this);
    closeButton = new QPushButton("Закрыть", this);

    insertView = new QVBoxLayout(this);

    insertView->addWidget(label);
    insertView->addWidget(insertLine);
    insertView->addWidget(insertButton);
    insertView->addWidget(closeButton);

    connect(insertButton, &QPushButton::clicked, this, &insertPathient);
    connect(closeButton, &QPushButton::clicked, this, &closeWindow);
}

InsertWindow::~InsertWindow() {}

void InsertWindow::insertPathient(){
    if(insertLine->text().isEmpty()){
        QMessageBox* errorMessage = new QMessageBox(this);
        errorMessage->critical(errorMessage, "Ошибка!", "Вы не заполнили строку ФИО");
        return;
    }
    pathientQueue->push_back(Pathient(insertLine->text()));
    QMessageBox* succesMessage = new QMessageBox(this);
    succesMessage->setWindowTitle("Успех!");
    succesMessage->setText("Пациент добавлен в очередь!");
    succesMessage->show();
    insertLine->clear();
}

void InsertWindow::closeWindow(){
    this->close();
}
