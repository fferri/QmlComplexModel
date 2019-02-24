#include "item.h"

Item::Item(const QString &name, const QList<Tag*> &tags, QObject *parent)
    : QObject(parent),
      name_(name)
{
    for(auto tag : tags)
        tags_.append(tag);
}

QString Item::name() const
{
    return name_;
}

void Item::setName(const QString &name)
{
    if(name != name_)
    {
        name_ = name;
        emit nameChanged(name_);
    }
}

QQmlObjectListModelBase * Item::tags()
{
    return &tags_;
}

void Item::setTags(QQmlObjectListModelBase *tags)
{
    tags_.clear();
    for(int i = 0; i < tags->count(); i++)
        tags_.append(tags->get(i));
}
