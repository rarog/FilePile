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
