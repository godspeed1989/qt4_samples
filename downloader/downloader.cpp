#include "downloader.h"

DownloadManager::DownloadManager()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::doDownload(const QUrl &url, const QString filepath)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);
#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            SLOT(sslErrors(QList<QSslError>)));
#endif
    DownloadTask task;
    task.reply = reply;
    task.filepath = filepath;
    taskListMutex.lock();
    taskList.append(task);
    taskListMutex.unlock();
}

void DownloadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#ifndef QT_NO_SSL
    foreach (const QSslError &error, sslErrors)
        fprintf(stderr, "SSL error: %s\n", qPrintable(error.errorString()));
#else
    Q_UNUSED(sslErrors);
#endif
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    int i;
    taskListMutex.lock();

    for(i = 0; i < taskList.size(); i++)
        if (taskList[i].reply == reply)
            break;
    if (i == taskList.size())
        return;

    if (reply->error())
    {
        fprintf(stderr, "Download of %s failed: %s\n",
                reply->url().toEncoded().constData(),
                qPrintable(reply->errorString()));
    }
    else
    {
        QFile file(taskList[i].filepath);
        file.write(reply->readAll());
        file.close();
        fprintf(stdout, "Download %s", taskList[i].filepath.toStdString().c_str());
    }
    taskList.removeAt(i);
    taskListMutex.unlock();

    reply->deleteLater();
}
