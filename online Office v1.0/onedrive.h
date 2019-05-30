#ifndef ONEDRIVE_H
#define ONEDRIVE_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class oneDrive;
}

class oneDrive : public QMainWindow
{
    Q_OBJECT

public:
    explicit oneDrive(QWidget *parent = nullptr);
    ~oneDrive();
    void paintEvent(QPaintEvent *event);

private:
    Ui::oneDrive *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // ONEDRIVE_H
