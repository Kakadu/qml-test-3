#include "MiniModel.h"

MiniModel::MiniModel(QList<DataItem*> lst, QObject *parent) :
    QAbstractItemModel(parent), _items(lst)
{
    _roles.insert(QWE_ROLE,"qwe");
}

QVariant MiniModel::data(const QModelIndex &index, int role) const {
    if (index.row()<0 || index.row()>_items.length())
        return QVariant();
    if (role == 0 || role==QWE_ROLE) {
        return QVariant::fromValue<QObject*>(_items.at(index.row()));
    } else {
        return QVariant();
    }
}
 int MiniModel::rowCount(const QModelIndex &parent) const {
     Q_UNUSED(parent);
     return _items.count();
 }
