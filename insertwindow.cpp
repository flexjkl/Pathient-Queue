#include "insertwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

bool checkName(QString pathientName){
    if(pathientName.isEmpty() || *pathientName.begin() == ' ') return false;
    auto itr = pathientName.begin(), end = pathientName.end();
    while(itr != end){
        if(!itr->isLetter()){
            if( !itr->isSpace()) return false;
        }
        itr++;
    }
    return true;
}

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
    label->setAlignment(Qt::AlignCenter);

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
    if(!checkName(insertLine->text())){
        QMessageBox* errorMessage = new QMessageBox(this);
        errorMessage->critical(errorMessage, "Ошибка!", "Некорректные данные!");
        insertLine->clear();
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
