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

#include "globalfunctions.h"


//bool checkRecentActivityFile()
//{
//    QFile file(QDir::homePath() + "/.config/coreBox/RecentActivity");
//    if (file.exists()) {
//        return true;
//    }
//    return false;
//}



// =========================================================================
#include <QString>
#include <QStringList>
#include "settingsmanage.h"
void GlobalFunc::appEngine(GlobalFunc::Category ctg ,const QString path)
{
    SettingsManage sm;

    switch (ctg) {

    case GlobalFunc::Category::FileManager: {

        QString defultFileManager = sm.getFileManager(); // selected FileManager name from settings.

        QProcess::startDetached(defultFileManager.toLower(), QStringList() << path);

        // Show message
        QString mess = defultFileManager + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        // Save file to RecentActivity
        Utilities::saveToRecent(defultFileManager,path);

        break;
    }
    case GlobalFunc::Category::TextEditor: {

        QString defultTextEditor = sm.getTextEditor(); // selected TextEditor name from settings.

        QProcess::startDetached(defultTextEditor.toLower(), QStringList() << path);

        // Show message
        QString mess = defultTextEditor + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        // Save file to RecentActivity
        Utilities::saveToRecent(defultTextEditor,path);

        break;
    }
    case GlobalFunc::Category::ImageViewer: {

        QString defultImageViewer = sm.getImageViewer(); // selected ImageViewer name from settings.

        QProcess::startDetached(defultImageViewer.toLower(), QStringList() << path);

        // Show message
        QString mess = defultImageViewer + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        // Save file to RecentActivity
        Utilities::saveToRecent(defultImageViewer,path);

        break;
    }

    case GlobalFunc::Category::ImageEditor: {

        QString defultImageEditor = sm.getImageEditor(); // selected ImageEditor name from settings.

        QProcess::startDetached(defultImageEditor.toLower(), QStringList() << path);

        // Show message
        QString mess = defultImageEditor + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        // Save file to RecentActivity
        Utilities::saveToRecent(defultImageEditor,path);

        break;
    }

    case GlobalFunc::Category::MediaPlayer: {

        QString defultMediaPlayer = sm.getMediaPlayer(); // selected ImageEditor name from settings.

        QProcess::startDetached(defultMediaPlayer.toLower(), QStringList() << path);

        // Show message
        QString mess = defultMediaPlayer + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        // Save file to RecentActivity
        Utilities::saveToRecent(defultMediaPlayer,path);

        break;
    }


    case GlobalFunc::Category::PDFViwer: {

        QString defultPDFViwer = sm.getPDFVierwer(); // selected ImageEditor name from settings.

        QProcess::startDetached(defultPDFViwer.toLower(), QStringList() << path);

        // Show message
        QString mess = defultPDFViwer + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        // Save file to RecentActivity
        Utilities::saveToRecent(defultPDFViwer,path);

        break;
    }

    case GlobalFunc::Category::Terminal: {

        QString defultTerminal = sm.getTerminal(); // selected terminal name from settings.
        QStringList args(defultTerminal.split(" "));
        QString name = args.at(0);
        args.removeAt(0);

        if (name == "CoreTerminal") {
            GlobalFunc::systemAppOpener("CoreTerminal",path);
        } else {
            QProcess::startDetached(name, args, path);
        }

        // Show message
        QString mess = defultTerminal + " opening " ;
        Utilities::messageEngine(mess, Utilities::MessageType::Info);

        break;
    }

    }
}


#include <QString>
#include <QStringList>
void GlobalFunc::systemAppOpener(QString appName, const QString &arg) // engine to open app in window
{
    QProcess::startDetached(appName.toLower(), QStringList() << arg);

    // Show message
    QString mess = appName + " opening " ;
    Utilities::messageEngine(mess, Utilities::MessageType::Info);
}


