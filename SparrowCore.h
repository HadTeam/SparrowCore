#ifndef SPARROWCORE_H
#define SPARROWCORE_H

#include "SparrowCore_global.h"
#include "jsonParser.h"
#include "CommandLine.h"
#include "utils.h"
#include "Minecraft.h"
#include "Launcher.h"

class SPARROWCORE_EXPORT SparrowCore
{
public:
    SparrowCore();
    QNetworkAccessManager * networkManager;
};

#endif // SPARROWCORE_H
