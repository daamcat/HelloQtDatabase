#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QMainWindow>
#include <QApplication>
#include <QTableView>


#include <QString>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>

#include "backend.h"

#include "mysqltablemodel.h"


int exec_qml(int argc, char *argv[]);
int exec_mainWindow(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    return exec_qml(argc,argv);
    //return exec_mainWindow(argc,argv);
}

int exec_mainWindow(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w.setWindowTitle("Database in QMainWindow");

    QTableView tableView(w.centralWidget());
    w.setCentralWidget(&tableView);

    DatabaseManager manager;
    tableView.setModel(manager.getTableModel());
    tableView.show();

    w.show();
    return a.exec();

}

int exec_qml(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<BackEnd>("com.mycompany.mycomponent",1,0,"BackEnd");
    // C++ class name: BackEnd
    // Version (major): 1
    // Version (minor): 0
    // Imported library???: com.mycompany.mycomponent

    DatabaseManager manager;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MySqlTableModel", manager.getTableModel());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject *obj, const QUrl &objUrl)
                        {
                            if (!obj && url == objUrl)
                            {
                                QCoreApplication::exit(-1);
                            }
                        },
                      Qt::QueuedConnection);
    engine.load(url);




    return app.exec();
}
