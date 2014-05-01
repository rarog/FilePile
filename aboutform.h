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

#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include <QWidget>
#include "common.h"

namespace Ui {
class AboutForm;
}

class AboutForm : public QWidget
{
    Q_OBJECT

public:
    explicit AboutForm(QWidget *parent = 0);
    ~AboutForm();

private:
    Ui::AboutForm *ui;

    QString getVersionText();
    QString compilerString();
    QString versionString();
    QString buildCompatibilityString();
};

#endif // ABOUTFORM_H
