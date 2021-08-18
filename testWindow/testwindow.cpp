#include "testWindow.h"
#include "UI_TestWindow.h"
#include "../SparrowCore.h"

testWindow::testWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::testWindow)
{
    ui->setupUi(this);
}

testWindow::~testWindow()
{
    delete ui;
}

