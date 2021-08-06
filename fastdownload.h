#ifndef FASTDOWNLOAD_H
#define FASTDOWNLOAD_H

#include <QtAlgorithms>
#include <QQueue>
#include <QString>

typedef qint16 fastDownloadStatus;
typedef qint8 fastDownloadQueueId;
typedef quint32 filePoint;

typedef struct fastDonwloadInfo {
    QString savePath, remotePath;
    fastDownloadStatus status;
    fastDonwloadInfo() {
        this->status=0;
    }
} fastDonwloadInfo;

class fastDownload
{
public:
    fastDownload();
    ~fastDownload();
    void downloadLoop();
    fastDownloadStatus startDownload(fastDownloadQueueId Id, filePoint startPos, filePoint endPos);

    QQueue<fastDonwloadInfo> downloadQueue;
};

#endif // FASTDOWNLOAD_H
