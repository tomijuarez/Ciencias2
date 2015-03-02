#include <QQmlApplicationEngine>
#include <QDebug>
#include <QObject>
#include <QGuiApplication>
#include <QQuickView>
#include "classes/receiver.h"
#include <QQuickItem>
#include <QQmlContext>




int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Receiver receiver;
    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("eventsManager", &receiver);
    engine.load(QUrl(QStringLiteral("qrc:./main.qml")));
    return app.exec();
}
