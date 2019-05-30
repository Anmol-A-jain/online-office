#ifndef WORD_H
#define WORD_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class Word;
}

class Word : public QMainWindow
{
    Q_OBJECT

public:
    explicit Word(QWidget *parent = nullptr);
    ~Word();
    void paintEvent(QPaintEvent *event);

private:
    Ui::Word *ui;
    QWebEngineView *web;
    QWebEnginePage *webpage;
};

#endif // WORD_H
