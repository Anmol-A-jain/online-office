#ifndef SWAY_H
#define SWAY_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class Sway;
}

class Sway : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sway(QWidget *parent = nullptr);
    ~Sway();
    void paintEvent(QPaintEvent *event);

private:
    Ui::Sway *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // SWAY_H
