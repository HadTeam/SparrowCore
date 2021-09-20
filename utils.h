#pragma once

#include <QDir>
#include "fastdownload.h"
#include <Windows.h>


namespace Sparrow::utils {
    typedef struct fileInfo {
        QUrl fileUrl;
        QString filePath;
        QString hash;
        qint8 size;

        fastDownloadInfo getDownloadInfo();

        fileInfo(void) {}

        fileInfo(const QUrl &fileUrl, const QString &filePath, const QString &hash, const qint8 &size);
    } fileInfo;

    typedef struct libraryFile : fileInfo {
        using fileInfo::fileInfo;
    } libraryFile;

    typedef struct nativesLibrary {
        libraryFile nativesLibrary_Windows;
        libraryFile nativesLibrary_Linux;
        libraryFile nativesLibrary_macOS;

        nativesLibrary(void) {}
    } nativesLibrary;

    typedef struct nativesLibraryFile : libraryFile {
        nativesLibrary classifiers;

        nativesLibraryFile(void) {}

        nativesLibraryFile(const libraryFile &, const nativesLibrary &e);
    } nativesLibraryFile;

    std::string getSystemName();

    std::string getSystemVersion();

}