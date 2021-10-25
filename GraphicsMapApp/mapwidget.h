#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <interactivemap.h>
#include <mapoperator.h>

class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = nullptr);

private:
    InteractiveMap *m_map;
    MapObjectOperator m_objOperator;
    MapEllipseOperator m_ellipseOperator;
    MapPolygonOperator m_polygonOperator;
    MapRouteOperator m_routeOperator;
};

#endif // MAPWIDGET_H
