#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Constructor, that creates the main application window.
 *
 * @param parent Parent form
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Show default frame
    on_actionAbout_triggered();
}

/**
 * @brief Destructor
 *
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Menu action, that shows the about dialog.
 *
 */
void MainWindow::on_actionAbout_triggered()
{
    auto aboutForm = new AboutForm(this);
    aboutForm->setAttribute(Qt::WA_DeleteOnClose);
    ui->ContentFrame->setWidget(aboutForm);
}
