#include "mapwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QOpenGLWidget>
#include <mappolygonitem.h>
#include <mapellipseitem.h>
#include <maptrailitem.h>
#include <mapobjectitem.h>
#include <maprouteitem.h>

MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    //
    QGraphicsScene *scene = new QGraphicsScene;
    m_map = new InteractiveMap(scene);
    m_map->setYInverted(true);
    m_map->setZoomLevel(10);
    m_map->centerOn({40, 99});
    m_map->setTilePath("E:/Arcgis");
    m_map->setDragMode(QGraphicsView::ScrollHandDrag);
    m_map->setRenderHint(QPainter::HighQualityAntialiasing, true);
    m_map->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    m_map->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    m_map->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    m_map->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    m_map->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    m_map->setViewport(new QOpenGLWidget);
    //
    QPushButton *obj = new QPushButton(u8"对象");
    QPushButton *polygon = new QPushButton(u8"多边形");
    QPushButton *ellipse = new QPushButton(u8"圆形");
    obj->setCheckable(true);
    polygon->setCheckable(true);
    ellipse->setCheckable(true);
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(obj);
    buttonGroup->addButton(polygon);
    buttonGroup->addButton(ellipse);

    //
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(obj);
    vLayout->addWidget(polygon);
    vLayout->addWidget(ellipse);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_map);
    layout->addLayout(vLayout);
    //
    connect(obj, &QPushButton::clicked, this, [&](){
        m_map->setOperator(&m_objOperator);
    });
    connect(polygon, &QPushButton::clicked, this, [&](){
        m_map->setOperator(&m_polygonOperator);
    });
    connect(ellipse, &QPushButton::clicked, this, [&](){
        m_map->setOperator(&m_ellipseOperator);
    });
}
