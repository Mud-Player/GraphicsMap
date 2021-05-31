#include <QApplication>
#include <QOpenGLWidget>
#include <QGraphicsEllipseItem>
#include <interactivemap.h>
#include <mappolygonitem.h>
#include <mapellipseitem.h>
#include <maptrailitem.h>
#include <mapobjectitem.h>
#include <maprouteitem.h>
#include "mapwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSurfaceFormat fmt;
    fmt.setSamples(16);
    QSurfaceFormat::setDefaultFormat(fmt);

    //
    MapWidget w;
    w.show();

    return a.exec();
}
