#include "cinputcalculatedata.h"

CInputCalculateData::CInputCalculateData(QWidget *parent) : QWidget(parent), style_back(esColor),
    image(width(), height(), QImage::Format_RGB32),
    ss(1), active_data(1), operation(0), timer_id(0)
{
    data[0] = 0;
    data[1] = 0;
}
void CInputCalculateData::OnPressKey(long int ch)
{
    long long tmp_ss = (ss == 0)? 2 : (ss == 1)? 10 : 16;
    if(ch >= 0)
    {
        long long new_data = data[active_data] * tmp_ss;
        long long new_data2 = new_data / tmp_ss;
        if(data[active_data] == new_data2)
        {
            if( (data[active_data] < 0) && (ss == 1) )
                new_data -= ch;
            else
                new_data += ch;
            data[active_data] = new_data;
        }
        Paint();
    }
    else if(ch == -100)//clear
    {
        data[active_data] = 0;
        Paint();
    }
    else if(ch == -104)// <-
    {
        data[active_data] /= tmp_ss;
        Paint();
    }
    else if(ch == -102)// -
    {
        data[active_data] = -data[active_data];
        Paint();
    }
    else if(ch == -5)// =
    {
        long long res = data[0];
        bool ok = true;
        switch(operation)
        {
            case 1: res -= data[1]; break;
            case 2: res += data[1]; break;
            case 3: if(data[1])
                        res /= data[1];
                    else
                        ok = false;
                    break;
            case 4: res *= data[1]; break;
        }
        if(ok)
        {
            active_data = 0;//(active_data)? 0 : 1;
            data[0] = res;
            StartTimer();
            //Resize();
        }
    }
    else if(ch > -5)
    {
        if(active_data)
        {
            data[0] = data[1];
        }
        //else
            active_data = 1;
        //if(operation == -ch)
            data[1] = 0;
        operation = -ch;
        StartTimer();
        //Resize();
    }
}
void CInputCalculateData::StartTimer()
{
    ptr_timer = 0;

    if(!timer_id)
        timer_id = QObject::startTimer(20);
}
void CInputCalculateData::timerEvent(QTimerEvent *event)
{
    ptr_timer ++;
    if(ptr_timer >= 10)
    {
        ptr_timer = 10;
        killTimer(timer_id);
        timer_id = 0;
    }
    Resize();
}
void CInputCalculateData::Resize()
{
    const int tmp = (width() / 5);
    const int size_lage = tmp + 3 * tmp * ptr_timer / 10;
    const int size_small = width() - size_lage;
    const int size_x[2] = {(active_data)? size_small : size_lage, (!active_data)? size_small : size_lage};
    const int begin_x[2] = {0, size_x[0]};
    rect_pos[0] = QRect(begin_x[0], 0, size_x[0], height());
    rect_pos[1] = QRect(begin_x[1], 0, size_x[1], height());
    Paint();
}
void CInputCalculateData::Paint()
{
    QPainter painter(&image);
    QRect rect_all = image.rect();
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawImage(rect_all, image_back, image_back.rect());
    painter.setBrush(init_struct.color_backgraund);
    painter.setPen(QPen(init_struct.color_text));

    const unsigned tmp_ss = (ss == 0)? 2 : (ss == 1)? 10 : 16;
    QString str[2];
    for(unsigned i = 0; i < 2; i ++)
    {
        const QString str0 = QString::number(data[i], tmp_ss);
        const unsigned size = str0.size();
        const unsigned size_ss = (ss == 1)? 3 : 4;
        for(unsigned i0 = 0; i0 < size; i0 ++)
        {
            if( !((size - i0) % size_ss) && i0)
                str[i] += " ";
            str[i] += str0[i0];
        }
        //str[i] = str[i].toUpper();
    }

    if(!active_data)
        painter.drawRect(rect_pos[0]);
    init_struct.font.setPointSize( GetSizeFont(0, str[0].size()) );
    painter.setFont(init_struct.font);
    painter.drawText(rect_pos[0], Qt::AlignVCenter | Qt::AlignLeft, str[0]);

    if(active_data)
        painter.drawRect(rect_pos[1]);
    init_struct.font.setPointSize( GetSizeFont(1, str[1].size()) );
    painter.setFont(init_struct.font);
    painter.drawText(rect_pos[1], Qt::AlignVCenter | Qt::AlignRight, str[1]);


    painter.end();
    update();
}
int CInputCalculateData::GetSizeFont(int n, int size_text)
{
    int tmpp1 = rect_pos[n].height() * 8 / 10;
    int tmpp2 = rect_pos[n].width() * 15 / 12;
    if(!size_text)
        return tmpp1;
    return (tmpp1 < (tmpp2 / size_text))? tmpp1 : tmpp2 / size_text;
}
void CInputCalculateData::paintEvent(QPaintEvent *p)
{
    if(!QWidget::isVisible())
        return;
    QPainter painter(this);
    painter.drawImage(rect(), image, image.rect());
    painter.end();
}
void CInputCalculateData::resizeEvent(QResizeEvent *r)
{
    image = QImage(width(), height(), QImage::Format_RGB32);
    emit IAmReSize();
    Resize();
}
void CInputCalculateData::SetImageBack(const QImage &ib, const QRect r)
{
    image_back = QImage(width(), height(), QImage::Format_RGB32);
    QPainter painter(&image_back);
    painter.drawImage(rect(), ib, r);
    painter.end();
    style_back = esImage;
    Paint();
}
void CInputCalculateData::mouseReleaseEvent(QMouseEvent *pe)
{
    const int coordinate = pe->x();
    const int tmp_uk1 = (active_data)? 0 : 1;
    const int tmp_uk2 = (!active_data)? 0 : 1;
    //if( (coordinate >= rect_pos[1].x()) && (coordinate < (rect_pos[1].x() + rect_pos[1].width())) )
    //    OnPressKey(-101);
    //else
    if( (coordinate >= rect_pos[tmp_uk1].x()) && (coordinate < (rect_pos[tmp_uk1].x() + rect_pos[tmp_uk1].width())) )
    {
        active_data = (active_data)? 0 : 1;
        StartTimer();
        //Resize();
    }
    else if( (coordinate >= rect_pos[tmp_uk2].x()) && (coordinate < (rect_pos[tmp_uk2].x() + rect_pos[tmp_uk2].width())) )
        OnPressKey(-100);
}
void CInputCalculateData::SetSS(unsigned char new_ss)
{
    ss = new_ss;
    Paint();
}
