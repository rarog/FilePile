/****************************************************************************
**
** FilePile - Remote SSH file manager
** Copyright (C) 2014  Andrej Sinicyn
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

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
