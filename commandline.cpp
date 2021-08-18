#include "commandline.h"
using namespace Sparrow::launch;
using namespace Sparrow::utils;

QString processArgument::toString()
{
	return "--" + key + " " + value;
}

processArgument::processArgument(QString key, QString value) : key(key), value(value)
{
}

QString jvmArgument::toString()
{
	if (key.startsWith("-X"))
		return key + value;
	else if (key.startsWith("-XX"))
		return key + ":" + value;
	else if (key.startsWith("-D"))
		return key + "=" + value;
	else if (key.startsWith("-cp"))
		return key + " " + value;
}

jvmArgument::jvmArgument(QString key, QString value) : key(key), value(value)
{
}

jvmArgument CommandLineCreator::maxHeapSize(const qint8& size)
{
	return jvmArgument("-Xmx", size + "m");
}

jvmArgument CommandLineCreator::newHeapSize(const qint8& size)
{
	return jvmArgument("-Xmn", size + "m");
}

jvmArgument CommandLineCreator::useG1()
{
	return jvmArgument("-XX", "+UseG1GC");
}

jvmArgument CommandLineCreator::useAdaptiveSizePolicy()
{
	return jvmArgument("-XX", "-UseAdaptiveSizePolicy");
}

jvmArgument CommandLineCreator::useOmitStackTraceInFastThrow()
{
	return jvmArgument("-XX", "-OmitStackTraceInFastThrow");
}

processArgument Sparrow::launch::CommandLineCreator::username(const QString& username)
{
	return processArgument("username", username);
}

processArgument Sparrow::launch::CommandLineCreator::version(const QString& version)
{
	return processArgument("version", version);
}

processArgument Sparrow::launch::CommandLineCreator::gameDir(const QString& gameDir)
{
	return processArgument("gameDir", gameDir);
}

processArgument Sparrow::launch::CommandLineCreator::assetsDir(const QString& assetsDir)
{
	return processArgument("assetsDir", assetsDir);
}

processArgument Sparrow::launch::CommandLineCreator::assetIndex(const QString& assetIndex)
{
	return processArgument("assetIndex", assetIndex);
}

processArgument Sparrow::launch::CommandLineCreator::uuid(const QString& uuid)
{
	return processArgument("uuid", uuid);
}

processArgument Sparrow::launch::CommandLineCreator::userType(const QString& userType)
{
	return processArgument("userType", userType);
}

processArgument Sparrow::launch::CommandLineCreator::versionType(const QString& versionType)
{
	return processArgument("versionType", versionType);
}

processArgument* Sparrow::launch::CommandLineCreator::getProcessArguments(const QString& username, const QString& version, const QString& gameDir, const QString& assetsDir, const QString& assetIndex, const QString& uuid, const QString& userType, const QString& versionType)
{
	processArgument a[8];
	a[0] = CommandLineCreator::username(username);
	a[1] = CommandLineCreator::version(version);
	a[2] = CommandLineCreator::gameDir(gameDir);
	a[3] = CommandLineCreator::assetsDir(assetsDir);
	a[4] = CommandLineCreator::assetIndex(assetIndex);
	a[5] = CommandLineCreator::uuid(uuid);
	a[6] = CommandLineCreator::userType(userType);
	a[7] = CommandLineCreator::versionType(versionType);
	return a;
}

const jvmArgument CommandLineCreator::constJvmArgs[] = {
	jvmArgument("-XX","HeapDumpPath=MojangTricksIntelDriversForPerformance_javaw.exe_minecraft.exe.heapdump"),
	jvmArgument("-Dos.name", QString::fromStdString(getSystemName())),
	jvmArgument("-Dos.version", QString::fromStdString(getSystemVersion()))
};

Sparrow::launch::CommandLine::CommandLine(const QString& javaPath, const QVector<jvmArgument>& jvmArguments) : javaPath(javaPath), jvmArguments(jvmArguments){
	for (auto i : CommandLineCreator::constJvmArgs) {
		this->jvmArguments.push_front(i);
	}
}
