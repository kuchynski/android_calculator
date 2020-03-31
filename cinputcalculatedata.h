#ifndef CINPUTCALCULATEDATA_H
#define CINPUTCALCULATEDATA_H

#include <QWidget>
#include <QtGui>

class CInputCalculateData : public QWidget
{
    Q_OBJECT
public:
    struct SLabelInit
    {
        QFont font;
        QColor color_backgraund;
        QColor color_line;
        QColor color_text;
        SLabelInit() : color_line(Qt::white), color_backgraund(Qt::black), color_text(Qt::white) {}
    };
    explicit CInputCalculateData(QWidget *parent = 0);

    void SetInitStruct(const SLabelInit &set_struct) {init_struct = set_struct;}
    //void AddString(QString str) {strings << str;}
    void SetImageBack(const QImage &ib, const QRect r);
    void OnPressKey(long int ch);
    void SetSS(unsigned char new_ss);
    unsigned char GetOperation()const {return operation;}

    void paintEvent(QPaintEvent *p);
    void resizeEvent(QResizeEvent *r);
private:
    enum eStyleBack {esColor, esImage};
    eStyleBack style_back;
    SLabelInit init_struct;

    long long data[2];
    unsigned char active_data;
    unsigned char operation;
    unsigned char ss;
    int ptr_timer;
    QImage image, image_back;
    int timer_id;
    QRect rect_pos[2];

    void timerEvent(QTimerEvent *event);
    void StartTimer();
    int GetSizeFont(int n, int size_text);
    void Resize();
    void Paint();
protected:
    virtual void mouseReleaseEvent(QMouseEvent *pe);
signals:
    void IAmReSize();

public slots:

};

#endif // CINPUTCALCULATEDATA_H
