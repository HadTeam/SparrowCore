#include "jsonparser.h"

QVector<MinecraftVersion> jsonParser::parseMinecraftVersions(QJsonDocument document)
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

MinecraftVersion::MinecraftVersion(QString& version, versionType& type, QUrl& versionJson_URL)
{
           this->version = version;
           this->type = type;
           this->versionJson_URL = versionJson_URL;
}

fileInfo::fileInfo() {

}

fileInfo::fileInfo(QUrl& fileURL, QString& filePath, QString& hash, qint8& size, fileType& type){
    this->fileURL = fileURL;
    this->filePath = filePath;
    this->hash = hash;
    this->size = size;
    this->type = type;
}


versionParseResult::versionParseResult(fileInfo& assetIndex, QString& assetVersion, fileInfo& clientJar, QQueue<fileInfo>& libs, QString& mainClass, enum versionType& versionType){
    this->assetIndex = assetIndex;
    this->assetVersion = assetVersion;
    this->clientJar = clientJar;
    this->libs = libs;
    this->mainClass = mainClass;
    this->versionType = versionType;
}
