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
typedef enum fileType { LIBRARY,LIBRARY_NATIVES,CLIENT_JAR } fileType;

typedef struct minecraftVersion{
    QString version;
    versionType type;
    QUrl versionJsonUrl;
} minecraftVersion;
typedef struct fileInfo{
    QUrl fileURL;
    QString filePath;
    QString hash;
    qint8 size;
    fileType type;
    fastDownloadInfo getDownloadInfo();
} fileInfo;
typedef struct versionParseResult{
    fileInfo assetIndex;
    QString assetVersion;
    fileInfo clientJar;
    QQueue<fileInfo> libs;
    QString mainClass;
    versionType versionType;
} versionParseResult;

class jsonParser
{
private:
    static const QMap<QString,versionType> strToVersionType; // Fastly convent version type from QString to versionType
public:
    jsonParser();
    static QVector<minecraftVersion> parseMinecraftVersions(QJsonDocument document);
    static versionParseResult parseVersionJson(QJsonDocument versionInfo);
};


#endif // JSONPARSER_H
