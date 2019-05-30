#ifndef EXCEL_H
#define EXCEL_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class excel;
}

class excel : public QMainWindow
{
    Q_OBJECT

public:
    explicit excel(QWidget *parent = nullptr);
    ~excel();
    void paintEvent(QPaintEvent *event);

private:
    Ui::excel *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // EXCEL_H
