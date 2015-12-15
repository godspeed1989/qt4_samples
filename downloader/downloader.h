#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSslError>
#include <QUrl>
#include <QFile>
#include <QList>
#include <QMutex>
#include <QObject>

typedef struct DownloadTask
{
    QNetworkReply *reply;
    QString filepath;
}DownloadTask;

class DownloadManager: public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager();
    void doDownload(const QUrl &url, const QString filepath);
    int pendingTaskNum()
    {
        int ret;
        taskListMutex.lock();
        ret = taskList.size();
        taskListMutex.unlock();
        return ret;
    }
private:
    QNetworkAccessManager manager;
    QList<DownloadTask> taskList;
    QMutex taskListMutex;
public slots:
    void downloadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &errors);
};

#endif // DOWNLOADER_H
