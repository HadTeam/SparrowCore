#pragma once

#include <QString>
#include <QVector>
#include "utils.h"
#include "Minecraft.h"

namespace Sparrow::launch {
    class processArgument {
    private:
        QString key;
        QString value;
    public:
        QString toString();

        processArgument(void) {}

        processArgument(QString key, QString value);
    };

    class jvmArgument {
        QString key;
        QString value;
    public:
        jvmArgument(void) {}

        QString toString();

        jvmArgument(QString key, QString value);
    };

    class CommandLine {
        CommandLine(void) {}

        CommandLine(const QString &javaPath,
                    const QVector<jvmArgument> &jvmArguments);    //ֻ���ɰ��������ĺ��Զ����JVM������CommandLine��ProcessArguments��LaunchArgument������
    private:
        QString javaPath;
        QVector<processArgument> processArguments;
        QVector<jvmArgument> jvmArguments;
    };

    class CommandLineCreator {
    public:
        CommandLineCreator(void) {}

        static jvmArgument maxHeapSize(const qint8 &size);

        static jvmArgument newHeapSize(const qint8 &size);

        static jvmArgument useG1();

        static jvmArgument useAdaptiveSizePolicy();

        static jvmArgument useOmitStackTraceInFastThrow();

        static const jvmArgument constJvmArgs[];

        static processArgument username(const QString &username);

        static processArgument version(const QString &version);

        static processArgument gameDir(const QString &gameDir);

        static processArgument assetsDir(const QString &assetsDir);

        static processArgument assetIndex(const QString &assetIndex);

        static processArgument uuid(const QString &uuid);

        static processArgument userType(const QString &userType);

        static processArgument versionType(const QString &versionType);

        static processArgument *getProcessArguments(
                const QString &username,
                const QString &version,
                const QString &gameDir,
                const QString &assetsDir,
                const QString &assetIndex,
                const QString &uuid,
                const QString &userType,
                const QString &versionType
        );
    };

    class __declspec(dllexport) LaunchArgument {
        jvmArgument osName;
        jvmArgument osVersion;
        jvmArgument javaLibraryPath;
        jvmArgument cp;
        jvmArgument log4jConfigurationFile;
        QString mainClass;
        processArgument username;
        processArgument version;
        processArgument gameDir;
        processArgument assetsDir;
        processArgument assetIndex;
        processArgument uuid;
        processArgument accessToken;
        processArgument userType;
        processArgument versionType;
        jvmArgument *additionalJvmArgument;
        processArgument *additionalProcessArgument;
    public:
        LaunchArgument(const jvmArgument &osName, const jvmArgument &osVersion, const jvmArgument &javaLibraryPath,
                       const jvmArgument &cp, const jvmArgument &log4JConfigurationFile, const QString &mainClass,
                       const processArgument &username, const processArgument &version, const processArgument &gameDir,
                       const processArgument &assetsDir, const processArgument &assetIndex, const processArgument &uuid,
                       const processArgument &accessToken, const processArgument &userType,
                       const processArgument &versionType, jvmArgument *additionalJvmArgument,
                       processArgument *additionalProcessArgument);
    };
}
