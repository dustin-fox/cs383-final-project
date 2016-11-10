#ifndef ANIMATIONVIEW_H
#define ANIMATIONVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QPointF>
#include <QDebug>
#include "global.h"

//http://stackoverflow.com/questions/7830054/how-to-draw-a-point-on-mouseclick-on-a-qgraphicsscene

class AnimationView : public QGraphicsView
{
    Q_OBJECT
public:
    static const int MOVE = 3;
    static const int DRAW = 1;
    static const int ERASE = 0;
    explicit AnimationView(QWidget *parent = 0);

signals:

public slots:
    void setTool(int);

private slots:
    void drawBackground(QPainter *painter, const QRectF &rect);
    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent();
    void mouseDoubleClickEvent(QMouseEvent * e);
    void mouseMoveEvent(QMouseEvent * e);
    qreal roundToGrid(qreal x);
    int drawPixel(QMouseEvent * e);
    int erasePixel(QMouseEvent * e);
    int move(QMouseEvent * e);

private:
    int tool;
    bool mouseClicked;
    QGraphicsScene * scene;
};

#endif // ANIMATIONVIEW_H
