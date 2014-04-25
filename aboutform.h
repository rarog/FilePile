#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include <QWidget>

const auto APP_NAME = "FilePile";
const auto VERSION = "1.0.0";
const auto COPYRIGHT_YEAR = "2014";
const auto AUTHOR = "Andrej Sinicyn";

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
