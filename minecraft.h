#pragma once
#include <QString>
#include <QUrl>
#include <QDir>

namespace Sparrow {
    typedef enum versionType { RELEASE, SNAPSHOT, OLD_ALPHA, OLD_BETA } versionType;

    typedef struct minecraftVersion {
        QString version;
        versionType type;
        QUrl versionJsonUrl;
        minecraftVersion(void) {}
        minecraftVersion(const QString& version, const versionType& type, const QUrl& versionJsonUrl);
    } minecraftVersion;

	class Minecraft
	{
    public:
        minecraftVersion version;
        QDir rootPath;  //TODO 封装为类，提供方法获取各子路径、获取各版本信息
        QDir path;  //TODO 封装为类，提供方法获取版本信息
        Minecraft(){}
	};
}
