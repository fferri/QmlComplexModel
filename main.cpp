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
    items.append(new Item("Item 1", QList<Tag*>()
            << new Tag("Tag 1", "red")
            << new Tag("Tag 2", "green")
            << new Tag("Tag 3", "blue")));
    items.append(new Item("Item 2", QList<Tag*>()
            << new Tag("Tag 4", "yellow")
            << new Tag("Tag 5", "magenta")));

    engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(&items));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
