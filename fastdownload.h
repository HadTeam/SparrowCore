#ifndef FASTDOWNLOAD_H
#define FASTDOWNLOAD_H

#include <QtAlgorithms>
#include <QQueue>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>

namespace Sparrow {
	namespace utils {
		typedef qint16 fastDownloadStatus;
		typedef qint8 fastDownloadQueueId;
		typedef quint32 filePoint;

		typedef struct fastDownloadInfo {
			QString savePath, remotePath;
			fastDownloadStatus status;
			fastDownloadInfo() {
				this->status = 0;
			}
		} fastDownloadInfo;

		class fastDownload
		{
		public:
			fastDownload();
			~fastDownload();
			void downloadLoop();
			fastDownloadStatus startDownload(fastDownloadQueueId Id, filePoint startPos, filePoint endPos);

			static QQueue<fastDownloadInfo> downloadQueue;
		};
	}
}
#endif // FASTDOWNLOAD_H
