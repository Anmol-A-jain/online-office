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

    history = new historyList;
    flag = true;
}

Office::~Office()
{
    delete page;
    delete web;
    delete ui;
}

void Office::closeEvent(QCloseEvent *event)
{
    ExitApp e;
    e.setModal(true);
    e.exec();
    event->ignore();
}

void Office::downloadRequested(QWebEngineDownloadItem* download)
{ Q_ASSERT(download && download->state() == QWebEngineDownloadItem::DownloadRequested);

    QString path = QFileDialog::getSaveFileName(this, tr("Save as"), download->path());
    if (path.isEmpty())
        return;

    download->setPath(path);
    download->accept();
}

void Office::setPageUrl()
{
    pageurl.insert(PageName::home,QUrl("https://office.live.com/"));
    pageurl.insert(PageName::word,QUrl("https://office.live.com/start/Word.aspx"));
    pageurl.insert(PageName::excel,QUrl("https://office.live.com/start/Excel.aspx"));
    pageurl.insert(PageName::powerPoint,QUrl("https://office.live.com/start/PowerPoint.aspx"));
    pageurl.insert(PageName::oneDrive,QUrl("https://onedrive.live.com"));
    pageurl.insert(PageName::outlook,QUrl("https://outlook.live.com"));
}

void Office::setShadowColor()
{
    shadowcolor.insert(PageName::word,QColor(43, 87, 154));
    shadowcolor.insert(PageName::excel,QColor(33, 115, 70));
    shadowcolor.insert(PageName::powerPoint,QColor(210, 71, 38));
    shadowcolor.insert(PageName::oneDrive,QColor(9, 74, 178));
    shadowcolor.insert(PageName::outlook,QColor(0, 114, 198));
}

void Office::setinstallevent()
{
    ui->word->installEventFilter(this);
    ui->excel->installEventFilter(this);
    ui->powerpoint->installEventFilter(this);
    ui->outlook->installEventFilter(this);
    ui->onedrive->installEventFilter(this);

    ui->back->installEventFilter(this);
    ui->next->installEventFilter(this);
    ui->refresh->installEventFilter(this);
    ui->title->installEventFilter(this);
    this->installEventFilter(this);
}

bool Office::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == static_cast<QObject*>(ui->word) )
    {
        setShadowEffect(ui->word,shadowcolor[PageName::word],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == static_cast<QObject*> (ui->excel) )
    {
        setShadowEffect(ui->excel,shadowcolor[PageName::excel],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == static_cast<QObject*> (ui->powerpoint) )
    {
        setShadowEffect(ui->powerpoint,shadowcolor[PageName::powerPoint],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == static_cast<QObject*> (ui->onedrive))
    {
        setShadowEffect(ui->onedrive,shadowcolor[PageName::oneDrive],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == static_cast<QObject*> (ui->outlook) )
    {
        setShadowEffect(ui->outlook,shadowcolor[PageName::outlook],event);
        return QWidget::eventFilter(obj,event);
    }
    if(obj == static_cast<QObject*> (ui->back))
    {
        if(event->type() == QEvent::HoverEnter)
        {
            setShadow(ui->back,Qt::green);
        }

        if(event->type() == QEvent::HoverLeave)
        {
            removeShadow(ui->back);
        }

        return QWidget::eventFilter(obj,event);
    }
    if( obj == static_cast<QObject*> (ui->next) )
    {
        if(event->type() == QEvent::HoverEnter)
        {
            setShadow(ui->next,Qt::green);
        }
        if(event->type() == QEvent::HoverLeave)
        {
            removeShadow(ui->next);
        }

        return QWidget::eventFilter(obj,event);
    }
    if(obj == static_cast<QObject*> (ui->refresh)  )
    {
        if(event->type() == QEvent::HoverEnter)
        {
            setShadow(ui->refresh,Qt::green);
        }
        if(event->type() == QEvent::HoverLeave)
        {
            removeShadow(ui->refresh);
        }

        return QWidget::eventFilter(obj,event);
    }
    if(event->type() == QEvent::KeyPress)
    {
        keyEventCombo.insert(static_cast<QKeyEvent*>(event)->key());
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_Left))
        {
            on_back_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_Right))
        {
            on_next_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_R))
        {
            on_refresh_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_1))
        {
            on_word_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_2))
        {
            on_excel_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_3))
        {
            on_powerpoint_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_4))
        {
            on_onedrive_clicked();
        }
        if(keyEventCombo.contains(Qt::Key_Alt) && keyEventCombo.contains(Qt::Key_5))
        {
            on_outlook_clicked();
        }
    }
    if(event->type() == QEvent::KeyRelease)
    {
        keyEventCombo.clear();
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
    //web->back();
    flag = false;
    QString url= web->page()->url().toString();
    QString temp = url;
    if(history->hasPrevious())
    {
        url = history->previous();
    }
    if(url != temp)
    {
        web->page()->setUrl(url);
    }
}

