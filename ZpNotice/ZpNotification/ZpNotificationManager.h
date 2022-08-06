#ifndef ZPNOTIFICATIONMANAGER_H
#define ZPNOTIFICATIONMANAGER_H

#include <QObject>
#include <QQueue>

#include "ZpNotification.h"

class ZpNotificationManager: public QObject
{
    Q_OBJECT
public:
    explicit ZpNotificationManager( QObject *parent = 0);

    void notify(const QString &title, const QString &body, const QString &icon, const QString url);
    void setMaxCount(int count);
    void setDisplayTime(int ms);

private:
    class NotifyData {
    public:
        NotifyData(const QString &icon, const QString &title, const QString &body, const QString url):
          icon(icon),
          title(title),
          body(body),
          url(url)
        {
        }

        QString icon;
        QString title;
        QString body;
        QString url;
    };

    void rearrange();
    void showNext();

    QQueue<NotifyData> dataQueue;
    QList<ZpNotification*> notifyList;
    int maxCount;
    int displayTime;
};

#endif // ZPNOTIFICATIONMANAGER_H


