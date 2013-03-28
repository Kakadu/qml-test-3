#ifndef MINIMODEL_H
#define MINIMODEL_H

#include <QAbstractItemModel>
#include "dataitem.h"
static const int QWE_ROLE = 666;
class MiniModel : public QAbstractItemModel
{
    Q_OBJECT

    QList<DataItem*> _items;
    QHash<int,QByteArray> _roles;
public:
    explicit MiniModel(QList<DataItem*>, QObject *parent = 0);
    int columnCount(const QModelIndex &) const {
        return 1;
    }
    bool hasChildren(const QModelIndex &) const {
        return (rowCount(QModelIndex()) > 0);
    }
    QModelIndex parent(const QModelIndex &) const {
        return createIndex(-1,-1,(void*)NULL);
    }
    virtual QHash<int,QByteArray> roleNames() const {
        return _roles;
    }
    Q_INVOKABLE QList<QByteArray> printroles() {
        return _roles.values();
    }

    QModelIndex index(int row, int column, const QModelIndex &parent) const {
        Q_UNUSED(column);
        if (row >= 0 && row < rowCount(parent))
            return createIndex(row,0);
        else
            return QModelIndex();
    }
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:

public slots:

};

#endif // MINIMODEL_H
