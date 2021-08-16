#pragma once
#include <QString>
#include <QVector>

namespace Sparrow {
	namespace launch {
		class CommandLine {
			CommandLine(void){}
		private:
			QString javaPath;
			QVector<processArgument> processArguments;
			QVector<jvmArgument> jvmArguments;
		};
		class processArgument {
			processArgument(void) {}
		private:
			QString key;
			QString value;
		public:
			QString toString();
			processArgument(QString key, QString value);
		};
		class jvmArgument {
			jvmArgument(void) {}
			QString key;
			QString value;
		public:
			QString toString();
			jvmArgument(QString key, QString value);
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
		};
	}
}
