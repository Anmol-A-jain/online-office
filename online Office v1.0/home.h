#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();
    void paintEvent(QPaintEvent *event);


private slots:
    void on_lineEdit_returnPressed();


private:
    Ui::Home *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // HOME_H
