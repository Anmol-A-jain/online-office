#include "sway.h"
#include "ui_sway.h"

Sway::Sway(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sway)
{
    ui->setupUi(this);
    this->setWindowTitle("Sway");
    this->setWindowIcon(QIcon(":/img/img/sway.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized)
;
    web = new QWebEngineView(ui->sway);
    webpage = new QWebEnginePage;
    webpage->setUrl(QUrl("https://sway.office.com/"));
    web->setPage(webpage);

}

Sway::~Sway()
{
    delete ui;
}

void Sway::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->sway->size());
}
