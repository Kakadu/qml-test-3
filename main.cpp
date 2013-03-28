#include <QtGui/QGuiApplication>

#include "MainModel.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QtQml/QQmlContext>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MainModel *m = new MainModel();
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("mainModel", m);

    view.setSource(QUrl::fromLocalFile(QString("View.qml")));
    view.show();

    return app.exec();
}
