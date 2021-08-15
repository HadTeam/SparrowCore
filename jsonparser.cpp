#include "jsonparser.h"

using namespace Sparrow;
using namespace Sparrow::Init;
using namespace Sparrow::Init::JsonParser;

const QMap<QString,versionType> jsonParser::strToVersionType={
    {"RELEASE",RELEASE},{"SNAPSHOT",SNAPSHOT},{"OLD_ALPHA",OLD_ALPHA},{"OLD_BETA",OLD_BETA}
};


libraryFile jsonParser::parseLibraryFile(const QJsonObject & libraryItem)
{
    QString temp = ".mincraft/libraries/"+libraryItem["path"].toString();
    return libraryFile(libraryItem["url"].toString(), temp.left(temp.lastIndexOf('/')), libraryItem["sha1"].toString(), libraryItem["size"].toInt());
}

nativesLibrary jsonParser::parseNativesLibrary(const QJsonObject & nativesLibraryItem){
    nativesLibrary result;
    result.nativesLibrary_Windows = parseLibraryFile(nativesLibraryItem["natives-windows"].toObject());
    result.nativesLibrary_Linux = parseLibraryFile(nativesLibraryItem["natives-linux"].toObject());
    result.nativesLibrary_macOS = parseLibraryFile(nativesLibraryItem["natives-macos"].toObject());
    return result;
}

QHash<QString, ParserResult_minecraftVersion> jsonParser::parseMinecraftVersions(const QJsonDocument& versionManifest)
{
    QHash<QString, ParserResult_minecraftVersion> result;
    for (QJsonValueRef i : versionManifest["versions"].toArray()) {
        QJsonObject obj=i.toObject();
        QString Version = obj["id"].toString();
        versionType versionType=strToVersionType[obj["type"].toString()];
        QUrl url = QUrl(obj["url"].toString());
        QString time = obj["time"].toString(), releaseTime = obj["releaseTime"].toString();
        result.insert(Version, ParserResult_minecraftVersion(Version, versionType, url, time, releaseTime));
    }
    return result;
}

minecraftVersion jsonParser::parseMinecraftVersion(const QJsonDocument & versionInfo)
{
    QString version = versionInfo["id"].toString();
    QString assetVersion = versionInfo["assets"].toString();
    versionType versionType = strToVersionType[versionInfo["type"].toString()];
    QString mainClass = versionInfo["mainClass"].toString();
    fileInfo assetIndex(versionInfo["assetIndex"]["url"].toString(),".minecraft/assets/indexes/", versionInfo["assetIndex"]["sha1"].toString(), versionInfo["assetIndex"]["size"].toInt());
    fileInfo clientJar(versionInfo["downloads"]["client"]["url"].toString(), ".minecraft/versions/"+versionInfo["id"].toString()+"/",versionInfo["downloads"]["client"]["sha1"].toString(),versionInfo["downloads"]["client"]["size"].toInt());
    QVector<fileInfo> libs;
    for(auto i : versionInfo["libraries"].toArray()){
        if(i.toObject()["classifiers"]==NULL){
            libs.push_back(parseLibraryFile(i.toObject()["artifact"].toObject()));
        }else{
            libs.push_back(nativesLibraryFile(parseLibraryFile(i.toObject()["artifact"].toObject()),parseNativesLibrary(i.toObject()["classifiers"].toObject())));
        }
    }
    return minecraftVersion(version, versionType, assetIndex, assetVersion, clientJar, libs, mainClass);
}

Sparrow::Minecraft Sparrow::Init::JsonParser::jsonParser::parseMinecraft(const QDir& dir)
{
    for (auto i : dir.entryList()) {
        if (i.endsWith(".json")) {
            minecraftVersion version = parseMinecraftVersion(QJsonDocument::fromJson(QFile(dir.dirName() + i).readAll()));
            MinecraftDirectory root = MinecraftDirectory(dir.dirName().left(dir.dirName().lastIndexOf("/versions") - 1));
            QString path = dir.dirName();
            QFile clientJar, jsonFile = QFile(dir.dirName() + i);
            for (auto k : dir.entryList()) {
                if (k.endsWith(".jar")) {
                    clientJar = QFile(dir.dirName() + k);
                }
            }
            return Minecraft(version, root, path, clientJar, jsonFile);
        }
    }
}

Sparrow::Minecraft::Minecraft(const QDir& dir) {
    for (auto i : dir.entryList()) {
        if (i.endsWith(".json")) {
            this->version = jsonParser::parseMinecraftVersion(QJsonDocument::fromJson(QFile(dir.dirName() + i).readAll()));
            this->root = MinecraftDirectory(dir.dirName().left(dir.dirName().lastIndexOf("/versions") - 1));
            this->path = dir.dirName();
            this->jsonFile = QFile(dir.dirName() + i);
            for (auto k : dir.entryList()) {
                if (k.endsWith(".jar")) {
                    this->clientJarFile = QFile(dir.dirName() + k);
                }
            }
        }
    }
}

QHash<QString, QString> Sparrow::Init::JsonParser::jsonParser::parseLatestVersion(const QJsonDocument& versionManifest)
{
    QJsonObject i = versionManifest["latest"].toObject();
    QHash<QString, QString> result;
    result.insert("release", i["release"].toString());
    result.insert("snapshot", i["snapshot"].toString());
}

nativesLibraryFile::nativesLibraryFile(const libraryFile &, const nativesLibrary & e){
    libraryFile(a);
    this->classifiers = e;
}

fileInfo::fileInfo(const QUrl &fileUrl, const QString &filePath, const QString &hash, const qint8 &size) : fileUrl(fileUrl), filePath(filePath), hash(hash), size(size)
{

}

Sparrow::Init::JsonParser::ParserResult_minecraftVersion::ParserResult_minecraftVersion(const QString& id, const versionType& type, const QUrl& url, const QString& time, const QString& releaseTime) : id(id), type(type), url(url), time(time), releaseTime(releaseTime)
{
}
