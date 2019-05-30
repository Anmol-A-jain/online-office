#include "word.h"
#include "ui_word.h"

Word::Word(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Word)
{
    ui->setupUi(this);

    this->setWindowTitle("Word");
    this->setWindowIcon(QIcon(":/img/img/word.png"));

    web = new QWebEngineView(ui->word);
    webpage = new QWebEnginePage();
    webpage->setUrl(QUrl("https://office.live.com/start/Word.aspx"));
    web->setPage(webpage);
    web->show();

    this->setWindowState(Qt::WindowState::WindowMaximized);
}

Word::~Word()
{
    delete ui;
}

void Word::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->word->size());
}
