#ifndef OUTLOOK_H
#define OUTLOOK_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class outlook;
}

class outlook : public QMainWindow
{
    Q_OBJECT

public:
    explicit outlook(QWidget *parent = nullptr);
    ~outlook();
    void paintEvent(QPaintEvent *event);

private:
    Ui::outlook *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // OUTLOOK_H
