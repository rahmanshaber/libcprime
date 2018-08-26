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

#ifndef SETTINGSMANAGE_H
#define SETTINGSMANAGE_H

#include <QDir>
#include <QIcon>
#include <QFileInfo>
#include <QSettings>
#include <QVariant>

#include "libcprime_global.h"

class LIBCPRIMESHARED_EXPORT SettingsManage
{

public:
    SettingsManage();
    QSettings *cSetting;
    void createDefaultSettings();

    bool setSpecificValue(QString groupName, QString keyName, QVariant value);
    QVariant getSpecificValue(QString groupName, QString keyName);

    QString getTerminal();
    bool setTerminal(QString termName);

    const QString getStartupPath();
    bool setStartupPath(const QString path);

    QString getThemeName();
    bool setThemeName(QString themeName);

    bool setFileManager(QString fmName);
    QString getFileManager();

    bool setTextEditor(QString textEditorName);
    QString getTextEditor();

    bool setImageViewer(QString imageViewerName);
    QString getImageViewer();

    bool setImageEditor(QString imageEditorName);
    QString getImageEditor();

    bool setPDFVierwer(QString imageEditorName);
    QString getPDFVierwer();

    bool setMediaPlayer(QString imageEditorName);
    QString getMediaPlayer();

    bool getIsRealMimeType();
    bool setIsRealMimeType(bool isRealMime);

    int getZoomValue();
    bool setZoomValue(int value);

    int getZoomTreeValue();
    bool setZoomTreeValue(int value);

    int getZoomListValue();
    bool setZoomListValue(int value);

    int getZoomDetailValue();
    bool setZoomDetailValue(int value);

    bool getIsShowThumb();
    bool setIsShowThumb(bool isShowThumb);

    bool getShowToolbox();
    bool setShowToolbox(bool showTool);

    bool getViewMode();
    bool setViewMode(bool mode);

    const QString getSCSaveLocation();
    bool setSCSaveLocation(const QString path);

    bool getShowBattery();
    bool setSHowBattery(bool showBattery);

    bool getDisableRecent();
    bool setDisableRecent(bool showRecent);

    QString getTimeFormat();
    bool setTimeFormat(QString AmPm);

    bool getShowHidden();
    bool setShowHidden(bool showTool);

    bool getShowCalander();
    bool setSHowCalander(bool showBattery);

    bool getShowSystem();
    bool setSHowSystem(bool showSystem);

    bool getShowNetwork();
    bool setSHowNetwork(bool showNetwork);

    bool getShowCalculator();
    bool setSHowCalculator(bool showCalculator);

    bool getShowNote();
    bool setSHowNote(bool showNote);

    bool setSHowTime(bool showTime);
    bool getShowTime();

    bool setStyleMode(bool mode);
    bool getStyleMode();

    bool setFontStyle(QString fontStyle);
    QString getFontStyle();

    bool setAddShadow(bool addShadow);
    bool getAddShadow();
};

#endif // SETTINGSMANAGE_H
