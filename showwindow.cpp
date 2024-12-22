#include "showwindow.h"
#include "xlsxdocument.h"
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>

ShowWindow::ShowWindow(std::list<Pathient> &pthntQueue, QWidget* parent = nullptr) :
    QTableWidget(parent),
    pathientQueue(&pthntQueue)
{
    int queueSize = pathientQueue->size();

    this->setWindowFlag(Qt::Window);
    this->setWindowModality(Qt::WindowModality::WindowModal);

    this->setWindowTitle("Очередь");
    this->setMinimumWidth(300);
    this->setMinimumHeight(queueSize * 50);
    this->setWindowIcon(QIcon(":/icons/queue.ico"));

    this->setColumnCount(2);
    this->setRowCount(queueSize);
    this->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("ID")));
    this->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("ФИО")));

    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

    importButton = new QPushButton("Загрузить очередь", this);
    exportButton = new QPushButton("Сохранить очередь", this);

    connect(importButton, &QPushButton::clicked, this, &importQueue);
    connect(exportButton, &QPushButton::clicked, this, &exportQueue);

    layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignBottom);

    layout->addWidget(importButton);
    layout->addWidget(exportButton);

    int i = 0;
    for(auto itr = pathientQueue->begin(), end = pathientQueue->end(); itr != end; itr++){
        this->setItem(i,0, new QTableWidgetItem(QString::number(itr->id)));
        this->setItem(i,1, new QTableWidgetItem(itr->fullName));
        i++;
    }

    this->horizontalHeader()->setStretchLastSection(true);
}

void ShowWindow::importQueue(){
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть","","*.xlsx");

    if(fileName.isEmpty()) return;

    QXlsx::Document loadDoc(fileName);
    if(!loadDoc.load()){
        QMessageBox* errorMessage = new QMessageBox(this);
        errorMessage->critical(errorMessage, "Ошибка!", "Файл не открыт!");
        return;
    }

    int id = 0;
    QString fullName = 0;
    std::list<Pathient> loadQueue;
    for(int i = 2; loadDoc.read(i,1).toBool(); i++){
        id = loadDoc.read(i,1).toInt();
        fullName = loadDoc.read(i,2).toString();
        loadQueue.push_back(Pathient(fullName, id));
    }

    *pathientQueue = loadQueue;
    int queueSize = pathientQueue->size();

    this->clear();
    this->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("ID")));
    this->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("ФИО")));
    this->setRowCount(queueSize);
    this->setMinimumHeight(queueSize*50+100);
    this->resize(300,queueSize*50+100);

    int i = 0;
    for(auto itr = pathientQueue->begin(), end = pathientQueue->end(); itr != end; itr++){
        this->setItem(i,0, new QTableWidgetItem(QString::number(itr->id)));
        this->setItem(i,1, new QTableWidgetItem(itr->fullName));
        i++;
    }
}

void ShowWindow::exportQueue(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить","","*.xlsx");
    if(!fileName.isEmpty()){
        QXlsx::Document writeDoc;

        writeDoc.write(1,1, "ID");
        writeDoc.write(1,2, "ФИО");

        int i = 2;
        for(auto itr = pathientQueue->begin(), end = pathientQueue->end(); itr != end; itr++, i++){
            writeDoc.write(i,1, itr->id);
            writeDoc.write(i, 2, itr->fullName);
        }
        bool status = writeDoc.saveAs(fileName);
        if(status){
            QMessageBox* succesMessage = new QMessageBox(this);
            succesMessage->information(succesMessage, "Успех!", "Очередь пациентов была сохранена в: " + fileName);
            return;
        }
        QMessageBox* errorMessage = new QMessageBox(this);
        errorMessage->critical(errorMessage, "Ошибка!", "Не удалось сохранить файл!" + fileName);
    }
}

ShowWindow::~ShowWindow(){}
