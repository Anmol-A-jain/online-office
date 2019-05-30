#include "office.h"
#include "ui_office.h"
#include "home.h"
#include "word.h"
#include "excel.h"
#include "onedrive.h"
#include "outlook.h"
#include "powerpoint.h"
#include "onenote.h"
#include "sway.h"
#include "forms.h"

Office::Office(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Office)
{
    ui->setupUi(this);

    QWebEngineProfile::defaultProfile()->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);

    QGraphicsDropShadowEffect *Shadow = new QGraphicsDropShadowEffect;

    Shadow->setBlurRadius(9.0);
    Shadow->setOffset(9.0);

    ui->mainFrame->setGraphicsEffect(Shadow);
}

Office::~Office()
{
    delete ui;
}

void Office::showWindows(QMainWindow *o)
{
    o->show();
}

void Office::on_pushButton_clicked()
{
    showWindows(new Home);
}

void Office::on_pushButton_2_clicked()
{
    showWindows(new Word);
}

void Office::on_pushButton_3_clicked()
{
    showWindows(new excel);
}

void Office::on_pushButton_4_clicked()
{
    showWindows(new oneDrive);
}

void Office::on_pushButton_5_clicked()
{
    showWindows(new outlook);
}

void Office::on_pushButton_6_clicked()
{
    showWindows(new powerPoint);
}

void Office::on_pushButton_7_clicked()
{
    showWindows(new oneNote);
}

void Office::on_pushButton_8_clicked()
{
    showWindows(new Sway);
}

void Office::on_pushButton_9_clicked()
{
    showWindows(new Forms);
}
