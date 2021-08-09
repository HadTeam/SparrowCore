#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QVector>
#include <QString>
#include <QUrl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "fastdownload.h"

typedef enum versionType { RELEASE,SNAPSHOT,OLD_ALPHA,OLD_BETA } versionType;

typedef struct minecraftVersion{
    QString version;
    versionType type;
    QUrl versionJsonUrl;
    minecraftVersion(void){}
    minecraftVersion(const QString & version, const versionType & type, const QUrl & versionJsonUrl);
} minecraftVersion;
typedef struct fileInfo{
    QUrl fileUrl;
    QString filePath;
    QString hash;
    qint8 size;
    fastDownloadInfo getDownloadInfo();
    fileInfo(void){}
    fileInfo(const QUrl & fileUrl, const QString & filePath, const QString & hash, const qint8 & size);
} fileInfo;
typedef struct libraryFile:fileInfo{
    using fileInfo::fileInfo;
} libraryFile;
typedef struct nativesLibrary{
    libraryFile nativesLibrary_Windows;
    libraryFile nativesLibrary_Linux;
    libraryFile nativesLibrary_macOS;
    nativesLibrary(void){}
} nativesLibrary;
typedef struct nativesLibraryFile : libraryFile{
    nativesLibrary classifiers;
    nativesLibraryFile(void){}
    nativesLibraryFile(const libraryFile &, const nativesLibrary & e);
} nativesLibraryFile;
typedef struct versionParseResult{
    fileInfo assetIndex;
    QString assetVersion;
    fileInfo clientJar;
    QVector<fileInfo> libs;
    QString mainClass;
    versionType versionType;
    versionParseResult(void){}
    versionParseResult(const fileInfo & assetIndex, const QString & assetVersion, const fileInfo & clientJar, const QVector<fileInfo> & libs, const QString & mainClass, const enum versionType & versionType);
} versionParseResult;

class jsonParser
{
private:
    static const QMap<QString,versionType> strToVersionType; // Fastly convent version type from QString to versionType
    static libraryFile parseLibraryFile(const QJsonObject & libraryItem);
    static nativesLibrary parseNativesLibrary(const QJsonObject & nativesLibraryItem);

public:
    jsonParser(){}
    static QVector<minecraftVersion> parseMinecraftVersions(const QJsonDocument & versionManifest);
    static versionParseResult parseVersionJson(const QJsonDocument & versionInfo);
};


#endif // JSONPARSER_H
