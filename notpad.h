#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class NotPad : public QMainWindow
{
    Q_OBJECT

public:
    NotPad(QWidget *parent = nullptr);
    ~NotPad();

private slots:
	void on_actionNew_triggered();
	void on_actionOpen_triggered();
	void saveFunc(QString fileName);
	void saveAs();
	void on_actionSave_triggered();
	void on_actionSave_As_triggered();
	void on_actionPrint_triggered();
	void on_actionExit_triggered();
	void on_actionUndo_triggered();
	void on_actionRedo_triggered();
	void on_actionSelect_triggered();
	void on_actionSelect_All_triggered();
	void on_actionCut_triggered();
	void on_actionCopy_triggered();
	void on_actionPaste_triggered();
	void on_actionDelete_triggered();

private:
    Ui::MainWindow *ui;
	QPrinter printer;
};
#endif // MAINWINDOW_H
