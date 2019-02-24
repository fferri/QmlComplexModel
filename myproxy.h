#ifndef MYPROXY_H
#define MYPROXY_H

#include <QObject>
#include "QQmlObjectListModel.h"
#include "item.h"

class MyProxy : public QObject
{
    Q_OBJECT
public:
    explicit MyProxy(QQmlObjectListModel<Item> *model, QObject *parent = nullptr);

signals:

public slots:
    void test();

private:
    QQmlObjectListModel<Item> *model_;
};

#endif // MYPROXY_H
