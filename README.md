Test application to show that
beginInsertRows(QModelIndex(-1,-1),...) --- OK
beginInsertRows(createIndex(-1,-1),....) ---- fail

See body of MainModel::onItemSelected()

N.B. Qt5 only
