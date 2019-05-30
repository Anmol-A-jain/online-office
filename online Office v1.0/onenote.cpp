#include "onenote.h"
#include "ui_onenote.h"

oneNote::oneNote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::oneNote)
{
    ui->setupUi(this);

    this->setWindowTitle("OneNote");
    this->setWindowIcon(QIcon(":/img/img/OneNote.png"));
    this->setWindowState(Qt::WindowState::WindowMaximized);

    web = new QWebEngineView(ui->OneNote);
    webpage = new QWebEnginePage;

    webpage->setUrl(QUrl("https://www.onenote.com"));
    web->setPage(webpage);
}

oneNote::~oneNote()
{
    delete ui;
}

void oneNote::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->OneNote->size());
}
