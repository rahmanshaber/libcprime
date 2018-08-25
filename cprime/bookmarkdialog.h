/*
Bookmarks app for bookmarking files

Bookmarks is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef BOOKMARKDIALOG_H
#define BOOKMARKDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QTimer>

#include "utilities.h"
#include "bookmarkmanage.h"
#include "libcprime_global.h"

namespace Ui {
class bookmarkDialog;
}

class LIBCPRIMESHARED_EXPORT bookmarkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bookmarkDialog(QWidget *parent = nullptr);
    ~bookmarkDialog();

    void callBookMarkDialog(QWidget *parent, const QString &currentPath);
    void checkPath();
    void setBookPath(const QString &path);
    void setBookName(const QString &bName);
    QString getBookName();
    QString getSectionName();
    bool accepted = false;

private slots:
    void on_done_clicked();
    void bookMarkName_Changed();
    void item_Changed();
    void on_bkSection_currentIndexChanged(const QString &arg1);
    void on_bkName_textChanged(const QString &arg1);

private:
    Ui::bookmarkDialog *ui;
    BookmarkManage bk;
};

#endif // BOOKMARKDIALOG_H