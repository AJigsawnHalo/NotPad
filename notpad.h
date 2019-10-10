#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextBlock>
#include <QFontDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "about.h"

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
	void on_actionFind_triggered();
	void findFunc(QString exp);
	void on_buttonFind_clicked();
	void on_buttonClose_clicked();
	void replaceFunc(QString exp, QString replace);
	void on_actionReplace_triggered();
	void on_buttonReplace_clicked();
	void on_buttonClose2_clicked();
	void on_actionGo_To_triggered();
	void on_buttonClose3_clicked();
	void on_buttonGo_clicked();
	void on_actionWord_Wrap_toggled(bool arg1);
	void on_actionZoom_In_triggered();
	void on_actionZoom_Out_triggered();
	void on_actionReset_Zoom_triggered();
	void on_actionFont_triggered();
	void on_actionView_Source_Code_triggered();
	void on_actionAbout_NotPad_triggered();

private:
    Ui::MainWindow *ui;
	QString activeFile = "";
	QPrinter printer;
	int currentZoom = 0;
	About ab;
};
#endif // MAINWINDOW_H
