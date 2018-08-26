/*
libcprime is a library for CoreApps

libcprime is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include <QIODevice>
#include <QSettings>
#include <QFont>
#include <QStyle>
#include <QGraphicsDropShadowEffect>
#include <QDesktopWidget>
#include <QScreen>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QTimer>
#include <QFontMetrics>
#include <QIcon>
#include <QMimeDatabase>
#include <QMimeType>
#include <QApplication>
#include <QDate>
#include <QTime>
#include <QCollator>
#include <QMessageBox>

#include "settingsmanage.h"

#include "libcprime_global.h"

class LIBCPRIMESHARED_EXPORT Utilities {

public:
enum MessageType {
    Info = 0,
    Warning = 1,
    Tips = 2
};

enum sortOrder {
    ASCENDING = 0,
    DESCENDING = 1
};

enum FolderSetup {
    BookmarkFolder = 0,
    DriveMountFolder = 1,
    TrashFolder
};

enum StyleAppName {
    AboutStyle,
    BookmarkItStyle,
    BookmarksStyle,
    CoreActionStyle,
    CoreArchiverStyle,
    CoreBoxStyle,
    CoreFMStyle,
    CoreImageStyle,
    CorePadStyle,
    CorePaintStyle,
    CorePlayerStyle,
    CoreRenamerStyle,
    CoreShotStyle,
    CoreTimeStyle,
    DashBoardStyle,
    DialogStyle,
    HelpStyle,
    PropertiesStyle,
    SearchStyle,
    SettingsStyle,
    StartStyle
};

static QRect screensize();

static QString checkIsValidDir(const QString str);
static QString checkIsValidFile(const QString str);

static bool moveToTrash(const QStringList &fileNames);

static void messageEngine(const QString &message, Utilities::MessageType messageType);

static QSettings *getStylesheetValue();
static QString getStylesheetFileContent(Utilities::StyleAppName san);
static QString readStringFromFile(const QString &path, const QIODevice::OpenMode &mode);

static QStringList fStringList(QStringList left, QStringList right, QFont font);

static QString formatSize(qint64 num);

static QString sentDateText(const QString &dateTime);
static bool saveToRecent(const QString &appName, const QString &pathName);

static void setupFolder(Utilities::FolderSetup fs);

static QIcon getAppIcon(const QString &appName);
static QIcon getFileIcon(const QString &filePath);

static QStringList sortDate(QStringList &dateList, Utilities::sortOrder s = ASCENDING);
static QStringList sortTime(QStringList &timeList, Utilities::sortOrder s = ASCENDING, QString format = "hh.mm.ss");
static QStringList sortList(QStringList &list, Utilities::sortOrder s = ASCENDING);
static QStringList sortDateTime(QStringList &dateTimeList, Utilities::sortOrder s = ASCENDING);

static void addDropShadow(QWidget *widget, const int alpha, const int blur = 25, const QString stylesheet = "") {
    SettingsManage sm;
    if (sm.getAddShadow()) {
         QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(widget);
         effect->setBlurRadius(blur);
         effect->setColor(QColor(0, 0, 0, alpha));
         effect->setOffset(0);
         widget->setGraphicsEffect(effect);
         if (!stylesheet.isNull())
             widget->setStyleSheet(stylesheet);
    }
}

};

#endif // UTILITIES_H
