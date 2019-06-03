#ifndef EXITAPP_H
#define EXITAPP_H

#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsEffect>

namespace Ui {
class ExitApp;
}

class ExitApp : public QDialog
{
    Q_OBJECT

public:
    explicit ExitApp(QWidget *parent = nullptr);
    ~ExitApp();
    void setPointer(ExitApp* e)
    {
        this->e = e;
    }

private slots:
    void on_btnExit_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ExitApp *ui;
    ExitApp *e;

};

#endif // EXITAPP_H
