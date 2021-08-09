#include "testwindow.h"
#include "ui_testwindow.h"
#include "../sparrowcore.h"

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

