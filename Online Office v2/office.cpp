#include "office.h"
#include "ui_office.h"

Office::Office(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Office)
{
    ui->setupUi(this);
    //enabling cookies
    QWebEngineProfile::defaultProfile()->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);

    //setting windows state and icon
    this->setWindowState(Qt::WindowState::WindowMaximized);
    this->setWindowIcon(QIcon(":/img/asset/logo.ico"));

    setPageUrl();
    setShadowColor();
    setinstallevent();

    web = new webview();
    page = new QWebEnginePage();
    page->setUrl(pageurl[PageName::home]);
    web->setPage(page);
    web->setParent(ui->window);

    connect(QWebEngineProfile::defaultProfile(),SIGNAL(downloadRequested(QWebEngineDownloadItem *)),this,SLOT(downloadRequested(QWebEngineDownloadItem *)));
    connect(web,SIGNAL(loadFinished(bool)),this,SLOT(onPageUrlChange()));
}

Office::~Office()
{
    delete page;
    delete web;
    delete ui;
}

void Office::setPageUrl()
{
    pageurl.insert(PageName::home,QUrl("https://www.office.com"));
    pageurl.insert(PageName::word,QUrl("https://office.live.com/start/Word.aspx"));
    pageurl.insert(PageName::excel,QUrl("https://office.live.com/start/Excel.aspx"));
    pageurl.insert(PageName::powerPoint,QUrl("https://office.live.com/start/PowerPoint.aspx"));
    pageurl.insert(PageName::oneDrive,QUrl("https://onedrive.live.com"));
    pageurl.insert(PageName::outlook,QUrl("https://outlook.live.com"));
}

void Office::setShadowColor()
{
    shadowcolor.insert(PageName::home,QColor(232, 63, 36));
    shadowcolor.insert(PageName::word,QColor(43, 87, 154));
    shadowcolor.insert(PageName::excel,QColor(33, 115, 70));
    shadowcolor.insert(PageName::powerPoint,QColor(210, 71, 38));
    shadowcolor.insert(PageName::oneDrive,QColor(9, 74, 178));
    shadowcolor.insert(PageName::outlook,QColor(0, 114, 198));
}

void Office::setinstallevent()
{
    ui->home->installEventFilter(this);
    ui->word->installEventFilter(this);
    ui->excel->installEventFilter(this);
    ui->powerpoint->installEventFilter(this);
    ui->outlook->installEventFilter(this);
    ui->onedrive->installEventFilter(this);
}

bool Office::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == (QObject*) ui->home)
    {
        setShadowEffect(ui->home,shadowcolor[PageName::home],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == (QObject*) ui->word)
    {
        setShadowEffect(ui->word,shadowcolor[PageName::word],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == (QObject*) ui->excel)
    {
        setShadowEffect(ui->excel,shadowcolor[PageName::excel],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == (QObject*) ui->powerpoint)
    {
        setShadowEffect(ui->powerpoint,shadowcolor[PageName::powerPoint],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == (QObject*) ui->onedrive)
    {
        setShadowEffect(ui->onedrive,shadowcolor[PageName::oneDrive],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == (QObject*) ui->outlook)
    {
        setShadowEffect(ui->outlook,shadowcolor[PageName::outlook],event);
        return QWidget::eventFilter(obj,event);
    }

    return QWidget::eventFilter(obj,event);
}

void Office::setShadowEffect(QWidget *widget, QColor color, QEvent *e)
{
    if(e->type() == QEvent::HoverEnter)
    {
        setShadow(widget,color);
    }
    if(e->type() == QEvent::HoverLeave)
    {
        removeShadow(widget);
    }
}

void Office::setShadow(QWidget* widget, QColor color)
{
    auto effect = new QGraphicsDropShadowEffect();
    effect->setOffset(.0);
    effect->setBlurRadius(25.0);
    effect->setColor(color);
    widget->setGraphicsEffect(effect);
}

void Office::removeShadow(QWidget *widget)
{
    widget->setGraphicsEffect(nullptr);
}

void Office::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    web->resize(ui->window->size());
}

void Office::on_back_clicked()
{
    web->back();
}

void Office::on_next_clicked()
{
    web->forward();
}

void Office::on_refresh_clicked()
{
    web->reload();
}

void Office::changeColor(QString backColor, QString fontColor)
{
    ui->mainWindow->setStyleSheet("#mainWindow{"
                         "background-color:" + backColor +"}");
    ui->refresh->setStyleSheet("background-color:" + backColor +";"
                               "border-image:url(:/img/asset/reload.png);");
    ui->back->setStyleSheet("background-color:" + backColor +"; "
                            "border-image:url(:/img/asset/goBack.png);");
    ui->next->setStyleSheet("background-color:" + backColor +"; "
                            "border-image:url(:/img/asset/goNext.png);");
    ui->title->setStyleSheet("color:" + fontColor +";"
                             "background-color:" + backColor +";");
}

void Office::on_home_clicked()
{;
    QWebEnginePage *temp = nullptr;
    if(web->page() != page)
    {
        temp = web->page();
    }
    page->setUrl(pageurl[PageName::home]);
    web->setPage(page);

    if(temp != nullptr)
    {
        delete temp;
    }
}


void Office::on_word_clicked()
{    QWebEnginePage *temp = nullptr;
     if(web->page() != page)
     {
         temp = web->page();
     }
     page->setUrl(pageurl[PageName::word]);
     web->setPage(page);

     if(temp != nullptr)
     {
         delete temp;
     }
}

void Office::on_excel_clicked()
{
    QWebEnginePage *temp = nullptr;
    if(web->page() != page)
    {
        temp = web->page();
    }
    page->setUrl(pageurl[PageName::excel]);
    web->setPage(page);

    if(temp != nullptr)
    {
        delete temp;
    }
}

void Office::on_powerpoint_clicked()
{
    QWebEnginePage *temp = nullptr;
    if(web->page() != page)
    {
        temp = web->page();
    }
    page->setUrl(pageurl[PageName::powerPoint]);
    web->setPage(page);

    if(temp != nullptr)
    {
        delete temp;
    }
}

void Office::on_onedrive_clicked()
{
    QWebEnginePage *temp = nullptr;
    if(web->page() != page)
    {
        temp = web->page();
    }
    page->setUrl(pageurl[PageName::oneDrive]);
    web->setPage(page);

    if(temp != nullptr)
    {
        delete temp;
    }
}

void Office::on_outlook_clicked()
{
    QWebEnginePage *temp = nullptr;
    if(web->page() != page)
    {
        temp = web->page();
    }
    web->setPage(page);
    page->setUrl(pageurl[PageName::outlook]);

    if(temp != nullptr)
    {
        delete temp;
    }
}

void Office::onPageUrlChange()
{
    qDebug() << web->page()->url().toString();
    QString temp = web->page()->url().toString();
    if(temp.contains(pageurl[PageName::word].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("Word");
        changeColor("#19478a","white");
    }
    else if (temp.contains(pageurl[PageName::excel].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("excel");
        changeColor("#0a6332","white");
    }
    else if (temp.contains(pageurl[PageName::powerPoint].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("PowerPoint");
        changeColor("#b83b1d","white");
    }
    else if (temp.contains(pageurl[PageName::oneDrive].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("OneDrive");
        changeColor("white","black");
    }
    else if (temp.contains(pageurl[PageName::oneDrive].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("Outlook");
        changeColor("white","black");
    }
    else if (temp.contains(pageurl[PageName::oneDrive].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("Office");
        changeColor("white","black");
    }
    else
    {
        ui->title->setText(web->page()->title());
        changeColor("white","black");
    }

}
