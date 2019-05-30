#include "excel.h"
#include "ui_excel.h"

excel::excel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::excel)
{
    ui->setupUi(this);
    this->setWindowTitle("Excel");
    this->setWindowIcon(QIcon(":/img/img/excel.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized);

    web = new QWebEngineView(ui->Excel);
    webpage = new QWebEnginePage();
    webpage->setUrl(QUrl("https://office.live.com/start/excel.aspx"));
    web->setPage(webpage);
}

excel::~excel()
{
    delete ui;
}

void excel::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->Excel->size());
}
