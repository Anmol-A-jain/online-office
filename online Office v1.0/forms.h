#ifndef FORMS_H
#define FORMS_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class Forms;
}

class Forms : public QMainWindow
{
    Q_OBJECT

public:
    explicit Forms(QWidget *parent = nullptr);
    ~Forms();
    void paintEvent(QPaintEvent * event);

private:
    Ui::Forms *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // FORMS_H
