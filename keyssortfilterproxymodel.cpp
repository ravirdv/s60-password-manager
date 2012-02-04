#include "keyssortfilterproxymodel.h"
#include "QDebug"
KeysSortFilterProxyModel::KeysSortFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

void KeysSortFilterProxyModel::sortBy(QString roleName)
{
    beginResetModel(); // Do I really need that?
    if (roleName == "name") {
    setSortRole(1);
    endResetModel();
}
}
void KeysSortFilterProxyModel::search(QString search)
{
        setFilterCaseSensitivity(Qt::CaseInsensitive);
        setFilterRole(1);
        setFilterWildcard(search);
}
