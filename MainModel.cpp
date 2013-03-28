#include "MainModel.h"

MainModel::MainModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    _roles.insert(HOMM_ROLE,"homm");
    QList<DataItem*> xs;
    xs << new DataItem("a","1") << new DataItem("b","1") << new DataItem("c","1");
    _items <<  qMakePair(-1, new MiniModel(xs) );
}

int MainModel::rowCount(const QModelIndex &) const {
    return _items.count();
}

QVariant MainModel::data(const QModelIndex &index, int role) const {
    qDebug() << "MainModel::data";
    if (index.row()<0 || index.row()>=_items.length())
        return QVariant();
    if (role == 0 || role==HOMM_ROLE) {
        return QVariant::fromValue(_items.at(index.row()).second);
    } else {
        return QVariant();
    }
}


void MainModel::onItemSelected(int x,int y) {
    Q_ASSERT(x==0);
    qDebug() << "MainModel::onItemSelected";
    QList<DataItem*> xs;
    for (int i=0; i<=y; ++i)
        xs << new DataItem(QString("%1").arg(i), "z");

    QModelIndex parent1 = createIndex(-1,-1); Q_UNUSED(parent1);
    const QModelIndex parent2; Q_UNUSED(parent2);
    beginInsertRows(parent1, 1, 1); // does not work
    //beginInsertRows(parent2, 1, 1); // works OK
    _items[0].first = x;
    _items << qMakePair(-1, new MiniModel(xs));
    endInsertRows();
}
