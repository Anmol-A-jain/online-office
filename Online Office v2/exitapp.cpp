#include "exitapp.h"
#include "ui_exitapp.h"

ExitApp::ExitApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitApp)
{
    ui->setupUi(this);
    this->setWindowTitle("Office");
    this->setWindowIcon(QIcon(":/img/asset/logo.ico"));
    auto effect = new QGraphicsDropShadowEffect();
    effect->setOffset(.0);
    effect->setBlurRadius(25.0);
    effect->setColor(QColor(43, 87, 154));
    ui->btnCancel->setGraphicsEffect(effect);

    auto effect2 = new QGraphicsDropShadowEffect();
    effect2->setOffset(.0);
    effect2->setBlurRadius(25.0);
    effect2->setColor(QColor(232, 63, 36));
    ui->btnExit->setGraphicsEffect(effect2);
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
