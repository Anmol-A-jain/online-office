#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    this->setWindowTitle("Bing");
    this->setWindowIcon(QIcon(":/img/img/bing.png"));
    ui->lineEdit->setPlaceholderText("Enter search");

    web = new QWebEngineView(ui->bing);
    webpage = new QWebEnginePage();
    webpage->setUrl(QUrl("https://www.bing.com/"));
    web->setPage(webpage);

}

Home::~Home()
{
    delete ui;
}

void Home::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->centralwidget->size());
}

void Home::on_lineEdit_returnPressed()
{
    webpage->setUrl(QUrl("https://www.bing.com/search?q=" + ui->lineEdit->text()));
    web->setPage(webpage);
}




