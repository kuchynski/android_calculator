#include "cmemory.h"

CMemory::CMemory(QWidget *parent) : QWidget(parent), label_change(this)
{
    label_change.AddString(QString::fromLocal8Bit("calculator"));
    label_change.AddString(QString::fromLocal8Bit("ver. 1.0"));
    label_change.AddString("kuchynski@tut.by");
    label_change.AddString("+375 297746768");
    label_change.Start();
}
//---------------------------------------------
void CMemory::paintEvent(QPaintEvent *p)
{
    if(!QWidget::isVisible())
        return;
    painter.begin(this);
    painter.drawImage(p->rect(), image_my, p->rect());
    painter.end();
}
void CMemory::resizeEvent(QResizeEvent *r)
{
    image_my = QImage(width(), height(), QImage::Format_RGB32);
    painter.begin(&image_my);
    QLinearGradient gradient(0, 0, width(), width());//height());
    QRect rect1(0, 0, width(), height());
    painter.setBrush(Qt::gray);
    painter.drawRect(rect1);
    QColor cg = QColor(0, 30, 185, 255);
    int stap_gr[8] = {255, 120, 140, 200, 230, 180, 200, 240};
    for(int i = 0; i < 8; i ++)
    {
        cg.setAlpha(stap_gr[i]);
        gradient.setColorAt((double)i / 7.0, cg);
    }
    painter.setPen(QPen(cg));
    painter.setBrush(gradient);
    painter.drawRect(rect1);
    painter.setPen(QPen(Qt::white));
    painter.setBrush(Qt::NoBrush);
    //painter.drawRoundedRect(QRect(510, 150, 250, 300), 5, 5);
    painter.end();

    CLabelChange::SLabelInit struct_label;
    struct_label.color_text = QColor(255, 255, 255, 255);
    QFont font2;
    font2.setPointSize(height() / 30);
    font2.setBold(true);
    font2.setWeight(75);
    struct_label.font = font2;
    label_change.SetInitStruct(struct_label);
    label_change.setGeometry(QRect(0, height() / 2 - height() / 30, width(), height() / 15));
    label_change.SetImageBack(image_my, label_change.geometry());
}
