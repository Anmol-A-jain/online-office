#include "forms.h"
#include "ui_forms.h"

Forms::Forms(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Forms)
{
    ui->setupUi(this);

    this->setWindowTitle("Forms");
    this->setWindowIcon(QIcon(":/img/img/forms.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized);

    web =  new QWebEngineView(ui->form);
    webpage =  new QWebEnginePage;
    webpage->setUrl(QUrl("https://forms.office.com/"));
    web->setPage(webpage);
}

Forms::~Forms()
{
    delete ui;
}

void Forms::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->form->size());
}
