#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QVector>
#include <QString>
#include <QUrl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHash>
#include "minecraft.h"
#include "utils.h"

using namespace Sparrow::utils;

namespace Sparrow::Init::JsonParser {
	class ParserResult_minecraftVersion {
	public:
		QString id;
		versionType type;
		QUrl url;
		QString time;
		QString releaseTime;
		ParserResult_minecraftVersion(void) {}
		ParserResult_minecraftVersion(
			const QString& id,
			const versionType& type,
			const QUrl& url,
			const QString& time,
			const QString& releaseTime);
	};

	class jsonParser
	{
	private:
		static const QMap<QString, versionType> strToVersionType; // Fastly convent version type from QString to versionType
		static libraryFile parseLibraryFile(const QJsonObject& libraryItem);
		static nativesLibrary parseNativesLibrary(const QJsonObject& nativesLibraryItem);

	public:
		jsonParser() {}
		static QHash<QString, ParserResult_minecraftVersion> parseMinecraftVersions(const QJsonDocument& versionManifest);
		static Sparrow::minecraftVersion parseMinecraftVersion(const QJsonDocument& versionInfo);
		static Sparrow::Minecraft parseMinecraft(const QDir& dir);
		static QHash<QString, QString> parseLatestVersion(const QJsonDocument& versionManifest);
	};

}

#endif // JSONPARSER_H