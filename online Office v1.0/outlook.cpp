#include "outlook.h"
#include "ui_outlook.h"

outlook::outlook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::outlook)
{
    ui->setupUi(this);
    this->setWindowTitle("Outlook");
    this->setWindowIcon(QIcon(":/img/img/OutLook.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized);

    web = new QWebEngineView(ui->Outlook);
    webpage = new QWebEnginePage();
    webpage->setUrl(QUrl("https://outlook.live.com"));
    web->setPage(webpage);


}

outlook::~outlook()
{
    delete ui;
}

void outlook::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->Outlook->size());
}
