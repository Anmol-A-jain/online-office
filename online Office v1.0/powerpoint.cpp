#include "powerpoint.h"
#include "ui_powerpoint.h"

powerPoint::powerPoint(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::powerPoint)
{
    ui->setupUi(this);

    this->setWindowTitle("Powerpoint");
    this->setWindowIcon(QIcon(":/img/img/PowerPoint.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized);

    web =  new QWebEngineView(ui->PowerPoint);
    webpage = new QWebEnginePage;
    webpage->setUrl(QUrl("https://office.live.com/start/PowerPoint.aspx"));
    web->setPage(webpage);

}

powerPoint::~powerPoint()
{
    delete ui;
}

void powerPoint::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->PowerPoint->size());
}
