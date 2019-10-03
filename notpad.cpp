#include "notpad.h"
#include "ui_mainwindow.h"

NotPad::NotPad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

NotPad::~NotPad()
{
    delete ui;
}

QString activeFile = "";

void NotPad::on_actionNew_triggered(){
	activeFile = "Untitled.txt";
	ui->plainTextEdit->document()->clear();
}

void NotPad::on_actionOpen_triggered(){
	
	QString fileName = QFileDialog::getOpenFileName(this, "Open..", QDir::currentPath());

	QFile file(fileName);
	activeFile = fileName;

	if (file.open(QIODevice::ReadOnly | QFile::Text)){
		QTextStream in(&file);
		QString content = in.readAll();
		ui->plainTextEdit->document()->setPlainText(content);
	}
	file.close();
}