void GlobalFunc::appSelectionEngine(const QString &path) // engine send right file to coreapps or system
{
    QFileInfo info(path);
    if(!info.exists() && !path.isEmpty()){
        // Function from utilities.cpp
        Utilities::messageEngine("File not exists", Utilities::MessageType::Warning);
        return;
    }

    QStringList image,txts,pdf,media;
    image << "jpg" << "jpeg" << "png" << "bmp" << "ico" << "svg" << "gif" ;
    txts << "txt" << "pro" << "" ;
    pdf << "pdf" << "xps" << "oxps" << "epub" << "cbr" << "cbz" << "cbt" << "cba" ;
    media << "webm" << "ogg" << "mpeg" << "mov" << "mkv" << "flv" << "avi"
           << "mp3" << "aac" << "m4a"  << "flac";

    QString suffix = QFileInfo(path).suffix();

    //File Manager
    if (info.isDir()) {
        GlobalFunc::appEngine(GlobalFunc::Category::FileManager, info.absoluteFilePath());
        return;
    }

    //Image Viewer
    else if (image.contains(suffix, Qt::CaseInsensitive)) {
        GlobalFunc::appEngine(GlobalFunc::Category::ImageViewer, info.absoluteFilePath());
        return;
    }

    //Text Editor
    else if (txts.contains(suffix, Qt::CaseInsensitive)) {
        GlobalFunc::appEngine(GlobalFunc::Category::TextEditor, info.absoluteFilePath());
        return;
    }

    //PDF Viewer
    else if (pdf.contains(suffix, Qt::CaseInsensitive)) {
        GlobalFunc::appEngine(GlobalFunc::Category::PDFViwer, info.absoluteFilePath());
        return;
    }

    //Media Player
    else if (media.contains(suffix, Qt::CaseInsensitive)) {
        GlobalFunc::appEngine(GlobalFunc::Category::MediaPlayer, info.absoluteFilePath());
        return;
    }

    //sendto System
    else {
        QProcess::startDetached("xdg-open", QStringList() << path);
    }
}






//void GlobalFunc::appEngines(GlobalFunc::AppsName i, const QString &arg) // engine to open app in window
//{
//    switch (i) {
//    case GlobalFunc::AppsName::CoreFM: {
//        corefm *app = new corefm();
//        QString str = Utilities::checkIsValidDir(arg);
//        if (!str.isEmpty() || !str.isNull()) app->goTo(str);
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CoreImage: {
//        coreimage *app = new coreimage();
//        QString str = Utilities::checkIsValidFile(arg);
//        if (str.count())
//            app->loadFile(str);
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CorePad: {
//        corepad *app = new corepad();
//        app->openText(Utilities::checkIsValidFile(arg));
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CorePaint: {
//        corepaint *app = new corepaint();
//        const QString str = Utilities::checkIsValidFile(arg);
//        if (str.count()) app->initializeNewTab(true, str);
//        else app->initializeNewTab();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CorePlayer: {
//        coreplayer *app = new coreplayer();
//        const QString str = Utilities::checkIsValidFile(arg);
//        if (!str.isEmpty() || !str.isNull()) app->openPlayer(str);
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::Dashboard: {
//        dashboard *app = new dashboard();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::Bookmarks: {
//        bookmarks *app = new bookmarks();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::About: {
//        about *app = new about();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::StartView: {
//        Start *app = new Start();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::Help: {
//        help *app = new help();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::Settings: {
//        settings *app = new settings();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::Search: {
//        search *app = new search();
//        QString str = Utilities::checkIsValidDir(arg);
//        if (!str.isEmpty() || !str.isNull()) app->setPath(str);
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CoreTime: {
//        coretime *app = new coretime();
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CorePDF: {
//        corepdf *app = new corepdf();
//        const QString str = Utilities::checkIsValidFile(arg);
//        if (!str.isEmpty() || !str.isNull()) app->openPdfFile(str);
//        app->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CoreTerminal: {
//        QString workDir = arg;
//        if (!arg.count())
//            workDir = QDir::homePath();
//        if (QFileInfo(workDir).isFile())
//            workDir = QFileInfo(arg).path();

//        coreterminal *cterm = new coreterminal( workDir, "" /*, Parent Needed */);
//        cterm->show();

//        break;
//    }
//    case GlobalFunc::AppsName::CoreRenamer: {
//        corerenamer *app = new corerenamer();
//        const QString str = Utilities::checkIsValidDir(arg);
//        if (str.count()) app->addPath(str);
//        app->show();

//        break;
//    }
//    default:
//        break;
//    }
//}





