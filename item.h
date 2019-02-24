#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include "tag.h"

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QList<Tag*> tags READ tags WRITE setTags NOTIFY tagsChanged)

public:
    Item(QObject *parent = nullptr);
    QString name() const;
    void setName(const QString &name);
    QList<Tag*> tags();
    void setTags(const QList<Tag*> &tags);

signals:
    void nameChanged(const QString &name);
    void tagsChanged(const QList<Tag*> &tags);

private:
    QString name_;
    QList<Tag*> tags_;
};

#endif // ITEM_H
