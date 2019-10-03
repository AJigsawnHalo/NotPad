#include "notpad.h"
#include "ui_mainwindow.h"

NotPad::NotPad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	this->setWindowTitle("NotPad");
}

NotPad::~NotPad()
{
    delete ui;
}

QString activeFile = "";

void NotPad::on_actionNew_triggered(){
	
	activeFile = "";
	this->setWindowTitle("untitled");
	qDebug() << activeFile;
	ui->plainTextEdit->document()->clear();
}

void NotPad::on_actionOpen_triggered(){
	
	QString fileName = QFileDialog::getOpenFileName(this, "Open..", QDir::currentPath());

	QFile file(fileName);
	activeFile = fileName;

	QString currentDir = QDir::currentPath() + "/";
	int dirLength = currentDir.length();
	QString currentFile = activeFile.mid(dirLength);
	this->setWindowTitle(currentFile);
	qDebug() << activeFile;
	
	if (file.open(QIODevice::ReadOnly | QFile::Text)){
		QTextStream in(&file);
		QString content = in.readAll();
		ui->plainTextEdit->document()->setPlainText(content);
	}
	file.close();
}

void NotPad::saveFunc(QString fileName){

	QFile file(fileName);
	activeFile = fileName;

	QString currentDir = QDir::currentPath() + "/";
	int dirLength = currentDir.length();
	QString currentFile = activeFile.mid(dirLength);
	this->setWindowTitle(currentFile);
	qDebug() << activeFile;

	if(file.open(QIODevice::WriteOnly | QFile::Text)){
		QTextStream out(&file);
		QString content = ui->plainTextEdit->document()->toPlainText();
		out << content;
	}
	file.close();
}

void NotPad::saveAs(){

	QString fileName = QFileDialog::getSaveFileName(this, "Save As...", QDir::currentPath());

	saveFunc(fileName);
}

void NotPad::on_actionSave_triggered(){

	if(activeFile != ""){
		saveFunc(activeFile);
	}
	else {
		saveAs();
	}
}

void NotPad::on_actionSave_As_triggered(){
	
	saveAs();
}

