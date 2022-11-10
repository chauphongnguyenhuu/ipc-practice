#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "employeelistmodel.h"

#define PACKAGE_URI "Lge.Avn"
#define MAJOR_VERSION 1
#define MINOR_VERSION 0

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qmlRegisterType<EmployeeListModel>(PACKAGE_URI, MAJOR_VERSION, MINOR_VERSION, "EmployeeListModel");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
