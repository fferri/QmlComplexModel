#include "tag.h"

Tag::Tag(QObject *parent)
    : QObject(parent)
{
}

QString Tag::tagName() const
{
    return name_;
}

void Tag::setTagName(const QString &name)
{
    if(name != name_)
    {
        name_ = name;
        emit tagNameChanged(name_);
    }
}

QString Tag::tagColor() const
{
    return color_;
}

void Tag::setTagColor(const QString &color)
{
    if(color != color_)
    {
        color_ = color;
        emit tagColorChanged(color_);
    }
}
