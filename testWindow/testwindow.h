#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class testWindow; }
QT_END_NAMESPACE

class testWindow : public QMainWindow
{
    Q_OBJECT

public:
    testWindow(QWidget *parent = nullptr);
    ~testWindow();

private:
    Ui::testWindow *ui;
};
#endif // TESTWINDOW_H
