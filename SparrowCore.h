#ifndef SPARROWCORE_H
#define SPARROWCORE_H

#include "SparrowCore_global.h"
#include "fastDownload.h"
#include "jsonParser.h"

class SPARROWCORE_EXPORT SparrowCore
{
public:
    SparrowCore();
    QNetworkAccessManager * networkManager;
};

#endif // SPARROWCORE_H
