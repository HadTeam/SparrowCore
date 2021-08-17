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
	else //"-D"
		return key + "=" + value;
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
	return jvmArgument("-Xmn",size+"m");
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

const jvmArgument CommandLineCreator::constJvmArgs[] = {
	jvmArgument("-XX","HeapDumpPath=MojangTricksIntelDriversForPerformance_javaw.exe_minecraft.exe.heapdump"),
	jvmArgument("-Dos.name", QString::fromStdString(getSystemName())),
	jvmArgument("-Dos.version", QString::fromStdString(getSystemVersion()))
};