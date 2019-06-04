#ifndef OFFICE_H
#define OFFICE_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QDebug>
#include <QWebEngineProfile>
#include <QGraphicsEffect>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QtEvents>
#include "exitapp.h"

namespace Ui {
class Office;
}

class webview;

enum PageName{home,word,excel,powerPoint,oneDrive,outlook};

class Office : public QMainWindow
{
    Q_OBJECT

public:
    explicit Office(QWidget *parent = nullptr);
    ~Office();
    void paintEvent(QPaintEvent* event);
    void setShadow(QWidget* widget, QColor color);
    void removeShadow(QWidget* widget);
    void setShadowEffect(QWidget* widget, QColor color,QEvent* e);
    bool eventFilter(QObject *obj, QEvent *event);
    void setPageUrl();
    void setinstallevent();
    void setShadowColor();
    void changeColor(QString backColor,QString fontColor);
    void closeEvent (QCloseEvent *event)
    {
        ExitApp *e = new ExitApp();
        e->setPointer(e);
        e->setModal(true);
        e->exec();
        delete e;

        event->ignore();
    }


private slots:
    void on_back_clicked();

    void on_next_clicked();

    void on_refresh_clicked();

    void on_home_clicked();

    void on_word_clicked();

    void on_excel_clicked();

    void on_powerpoint_clicked();

    void on_onedrive_clicked();

    void on_outlook_clicked();

    void downloadRequested(QWebEngineDownloadItem* download)
    { Q_ASSERT(download && download->state() == QWebEngineDownloadItem::DownloadRequested);

        QString path = QFileDialog::getSaveFileName(this, tr("Save as"), download->path());
        if (path.isEmpty())
            return;

        download->setPath(path);
        download->accept();
    }


private:
    Ui::Office *ui;
    webview *web;
    QWebEnginePage* page;
    QHash<int,QUrl> pageurl;
    QHash<int,QColor> shadowcolor;
};

class webview : public QWebEngineView
{

public:
    QWebEngineView* createWindow(QWebEnginePage::WebWindowType type)
    {
        if(QWebEnginePage::WebWindowType::WebBrowserTab == type)
        {
            this->setPage(new QWebEnginePage);
            return this;
        }
        return nullptr;
    }
};

#endif // OFFICE_H
