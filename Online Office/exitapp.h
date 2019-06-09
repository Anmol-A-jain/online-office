#ifndef EXITAPP_H
#define EXITAPP_H

#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsEffect>
#include <QDebug>

namespace Ui {
class ExitApp;
}

class ExitApp : public QDialog
{
    Q_OBJECT

public:
    explicit ExitApp(QWidget *parent = nullptr);
    ~ExitApp();

private slots:
    void on_btnExit_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ExitApp *ui;
};

#endif // EXITAPP_H
