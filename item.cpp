#include "item.h"

Item::Item(QObject *parent)
    : QObject(parent)
{
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

QList<Tag *> Item::tags()
{
    return tags_;
}

void Item::setTags(const QList<Tag *> &tags)
{
    if(tags != tags_)
    {
        tags_ = tags;
        emit tagsChanged(tags_);
    }
}
