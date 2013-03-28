#include "dataitem.h"

DataItem::DataItem(QString name, QString sort, QObject *parent) :
    QObject(parent), _name(name), _sort(sort)
{
}
