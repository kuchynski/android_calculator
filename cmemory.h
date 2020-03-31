#ifndef CMEMORY_H
#define CMEMORY_H

#include <QWidget>
#include <QtGui>
#include "clabelchange.h"

class CMemory : public QWidget
{
    Q_OBJECT
private:
    QPainter painter;
    QImage image_my;

    CLabelChange label_change;

public:
    explicit CMemory(QWidget *parent = 0);

    void paintEvent(QPaintEvent *p);
    void resizeEvent(QResizeEvent *r);
signals:

public slots:

};

#endif // CMEMORY_H
