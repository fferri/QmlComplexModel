#include "myproxy.h"

MyProxy::MyProxy(QQmlObjectListModel<Item> *model, QObject *parent)
    : QObject(parent),
      model_(model)
{
}

void MyProxy::test()
{
    static int itemNumber = 0;
    static QStringList colors {"red", "green", "blue", "magenta", "orange", "gray", "navy"};
    static QStringList tags {"Foo", "Bar", "Baz", "Woop"};

    if(!itemNumber) itemNumber = model_->count();

    switch(qrand() % 8)
    {
    case 0:
    case 4:
        // add a new item
        model_->append(new Item(QStringLiteral("Item %1").arg(++itemNumber), {}));
        break;
    case 1:
    case 5:
    case 6:
        // add a tag to an item
        if(model_->isEmpty()) test();
        else model_->at(qrand() % model_->count())->tags()->append(new Tag(tags[qrand() % tags.count()], colors[qrand() % colors.count()]));
        break;
    case 2:
    case 7:
        // remove a tag
        if(model_->isEmpty()) test();
        else
        {
            auto t = model_->at(qrand() % model_->count())->tags();
            if(t->isEmpty()) test();
            else t->remove(qrand() % t->count());
        }
        break;
    case 3:
        // remove an item
        if(model_->isEmpty()) test();
        else model_->remove(qrand() % model_->count());
        break;
    }
}
