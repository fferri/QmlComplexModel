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
    QList<Tag*> tags1;
    tags1.append(new Tag("Tag 1", "red"));
    tags1.append(new Tag("Tag 2", "green"));
    tags1.append(new Tag("Tag 3", "blue"));
    items.append(new Item("Item 1", tags1));
    QList<Tag*> tags2;
    tags2.append(new Tag("Tag 4", "yellow"));
    tags2.append(new Tag("Tag 5", "magenta"));
    items.append(new Item("Item 2", tags2));

    engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(&items));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
