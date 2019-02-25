#include "myproxy.h"

MyProxy::MyProxy(QQmlObjectListModel<Item> *model, QObject *parent)
    : QObject(parent),
      model_(model)
{
}

void MyProxy::test()
{
    static int action = 0;

    switch(action)
    {
    case 0:
        // add a new item
        model_->append(new Item(QStringLiteral("Item %1").arg(model_->count() + 1), {}));
        break;
    case 1:
        // add a tag to an item
        model_->at(model_->count() - 1)->tags()->append(new Tag("Foo", "gray"));
        model_->at(model_->count() - 1)->tags()->append(new Tag("Bar", "navy"));
        break;
    case 2:
        // remove a tag
        model_->at(model_->count() - 1)->tags()->remove(0);
        break;
    case 3:
        // remove an item
        model_->remove(model_->count() - 1);
        break;
    }

    action = (action + 1) % 4;
}
