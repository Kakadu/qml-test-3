#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QAbstractItemModel>
#include "MiniModel.h"
static const int HOMM_ROLE = 555;
class MainModel : public QAbstractItemModel
{
    Q_OBJECT
    QList<QPair<int,MiniModel*> > _items;
    QHash<int,QByteArray> _roles;

public:
    explicit MainModel(QObject *parent = 0);
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
    Q_INVOKABLE QList<QString> printroles() {
        QList<QString> ans;
        foreach(QByteArray b, _roles)
            ans << b;
        return ans;
    }

    QModelIndex index(int row, int column, const QModelIndex &parent) const {
        Q_UNUSED(column);
        if (row >= 0 && row < rowCount(parent))
            return createIndex(row,0);
        else
            return QModelIndex();
    }
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
signals:

public slots:
    void onItemSelected(int x, int y);
};

#endif // MAINMODEL_H
