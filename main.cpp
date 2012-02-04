#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeEngine>
#include <QtDeclarative>
#include <QDir>
#include <QString>
#include <QDebug>
#include "qmlclipboardadapter.h"
#include "keyssortfilterproxymodel.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDeclarativeEngine engine;
    //Set Database Path
    QString customPath = "c:\\data\\.config\\chabhi";
    QDir dir;
    if(dir.mkpath(QString(customPath))){
        qDebug() << "Default path >> "+engine.offlineStoragePath();
        engine.setOfflineStoragePath(customPath);
        qDebug() << "New path >> "+engine.offlineStoragePath();
    }
    //Setup Cliboard Integration with QML
    qmlRegisterType<QmlClipboardAdapter>("keychain", 1, 0, "QClipboard");
    qmlRegisterType<KeysSortFilterProxyModel>("sortproxy",1,0,"QSortProxy");

    QAbstractItemModel *model;
    KeysSortFilterProxyModel *proxy = new KeysSortFilterProxyModel();
    proxy->setSourceModel(model);
    //Load QML
    QmlApplicationViewer viewer;
    QDeclarativeContext *context = viewer.rootContext();
    context->setContextProperty("itemListModel", model);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setMainQmlFile(QLatin1String("qml/Keychain/SplashScreen.qml"));
    viewer.engine()->setOfflineStoragePath(customPath);

    viewer.showExpanded();

    return app.exec();
}
