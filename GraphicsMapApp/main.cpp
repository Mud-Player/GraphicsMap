#include <QApplication>
#include <QOpenGLWidget>
#include <QGraphicsEllipseItem>
#include <interactivemap.h>
#include <mappolygonitem.h>
#include <mapellipseitem.h>
#include <maptrailitem.h>
#include <mapobjectitem.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSurfaceFormat fmt;
    fmt.setSamples(16);
    QSurfaceFormat::setDefaultFormat(fmt);
    auto scene = new QGraphicsScene;
    InteractiveMap map(scene);
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
    QVector<QGeoCoordinate> coords;
    coords.append(coord0);
    coords.append(coord1);
    coords.append(coord2);
    coords.append(coord3);
    item->setCoordinates(coords);
    item->setBrush(QBrush(Qt::red));
//    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    item->setEditable(true);
//    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setSelected(true);
    //
    MapEllipseItem *ellipse = new MapEllipseItem;
    ellipse->setEditable(false);
    scene->addItem(ellipse);
    ellipse->setRect(QGeoCoordinate(40.4014, 99.7895), QGeoCoordinate(40.3454, 99.23));
    ellipse->setSize({5e4, 2e4});
    ellipse->setBrush(QColor(255, 100, 100, 150));
    ellipse->setEditable(true);
//    ellipse->setFlag(QGraphicsItem::ItemIsSelectable);

    //
    MapTrailItem *trail = new MapTrailItem;
    scene->addItem(trail);
    trail->addCoordinate({40, 99});
    trail->addCoordinate({41, 99});
    trail->addCoordinate({41, 100});

    //
    QGraphicsEllipseItem *origin = new QGraphicsEllipseItem;
    origin->setBrush(Qt::white);
    origin->setRect(-2, -2, 4, 4);
    origin->setRect(-2, -2, 4, 4);
    origin->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    scene->addItem(origin);
    MapObjectItem *obj = new MapObjectItem;
    obj->setCoordinate({40,99});
    obj->setColor(Qt::red);
    scene->addItem(obj);

    map.setOperator(new MapPolygonOperator);

    return a.exec();
}
