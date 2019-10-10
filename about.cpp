#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
		this->setWindowTitle("About NotPad");
}

About::~About()
{
    delete ui;
}

void About::on_buttonSource_clicked()
{
	QDesktopServices::openUrl(QUrl("https://github.com/AJigsawnHalo/NotPad", QUrl::TolerantMode));
}

void About::on_buttonLicense_clicked()
{
	QDesktopServices::openUrl(QUrl("https://github.com/AJigsawnHalo/NotPad/blob/master/LICENSE", QUrl::TolerantMode));
}

void About::on_buttonQtLicense_clicked()
{
	QDesktopServices::openUrl(QUrl("https://doc.qt.io/qt-5/lgpl.html", QUrl::TolerantMode));
}
