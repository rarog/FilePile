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

#include "aboutform.h"
#include "ui_aboutform.h"

/**
 * @brief Constructor, that creates the application info form.
 *
 * @param parent Parent form
 */
AboutForm::AboutForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);

    // Load version info
    ui->infoTextBox->setPlainText(getVersionText());
}


/**
 * @brief Destructor
 *
 */
AboutForm::~AboutForm()
{
    delete ui;
}

/**
 * @brief Compiles all information for the info box.
 *
 * @return QString
 */
QString AboutForm::getVersionText() {
    QString result = tr(
       "%1\n"
       "%2\n"
       "\n"
       "Built on %3 at %4\n"
       "\n"
       "Copyright %5 %6. All rights reserved.\n"
       "\n"
       "Icon taken from Crystal Project Icons\n"
       "AUTHOR: Everaldo Coelho\n"
       "SITE: http://www.everaldo.com\n"
       "CONTACT: everaldo@everaldo.com\n"
       "Copyright (c) 2006-2007 Everaldo Coelho."
       "\n"
       "The program is provided AS IS with NO WARRANTY OF ANY KIND, "
       "INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A "
       "PARTICULAR PURPOSE.")
       .arg(
            versionString(),
            buildCompatibilityString(),
            QLatin1String(__DATE__),
            QLatin1String(__TIME__),
            QLatin1String(COPYRIGHT_YEAR),
            QLatin1String(AUTHOR)
        );

    return result;
}

/**
 * @brief Compiles information about used compiler.
 * @details Taken from icore.cpp of Qt Creator.
 *
 * @return QString
 */
QString AboutForm::compilerString(){
#if defined(Q_CC_CLANG) // must be before GNU, because clang claims to be GNU too
    QString isAppleString;
#if defined(__apple_build_version__) // Apple clang has other version numbers
    isAppleString = QLatin1String(" (Apple)");
#endif
    return QLatin1String("Clang " ) + QString::number(__clang_major__) + QLatin1Char('.')
            + QString::number(__clang_minor__) + isAppleString;
#elif defined(Q_CC_GNU)
    return QLatin1String("GCC " ) + QLatin1String(__VERSION__);
#elif defined(Q_CC_MSVC)
    if (_MSC_VER >= 1800) // 1800: MSVC 2013 (yearly release cycle)
        return QLatin1String("MSVC ") + QString::number(2008 + ((_MSC_VER / 100) - 13));
    if (_MSC_VER >= 1500) // 1500: MSVC 2008, 1600: MSVC 2010, ... (2-year release cycle)
        return QLatin1String("MSVC ") + QString::number(2008 + 2 * ((_MSC_VER / 100) - 15));
#endif
    return QLatin1String("<unknown compiler>");
}

/**
 * @brief Compiles information block with application name and version.
 *
 * @return QString
 */
QString AboutForm::versionString(){
    return tr("%1 %2\n").arg(
        QLatin1String(APP_NAME),
        QLatin1String(VERSION)
    );
}

/**
 * @brief Compiles information about used Qt version.
 *
 * @return QString
 */
QString AboutForm::buildCompatibilityString()
{
    return tr("Based on Qt %1 (%2, %3 bit)").arg(
        QLatin1String(qVersion()),
        compilerString(),
        QString::number(QSysInfo::WordSize)
    );
}
