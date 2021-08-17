#pragma once
#include <QString>
#include <QVector>

namespace Sparrow {
	namespace launch {
		class processArgument {
		private:
			QString key;
			QString value;
		public:
			QString toString();
			processArgument(void){}
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
		};
	}
}
