#pragma once
#include <QDir>
#include "fastdownload.h"
#include <Windows.h>
#include "SparrowCore_global.h"

namespace Sparrow::utils {
	class __declspec(dllexport) fileInfo {
	public:
		QUrl fileUrl;
		QString filePath;
		QString hash;
		qint8 size;
		fastDownloadInfo getDownloadInfo();
		fileInfo(void) {}
		fileInfo(const QUrl& fileUrl, const QString& filePath, const QString& hash, const qint8& size);
	};

	class __declspec(dllexport) libraryFile : public fileInfo {
		using fileInfo::fileInfo;
	};

	class __declspec(dllexport) nativesLibrary {
	public:
		libraryFile nativesLibrary_Windows;
		libraryFile nativesLibrary_Linux;
		libraryFile nativesLibrary_macOS;
		nativesLibrary(void);
	};

	class __declspec(dllexport) nativesLibraryFile : public libraryFile {
	public:
		nativesLibrary classifiers;
		nativesLibraryFile(void);
		nativesLibraryFile(const libraryFile&, const nativesLibrary& e);
	};

	std::string getSystemName();

	std::string getSystemVersion();
}