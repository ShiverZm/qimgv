#pragma once

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include "settings.h"
#include "utils/imagelib.h"

class IconWidget : public QWidget
{
public:
    explicit IconWidget(QWidget *parent = nullptr);
    ~IconWidget();
    void setIconPath(QString path);

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool hiResPixmap;
    QPixmap *pixmap;
    qreal dpr, pixmapDrawScale;
};
