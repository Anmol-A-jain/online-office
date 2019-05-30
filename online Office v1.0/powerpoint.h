#ifndef POWERPOINT_H
#define POWERPOINT_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class powerPoint;
}

class powerPoint : public QMainWindow
{
    Q_OBJECT

public:
    explicit powerPoint(QWidget *parent = nullptr);
    ~powerPoint();
    void paintEvent(QPaintEvent *event);

private:
    Ui::powerPoint *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // POWERPOINT_H
