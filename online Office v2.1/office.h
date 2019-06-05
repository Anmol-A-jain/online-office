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
class historyList;

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
    void changePage(QUrl url);
    void closeEvent (QCloseEvent *event);


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

    void onPageUrlChange();

    void downloadRequested(QWebEngineDownloadItem* download);

private:
    Ui::Office *ui;
    webview *web;
    QWebEnginePage* page;
    QHash<int,QUrl> pageurl;
    QHash<int,QColor> shadowcolor;
    historyList *history;
    bool flag;
};

class historyList
{
private:
    historyList *first,*last,*current,*preNode,*nextNode;
    QString history;
    int length;

public:

    historyList()
    {
        first = nullptr;
        last = nullptr;
        current = nullptr;

        preNode = nullptr;
        nextNode = nullptr;

        length = 0;
    }
    void insert(QString str)
    {
        if(first==nullptr)
        {
            first = new historyList();
            first->preNode = nullptr;
            first->nextNode = nullptr;
            first->history = str;

            last = first;
            current = first;
        }
        else
        {
            if(first->history == str)
            {
                return;
            }
            historyList *temp = new historyList();
            temp->preNode = last;
            temp->nextNode = nullptr;
            temp->history = str;

            last->nextNode = temp;
            last = temp;
        }
        length++;
    }

    bool hasNext()
    {
        if(current->nextNode != nullptr)
        {
            return true;
        }
        return false;
    }

    QString next()
    {
        if(current->nextNode != nullptr)
        {
            current = current->nextNode;
            return current->history;
        }
    }

    bool hasPrevious()
    {
        if(current->preNode != nullptr)
        {
            return true;
        }
        return false;
    }

    QString currentUrl()
    {
        if(current != nullptr)
            return current->history;
        return nullptr;
    }

    QStringList allPages()
    {
        historyList *temp = new historyList;
        temp = first;
        QStringList list;

        if(first == nullptr)
        {
            QStringList templist;
            return  templist;
        }

        do
        {
            list.append(temp->history);
            temp = temp->nextNode;
        }while(temp != nullptr );

        return list;
    }

    QString previous()
    {
        if(current->preNode != nullptr)
        {
            current = current->preNode;
            return current->history;
        }
    }

    void insertNext(QString str)
    {
        historyList *temp = new historyList();
        temp->preNode = current;
        temp->nextNode = current->nextNode;
        temp->history = str;

        current->nextNode = temp;
        current = temp;
        length++;
    }

    historyList* firstpage()
    {
        return first;
    }

    historyList* currentPage()
    {
        return current;
    }

    historyList* lastPage()
    {
        return last;
    }

    int getLength()
    {
        return length;
    }
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
