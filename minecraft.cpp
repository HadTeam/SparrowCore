#include "Minecraft.h"
using namespace Sparrow;
using namespace Sparrow::utils;

Sparrow::minecraftVersion::minecraftVersion(const QString& version, const enum versionType& type, const fileInfo& assetIndex, const QString& assetVersion, const fileInfo& clientJar, const QVector<fileInfo>& libs, const QString& mainClass) : version(version), type(type), assetIndex(assetIndex), assetVersion(assetVersion), clientJar(clientJar), libs(libs), mainClass(mainClass)
{

}

bool minecraftVersion::operator<(const minecraftVersion& b) {
	return this->version < b.version;
}

bool Sparrow::minecraftVersion::operator<(const QString& b)
{
	return this->version < b;
}

bool Sparrow::minecraftVersion::operator==(const minecraftVersion& b)
{
	return this->version == b.version;
}

bool Sparrow::minecraftVersion::operator==(const QString& b)
{
	return this->version == b;
}

bool Sparrow::minecraftVersion::operator>(const minecraftVersion& b)
{
	return this->version > b.version;
}

bool Sparrow::minecraftVersion::operator>(const QString& b)
{
	return this->version > b;
}

bool Sparrow::minecraftVersion::operator<=(const minecraftVersion& b)
{
	return this->version < b.version || this->version == b.version;
}

bool Sparrow::minecraftVersion::operator<=(const QString& b)
{
	return this->version < b|| this->version == b;
}

bool Sparrow::minecraftVersion::operator>=(const minecraftVersion& b)
{
	return this->version > b.version || this->version == b.version;
}

bool Sparrow::minecraftVersion::operator>=(const QString& b)
{
	return this->version > b || this->version == b;
}

Sparrow::MinecraftDirectory::MinecraftDirectory(const QString& rootDir)
{
	this->rootDir = QDir(rootDir);
	this->assetsDir = QDir(rootDir + "/assets");
	this->crash_reportsDir = QDir(rootDir + "/crash-reports");
	this->librariesDir = QDir(rootDir + "/libraries");
	this->resourcepacksDir = QDir(rootDir + "/resourcepacks");
	this->savesDir = QDir(rootDir + "/saves");
	this->versionsDir = QDir(rootDir + "/versionsDir");
}

Sparrow::Minecraft::Minecraft(const minecraftVersion& version, const MinecraftDirectory& root, const QDir& path, const QString& clientJarFile, const QString& jsonFile) : version(version), root(root), path(path), clientJarFile(clientJarFile), jsonFile(jsonFile)
{
}
