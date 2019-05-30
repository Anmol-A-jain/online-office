#ifndef ONENOTE_H
#define ONENOTE_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class oneNote;
}

class oneNote : public QMainWindow
{
    Q_OBJECT

public:
    explicit oneNote(QWidget *parent = nullptr);
    ~oneNote();
    void paintEvent(QPaintEvent *event);

private:
    Ui::oneNote *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // ONENOTE_H
