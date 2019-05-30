#ifndef OFFICE_H
#define OFFICE_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QWebEngineProfile>


namespace Ui {
class Office;
}

class Office : public QMainWindow
{
    Q_OBJECT

public:
    explicit Office(QWidget *parent = nullptr);
    ~Office();
    void showWindows(QMainWindow *o);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Office *ui;
};

#endif // OFFICE_H
