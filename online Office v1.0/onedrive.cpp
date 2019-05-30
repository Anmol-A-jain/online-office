#include "onedrive.h"
#include "ui_onedrive.h"

oneDrive::oneDrive(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::oneDrive)
{
    ui->setupUi(this);

    this->setWindowTitle("OneDrive");
    this->setWindowIcon(QIcon(":/img/img/onedrive.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized);

    web = new QWebEngineView(ui->onedrive);
    webpage = new QWebEnginePage();
    webpage->setUrl(QUrl("https://onedrive.live.com"));
    web->setPage(webpage);
}

oneDrive::~oneDrive()
{
    delete ui;
}

void oneDrive::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->onedrive->size());
}
