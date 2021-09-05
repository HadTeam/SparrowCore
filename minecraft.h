#pragma once
#include <QString>
#include <QUrl>
#include <QDir>
#include "utils.h"

using namespace Sparrow::utils;

namespace Sparrow {
    enum class __declspec(dllexport) versionType { RELEASE, SNAPSHOT, OLD_ALPHA, OLD_BETA };

    class __declspec(dllexport) MinecraftVersion {
    public:
        QString version;
        versionType type;
        fileInfo assetIndex;
        QString assetVersion;
        fileInfo clientJar;
        QVector<fileInfo> libs;
        QString mainClass;
        MinecraftVersion(void);
        MinecraftVersion(const QString& version, 
            const enum versionType& type, 
            const fileInfo& assetIndex,
            const QString& assetVersion,
            const fileInfo& clientJar,
            const QVector<fileInfo>& libs,
            const QString& mainClass);
        bool operator<(const MinecraftVersion& b);
        bool operator<(const QString& b);
        bool operator==(const MinecraftVersion& b);
        bool operator==(const QString& b);
        bool operator>(const MinecraftVersion& b);
        bool operator>(const QString& b);
        bool operator<=(const MinecraftVersion& b);
        bool operator<=(const QString& b);
        bool operator>=(const MinecraftVersion& b);
        bool operator>=(const QString& b);
    };

    class __declspec(dllexport) MinecraftDirectory {
    public:
        QDir rootDir;
        QDir versionsDir;
        QDir savesDir;
        QDir resourcepacksDir;
        QDir librariesDir;
        QDir crash_reportsDir;
        QDir assetsDir;
        MinecraftDirectory(void);
        MinecraftDirectory(const QString& rootDir);
    };

	class __declspec(dllexport) Minecraft
	{
    public:
        MinecraftVersion version;
        MinecraftDirectory root;
        QDir path;
        QString clientJarFile;
        QString jsonFile;
        Minecraft(void);
        Minecraft(
            const MinecraftVersion& version,
            const MinecraftDirectory& root,
            const QDir& path,
            const QString& clientJarFile,
            const QString& jsonFile);
        Minecraft(const QDir& dir);
	};
}
