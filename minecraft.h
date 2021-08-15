#pragma once
#include <QString>
#include <QUrl>
#include <QDir>
#include "utils.h"

using namespace Sparrow::utils;

namespace Sparrow {
    typedef enum versionType { RELEASE, SNAPSHOT, OLD_ALPHA, OLD_BETA } versionType;

    typedef struct minecraftVersion {
        QString version;
        versionType type;
        fileInfo assetIndex;
        QString assetVersion;
        fileInfo clientJar;
        QVector<fileInfo> libs;
        QString mainClass;
        minecraftVersion(void) {}
        minecraftVersion(const QString& version, 
            const enum versionType& type, 
            const fileInfo& assetIndex,
            const QString& assetVersion,
            const fileInfo& clientJar,
            const QVector<fileInfo>& libs,
            const QString& mainClass);
        bool operator<(const minecraftVersion& b);
        bool operator<(const QString& b);
        bool operator==(const minecraftVersion& b);
        bool operator==(const QString& b);
        bool operator>(const minecraftVersion& b);
        bool operator>(const QString& b);
        bool operator<=(const minecraftVersion& b);
        bool operator<=(const QString& b);
        bool operator>=(const minecraftVersion& b);
        bool operator>=(const QString& b);
    } minecraftVersion;

    class MinecraftDirectory {
    public:
        QDir rootDir;
        QDir versionsDir;
        QDir savesDir;
        QDir resourcepacksDir;
        QDir librariesDir;
        QDir crash_reportsDir;
        QDir assetsDir;
        MinecraftDirectory(void){}
        MinecraftDirectory(const QString& rootDir);
        QVector<Minecraft> getMinecrafts();
    };

	class Minecraft
	{
    public:
        minecraftVersion version;
        MinecraftDirectory root;
        QDir path;
        QFile clientJarFile;
        QFile jsonFile;
        Minecraft(void){}
        Minecraft(
            const minecraftVersion& version,
            const MinecraftDirectory& root,
            const QDir& path,
            const QFile& clientJarFile,
            const QFile& jsonFile);
        Minecraft(const QDir& dir);
	};
}
