#include "exitapp.h"
#include "ui_exitapp.h"

ExitApp::ExitApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitApp)
{
    ui->setupUi(this);

    this->setWindowTitle("Office");
    this->setWindowIcon(QIcon(":/img/asset/logo.ico"));
}

ExitApp::~ExitApp()
{
    delete ui;
}

void ExitApp::on_btnExit_clicked()
{
    qApp->exit();
}

void ExitApp::on_btnCancel_clicked()
{
    QKeyEvent *event = new QKeyEvent( QEvent::KeyPress, Qt::Key_Escape ,Qt::NoModifier);
    QCoreApplication::postEvent (this, event);
}
