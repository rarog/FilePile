#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Show default frame
    on_actionAbout_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    auto aboutForm = new AboutForm(this);
    aboutForm->setAttribute(Qt::WA_DeleteOnClose);
    ui->ContentFrame->setWidget(aboutForm);
}
