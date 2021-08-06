#include "jsonparser.h"

QVector<MinecraftVersion> jsonParser::getMinecraftVersions(QJsonDocument document)
{
        QVector<MinecraftVersion> result;
        for (auto i : document.object().value("versions").toArray()) {
            QJsonObject j = i.toObject();
            QString version = j.value("id").toString();
            QString _versionType = j.value("type").toString();
            versionType versionType;
            if (_versionType == "release") {
                versionType = RELEASE;
            }
            else if (_versionType == "snapshot") {
                versionType = SNAPSHOT;
            }
            else if (_versionType == "old_alpha") {
                versionType = OLD_ALPHA;
            }
            else /**if (_versionType == "old_beta")**/ {
                versionType = OLD_BETA;
            }
            QUrl URL(j.value("url").toString());
            result.push_front(MinecraftVersion(version, versionType, URL));
        }
        return result;
}

MinecraftVersion::MinecraftVersion(QString version, versionType type, QUrl versionJson_URL)
{
           this->version = version;
           this->type = type;
           this->versionJson_URL = versionJson_URL;
}
