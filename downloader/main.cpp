#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QtTest/QTest>
#include <cmath>
#include "downloader.h"

void tiles_map_down(int zoom, DownloadManager& manager)
{
    // http://b.tile.openstreetmap.org/0/0/0.png
#define map_type ""
#define suffix   ".png"
    QString base_url = "http://b.tile.openstreetmap.org/" map_type "%1/%2/%3" suffix;
    QString base_path = "./" map_type "%1/%2/%3" suffix;

    int size = 1 << zoom;
    for (int col = 0; col < size; col++)
    {
        for (int row = 0; row < size; row++)
        {
            QUrl url(base_url.arg(zoom).arg(col).arg(row));
            QString filepath = base_path.arg(zoom).arg(col).arg(row);
            manager.doDownload(url, filepath);
            qDebug() << filepath;
            while (manager.pendingTaskNum() > 0)
            {
                QTest::qWait(10*1000);
            }
        }
    }
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    DownloadManager manager;

    tiles_map_down(4, manager);

    return app.exec();
}
