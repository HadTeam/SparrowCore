#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QVector>
#include <QString>
#include <QUrl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <fastdownload.h>

enum versionType {
    RELEASE,
    SNAPSHOT,
    OLD_ALPHA,
    OLD_BETA
};

class MinecraftVersion{
public:
    QString version;
    versionType type;
    QUrl versionJson_URL;

    MinecraftVersion(QString& version, versionType& type, QUrl& versionJson_URL);
};

enum fileType{
    LIBRARY,
    LIBRARY_NATIVES,
    CLIENT_JAR
};

class fileInfo{
public:
    QUrl fileURL;
    QString filePath;
    QString hash;
    qint8 size;
    fileType type;

    fileInfo(QUrl& fileURL, QString& filePath, QString& hash, qint8& size, fileType& type);
    fastDownloadInfo getDownloadInfo();
};

class versionParseResult{
public:
    //param params;
    fileInfo assetIndex;
    QString assetVersion;
    fileInfo clientJar;
    QQueue<fileInfo> libs;
    QString mainClass;
    versionType versionType;

    versionParseResult(fileInfo& assetIndex, QString& assetVersion, fileInfo& clientJar, QQueue<fileInfo>& libs, QString& mainClass, enum versionType& versionType);
};

class jsonParser
{
public:
    jsonParser();
    static QVector<MinecraftVersion> parseMinecraftVersions(QJsonDocument versionManifest);
    static versionParseResult parseVersionJson(QJsonDocument versionInfo);
};


#endif // JSONPARSER_H
