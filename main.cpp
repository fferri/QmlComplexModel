#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QAbstractItemModel>

#include "QQmlObjectListModel.h"
#include "item.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<Tag>("ComplexModel", 1, 0, "Tag", "Model from C++");
    qmlRegisterUncreatableType<Item>("ComplexModel", 1, 0, "Item", "Model from C++");

    QQmlApplicationEngine engine;

    QQmlObjectListModel<Item> items;

    //QList<Item*> items;
    for(int i = 0; i < 2; i++)
        items.append(new Item);
    items.at(0)->setName("Item 1");
    QList<Tag*> tags1;
    for(int i = 0; i < 3; i++)
        tags1.append(new Tag);
    tags1[0]->setTagName("Tag 1");
    tags1[0]->setTagColor("red");
    tags1[1]->setTagName("Tag 2");
    tags1[1]->setTagColor("green");
    tags1[2]->setTagName("Tag 3");
    tags1[2]->setTagColor("blue");
    items.at(0)->setTags(tags1);
    items.at(1)->setName("Item 2");
    QList<Tag*> tags2;
    for(int i = 0; i < 2; i++)
        tags2.append(new Tag);
    tags2[0]->setTagName("Tag 4");
    tags2[0]->setTagColor("red");
    tags2[1]->setTagName("Tag 5");
    tags2[1]->setTagColor("blue");
    items.at(1)->setTags(tags2);

    engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(&items));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
