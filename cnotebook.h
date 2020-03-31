#ifndef CNOTEBOOK_H
#define CNOTEBOOK_H

#include <QWidget>
#include <QtGui>
#include <QtWidgets/QLabel>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets>

class CNotebook : public QWidget
{
    Q_OBJECT
private:
    QPainter painter;
    QImage image_my;
    QBoxLayout *box_layout;
    QTextEdit edit;

public:
    explicit CNotebook(QWidget *parent = 0);

    void paintEvent(QPaintEvent *p);
    void resizeEvent(QResizeEvent *r);
signals:

public slots:

};
#endif // CNOTEBOOK_H
