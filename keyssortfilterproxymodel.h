#ifndef KEYSSORTFILTERPROXYMODEL_H
#define KEYSSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>
#include <QAbstractItemModel>
class KeysSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit KeysSortFilterProxyModel(QObject *parent = 0);
    QAbstractItemModel *model;
signals:
    
public slots:
    void search(QString search);
    void sortBy(QString roleName);
};

#endif // KEYSSORTFILTERPROXYMODEL_H
