#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class About;
}

class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private slots:
		void on_buttonLicense_clicked();
		void on_buttonSource_clicked();
		void on_buttonQtLicense_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
