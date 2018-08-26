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

#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <QApplication>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileInfo>
#include <QSettings>
#include <QDirIterator>
#include <QProcess>
#include <QTextStream>

#include "settingsmanage.h"
#include "utilities.h"

#include "libcprime_global.h"

class LIBCPRIMESHARED_EXPORT GlobalFunc {

public:

enum AppsName {
    damn = -1,
    CoreFM = 0,
    CoreImage,
    CorePad,
    CorePaint,
    CorePlayer,
    Dashboard,
    Bookmarks,
    About,
    StartView,
    Help,
    Settings,
    Search,
    CoreTime,
    CoreRenamer,
    CorePDF,
    CoreTerminal
};

enum Category {
    FileManager,
    TextEditor,
    ImageViewer,
    ImageEditor,
    MediaPlayer,
    PDFViwer,
    Terminal
};

static void appEngine(GlobalFunc::Category ctg , const QString path);

static void systemAppOpener(QString appName, const QString &arg = nullptr);

// bool checkRecentActivityFile();

static void appSelectionEngine(const QString &path);

};

#endif // GLOBALFUNCTIONS_H
