#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QVector>
#include <QString>
#include <QUrl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

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

    MinecraftVersion(QString version, versionType type, QUrl versionJson_URL);
};

class jsonParser
{
public:
    jsonParser();
    static QVector<MinecraftVersion> getMinecraftVersions(QJsonDocument document);
};


#endif // JSONPARSER_H
