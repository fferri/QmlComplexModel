#ifndef TAG_H
#define TAG_H

#include <QObject>

class Tag : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString tagName READ tagName WRITE setTagName NOTIFY tagNameChanged)
    Q_PROPERTY(QString tagColor READ tagColor WRITE setTagColor NOTIFY tagColorChanged)

public:
    Tag(const QString &name, const QString &color, QObject *parent = nullptr);
    QString tagName() const;
    void setTagName(const QString &name);
    QString tagColor() const;
    void setTagColor(const QString &color);

signals:
    void tagNameChanged(const QString &name);
    void tagColorChanged(const QString &color);

private:
    QString name_;
    QString color_;
};

#endif // TAG_H
