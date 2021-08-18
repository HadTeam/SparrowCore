#pragma once
#include <QString>
#include <QVector>
#include "utils.h"

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
		CommandLine(const QString& javaPath, const QVector<jvmArgument>& jvmArguments);	//只生成包含常量的和自定义的JVM参数的CommandLine，ProcessArguments在LaunchArgument中添加
	private:
		QString javaPath;
		QVector<processArgument> processArguments;
		QVector<jvmArgument> jvmArguments;
	};
	class CommandLineCreator
	{
	public:
		CommandLineCreator(void) {}
		static jvmArgument maxHeapSize(const qint8& size);
		static jvmArgument newHeapSize(const qint8& size);
		static jvmArgument useG1();
		static jvmArgument useAdaptiveSizePolicy();
		static jvmArgument useOmitStackTraceInFastThrow();
		static const jvmArgument constJvmArgs[];

		static processArgument username(const QString& username);
		static processArgument version(const QString& version);
		static processArgument gameDir(const QString& gameDir);
		static processArgument assetsDir(const QString& assetsDir);
		static processArgument assetIndex(const QString& assetIndex);
		static processArgument uuid(const QString& uuid);
		static processArgument userType(const QString& userType);
		static processArgument versionType(const QString& versionType);
		static processArgument* getProcessArguments(
			const QString& username,
			const QString& version,
			const QString& gameDir,
			const QString& assetsDir,
			const QString& assetIndex,
			const QString& uuid,
			const QString& userType,
			const QString& versionType
		);
	};
}