void Office::on_next_clicked()
{
    //web->forward();
    flag = false;
    QString url = web->page()->url().toString();
        QString temp = url;
    if(history->hasNext())
    {
        url = history->next();
    }
    if(url != temp)
    {
        web->page()->setUrl(url);
    }

}

void Office::on_refresh_clicked()
{
    flag = false;
    web->reload();
}

void Office::changeColor(QString backColor, QString fontColor)
{
    ui->mainWindow->setStyleSheet("#mainWindow{"
                         "background-color:" + backColor +"}");
    ui->title->setStyleSheet("color:" + fontColor +";"
                             "background-color:" + backColor +";");
    if(backColor == "white")
    {
        ui->refresh->setStyleSheet("background-color:" + backColor +";"
                                   "border-image:url(:/img/asset/reload.png);"
                                    "border-radius:5px;");
        ui->back->setStyleSheet("background-color:" + backColor +"; "
                                "border-image:url(:/img/asset/goBack.png);"
                                "border-radius:5px;");
        ui->next->setStyleSheet("background-color:" + backColor +"; "
                                "border-image:url(:/img/asset/goNext.png);"
                                "border-radius:5px;");
    }
    else
    {
        ui->refresh->setStyleSheet("background-color:" + backColor +";"
                                   "border-image:url(:/img/asset/reload_white.png);"
                                   "border-radius:5px;");
        ui->back->setStyleSheet("background-color:" + backColor +"; "
                                "border-image:url(:/img/asset/goBack_white.png);"
                                "border-radius:5px;");
        ui->next->setStyleSheet("background-color:" + backColor +"; "
                                "border-image:url(:/img/asset/goNext_white.png);"
                                "border-radius:5px;");
    }
}

void Office::changePage(QUrl url)
{
    QWebEnginePage *temp = nullptr;
    temp = web->page();
    QWebEnginePage *newPage = new QWebEnginePage;
    newPage->setUrl(url);
    web->setPage(newPage);
    delete temp;
}

void Office::on_word_clicked()
{
    changePage(pageurl[PageName::word]);
}

void Office::on_excel_clicked()
{
    changePage(pageurl[PageName::excel]);
}

void Office::on_powerpoint_clicked()
{

    changePage(pageurl[PageName::powerPoint]);
}

void Office::on_onedrive_clicked()
{

    changePage(pageurl[PageName::oneDrive]);
}

void Office::on_outlook_clicked()
{

    changePage(pageurl[PageName::outlook]);
}

void Office::onPageUrlChange()
{

    if(flag)
    {
        if(history->firstpage() == nullptr)
        {
            history->insert(web->page()->url().toString());
        }
        else if(history->currentPage() == history->lastPage())
        {
            history->insert(web->page()->url().toString());
            history->next();
        }
        else
        {
            history->insertNext(web->page()->url().toString());
        }
    }

    QString temp = web->page()->url().toString();
    if(temp.contains(pageurl[PageName::word].toString(),Qt::CaseInsensitive) || temp.contains("app=Word",Qt::CaseInsensitive) || temp.contains("Cdocx",Qt::CaseInsensitive))
    {
        ui->title->setText("Word");
        changeColor("#19478a","white");
    }
    else if (temp.contains(pageurl[PageName::excel].toString(),Qt::CaseInsensitive) || temp.contains("app=Excel",Qt::CaseInsensitive))
    {
        ui->title->setText("Excel");
        changeColor("#0a6332","white");
    }
    else if (temp.contains(pageurl[PageName::powerPoint].toString(),Qt::CaseInsensitive) || temp.contains("Cpptx" , Qt::CaseInsensitive))
    {
        ui->title->setText("PowerPoint");
        changeColor("#b83b1d","white");
    }
    else if (temp.contains(pageurl[PageName::oneDrive].toString(),Qt::CaseInsensitive))
    {
        ui->title->setText("OneDrive");
        changeColor("white","black");
    }
    else if (temp.contains(pageurl[PageName::oneDrive].toString(),Qt::CaseInsensitive) && !temp.contains("https://onedrive.live.com/edit.aspx",Qt::CaseInsensitive))
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
    flag = true;
}
