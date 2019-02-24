#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include "QQmlObjectListModel.h"
#include "tag.h"

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QQmlObjectListModelBase *tags READ tags CONSTANT)

public:
    Item(const QString &name, const QList<Tag*> &tags, QObject *parent = nullptr);
    QString name() const;
    void setName(const QString &name);
    QQmlObjectListModel<Tag> * tags();

signals:
    void nameChanged(const QString &name);

private:
    QString name_;
    QQmlObjectListModel<Tag> tags_;
};

#endif // ITEM_H
