#ifndef CCALC_H
#define CCALC_H

#include <QWidget>
#include <QtGui>
#include <QtWidgets/QLabel>
#include <QtWidgets/QBoxLayout>
#include "cbuttons.h"
#include "cbuttonscheck.h"
#include "cinputcalculatedata.h"

class CCalc : public QWidget
{
    Q_OBJECT
private:
    QPainter painter;
    QImage image_my;

    QBoxLayout *box_layout;
    CInputCalculateData label_data;
    CButtonsCheck buttons_ss;
    CButtons buttons_03, buttons_47, buttons_8B, buttons_CF;
    CButtonsCheck buttons_operates;
    unsigned char ss;
    unsigned znach;

    void SetSize();
public:
    explicit CCalc(QWidget *parent = 0);

    void paintEvent(QPaintEvent *p);
    void resizeEvent(QResizeEvent *r);
signals:

public slots:
    void SetSS(unsigned n, bool state = false);
    void Buttons03Click(unsigned n, bool state = false);
    void Buttons47Click(unsigned n, bool state = false);
    void Buttons8BClick(unsigned n, bool state = false);
    void ButtonsCFClick(unsigned n, bool state = false);
    void ButtonsOperatesClick(unsigned n, bool state = false);
    void ReSizeButtonSS();
    void ReSizeButton03();
    void ReSizeButton47();
    void ReSizeButton8B();
    void ReSizeButtonCF();
    void ReSizeButtonOperates();
};

#endif // CCALC_H
