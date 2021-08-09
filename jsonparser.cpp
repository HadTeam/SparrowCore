#include "jsonparser.h"

const QMap<QString,versionType> jsonParser::strToVersionType={
    {"RELEASE",RELEASE},{"SNAPSHOT",SNAPSHOT},{"OLD_ALPHA",OLD_ALPHA},{"OLD_BETA",OLD_BETA}
};


QVector<minecraftVersion> jsonParser::parseMinecraftVersions(QJsonDocument document)
{
    QVector<minecraftVersion> result;
    for (QJsonValueRef i : document["versions"].toArray()) {
        QJsonObject obj=i.toObject();
        QString objVersion = obj["id"].toString();
        QString objVersionType = obj["type"].toString();
        versionType _versionType;
        _versionType=strToVersionType[objVersionType];
        result.push_front(minecraftVersion{objVersion, _versionType, QUrl(obj["url"].toString())});
    }
    return result;
}

