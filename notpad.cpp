#include "notpad.h"
#include "ui_mainwindow.h"

NotPad::NotPad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->stackedWidget->setVisible(false);
	this->setWindowTitle("NotPad");
}

NotPad::~NotPad()
{
    delete ui;
}


void NotPad::on_actionNew_triggered(){
	
	activeFile = "";
	this->setWindowTitle("untitled - NotPad");
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
	this->setWindowTitle(currentFile + " - NotPad");
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
	this->setWindowTitle(currentFile + " - NotPad");
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

void NotPad::on_actionPrint_triggered(){
	
	QPrinter printer;
	printer.setOutputFormat(QPrinter::NativeFormat);
	QPrintDialog printDlg(&printer, this);
	if(printDlg.exec() != QDialog::Rejected){
		ui->plainTextEdit->document()->print(&printer);
	}
}

void NotPad::on_actionExit_triggered(){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Quit", "Would You like to exit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {

        QApplication::quit();
      }
}

void NotPad::on_actionUndo_triggered(){

	ui->plainTextEdit->undo();
}

void NotPad::on_actionRedo_triggered(){

	ui->plainTextEdit->redo();
}

void NotPad::on_actionSelect_triggered(){

	QTextCursor cursor;
	cursor.clearSelection();
	cursor = ui->plainTextEdit->textCursor();
	cursor.select(QTextCursor::WordUnderCursor);
	ui->plainTextEdit->setTextCursor(cursor);
}

void NotPad::on_actionSelect_All_triggered(){

	ui->plainTextEdit->selectAll();
}
void NotPad::on_actionCut_triggered(){

	ui->plainTextEdit->cut();
}

void NotPad::on_actionCopy_triggered(){

	ui->plainTextEdit->copy();
}

void NotPad::on_actionPaste_triggered(){

	ui->plainTextEdit->paste();
}

void NotPad::on_actionDelete_triggered(){

	QTextCursor cursor;
	cursor = ui->plainTextEdit->textCursor();
	cursor.removeSelectedText();
}

void NotPad::on_actionFind_triggered(){

	ui->stackedWidget->setCurrentIndex(0);
	ui->stackedWidget->setVisible(true);
}

void NotPad::findFunc(QString exp){

	QTextCursor cursor = ui->plainTextEdit->textCursor();

	if(cursor.atEnd()){
		cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
		ui->plainTextEdit->setTextCursor(cursor);
		ui->plainTextEdit->find(exp);
	}
	else{
		ui->plainTextEdit->find(exp);
	}
}

void NotPad::on_buttonFind_clicked(){

	QString exp = ui->lineFind->text();
	findFunc(exp);
}

void NotPad::on_buttonClose_clicked(){

	ui->stackedWidget->setVisible(false);
}

void NotPad::replaceFunc(QString exp, QString replace){

	// FIXME: Add a way to confirm replacement and a Replace All.
	QTextCursor cursor;
	findFunc(exp);
	cursor = ui->plainTextEdit->textCursor();
	cursor.insertText(replace);
	ui->plainTextEdit->find(replace, QTextDocument::FindBackward);
}

void NotPad::on_actionReplace_triggered(){
	ui->stackedWidget->setCurrentIndex(1);
	ui->stackedWidget->setVisible(true);
}

void NotPad::on_buttonReplace_clicked(){

	QString exp, replace;
	exp = ui->lineFind2->text();
	replace = ui->lineReplace->text();
	replaceFunc(exp, replace);
}

void NotPad::on_buttonClose2_clicked(){

	ui->stackedWidget->setVisible(false);
}
