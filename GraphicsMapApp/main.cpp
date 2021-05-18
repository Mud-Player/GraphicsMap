#include <graphicsmap.h>
#include <QApplication>
#include <QOpenGLWidget>
#include <QGraphicsEllipseItem>
#include "mappolygonitem.h"
#include "mapellipseitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSurfaceFormat fmt;
    fmt.setSamples(16);
    QSurfaceFormat::setDefaultFormat(fmt);
    auto scene = new QGraphicsScene;
    MudMap map(scene);
    map.setYInverted(true);
    map.setZoomLevel(10);
    map.centerOn({40.4015, 99.7895});
    map.setTilePath("C:/Users/Yshin/Downloads/Arcgis");
    map.setDragMode(QGraphicsView::ScrollHandDrag);
    map.setRenderHint(QPainter::HighQualityAntialiasing, true);
    map.setOptimizationFlags(QGraphicsView::DontSavePainterState);
    map.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    map.setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    map.setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    map.setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    map.setViewport(new QOpenGLWidget);
    map.show();
    //
    MapPolygonItem *item = new MapPolygonItem;
    scene->addItem(item);
    QGeoCoordinate coord0(40.4014, 99.7895);
    QGeoCoordinate coord1 = coord0.atDistanceAndAzimuth(1e4, 90);
    QGeoCoordinate coord2 = coord1.atDistanceAndAzimuth(1e4, 180);
    QGeoCoordinate coord3 = coord0.atDistanceAndAzimuth(1e4, 180);
    QList<QGeoCoordinate> coords;
    coords.append(coord0);
    coords.append(coord1);
    coords.append(coord2);
    coords.append(coord3);
    item->setCoordinates(coords);
    item->setBrush(QBrush(Qt::red));
//    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    item->setEditable(true);
    //
    MapEllipseItem *ellipse = new MapEllipseItem;
    scene->addItem(ellipse);
    ellipse->setCenter({40.4014, 99.7895});
    ellipse->setSize({5e4, 2e4});

    return a.exec();
}
