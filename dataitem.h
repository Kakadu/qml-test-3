#ifndef DATAITEM_H
#define DATAITEM_H

#include <QObject>
#include <QDebug>

class DataItem : public QObject
{
    Q_OBJECT
    QString _name, _sort;
    //Q_PROPERTY(QString READ name NOTIFY nameChanged);

public:
    explicit DataItem(QString name,QString sort, QObject *parent = 0);
    Q_INVOKABLE QString name() {
        return _name;
    }
    Q_INVOKABLE QString sort() {
        return _sort;
    }

signals:
    void nameChanged();
public slots:

};

#endif // DATAITEM_H
