#include "commandline.h"
using namespace Sparrow::launch;

QString Sparrow::launch::processArgument::toString()
{
	return "--" + key + " " + value;
}

Sparrow::launch::processArgument::processArgument(QString key, QString value) : key(key), value(value)
{
}

QString Sparrow::launch::jvmArgument::toString()
{
	if (!key.startsWith("-D"))
		return key + "=" + value;
	else
		return "-D" + key + "=" + value;
}

Sparrow::launch::jvmArgument::jvmArgument(QString key, QString value) : key(key), value(value)
{
}

jvmArgument Sparrow::launch::CommandLineCreator::maxHeapSize(const qint8& size)
{
	return jvmArgument("-Xmx", size + "m");
}

jvmArgument Sparrow::launch::CommandLineCreator::newHeapSize(const qint8& size)
{
	return jvmArgument("-Xmn",size+"m");
}

jvmArgument Sparrow::launch::CommandLineCreator::useG1()
{
	return jvmArgument("-XX:", "+UseG1GC");
}

jvmArgument Sparrow::launch::CommandLineCreator::useAdaptiveSizePolicy()
{
	return jvmArgument("-XX:", "-UseAdaptiveSizePolicy");
}

jvmArgument Sparrow::launch::CommandLineCreator::useOmitStackTraceInFastThrow()
{
	return jvmArgument("-XX:", "-OmitStackTraceInFastThrow");
}
