#include "jsonparser.h"

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

QVector<minecraftVersion> jsonParser::parseMinecraftVersions(const QJsonDocument & document)
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

versionParseResult jsonParser::parseVersionJson(const QJsonDocument & versionInfo)
{
    versionParseResult result;
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
    return versionParseResult{assetIndex, assetVersion, clientJar, libs, mainClass, versionType};
}

nativesLibraryFile::nativesLibraryFile(const libraryFile &, const nativesLibrary & e){
    libraryFile(a);
    this->classifiers = e;
}


minecraftVersion::minecraftVersion(const QString &version, const versionType &type, const QUrl &versionJsonUrl) : version(version), type(type), versionJsonUrl(versionJsonUrl)
{

}

fileInfo::fileInfo(const QUrl &fileUrl, const QString &filePath, const QString &hash, const qint8 &size) : fileUrl(fileUrl), filePath(filePath), hash(hash), size(size)
{

}

versionParseResult::versionParseResult(const fileInfo &assetIndex, const QString &assetVersion, const fileInfo &clientJar, const QVector<fileInfo> &libs, const QString &mainClass, const enum versionType &versionType) : assetIndex(assetIndex), assetVersion(assetVersion), clientJar(clientJar), libs(libs), mainClass(mainClass), versionType(versionType)
{

}

