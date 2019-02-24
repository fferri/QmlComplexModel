#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include "QQmlObjectListModel.h"
#include "tag.h"

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QQmlObjectListModelBase *tags READ tags WRITE setTags NOTIFY tagsChanged)

public:
    Item(const QString &name, const QList<Tag*> &tags, QObject *parent = nullptr);
    QString name() const;
    void setName(const QString &name);
    QQmlObjectListModelBase * tags();
    void setTags(QQmlObjectListModelBase *tags);

signals:
    void nameChanged(const QString &name);
    void tagsChanged(QQmlObjectListModelBase *tags);

private:
    QString name_;
    QQmlObjectListModel<Tag> tags_;
};

#endif // ITEM_H
