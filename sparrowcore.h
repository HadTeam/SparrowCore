#ifndef SPARROWCORE_H
#define SPARROWCORE_H

#include "SparrowCore_global.h"
#include "fastdownload.h"
#include "jsonparser.h"

class SPARROWCORE_EXPORT SparrowCore
{
public:
    SparrowCore();
    QNetworkAccessManager * networkManager;
};

#endif // SPARROWCORE_H
