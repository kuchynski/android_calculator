#ifndef CAllWindows_H
#define CAllWindows_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>
#include <QtGui>
#include <QMenuBar>
#include <QMenu>
#include "cbuttonscheck.h"


class CAllWindows : public QWidget
{
    Q_OBJECT
public:
    struct SAllWindowsInit
    {
        enum eDirection {edVertical, edHorizontal};

        eDirection direction_frame;
        eDirection direction_widget;
        unsigned rewindow_time_all;
        unsigned rewindow_kol_step;
        unsigned frame_height;
        unsigned frame_width;
        SAllWindowsInit(): rewindow_time_all(700), rewindow_kol_step(10), frame_height(30), frame_width(30),
                           direction_frame(edHorizontal), direction_widget(edHorizontal) {}
    };

    explicit CAllWindows(QWidget *parent = 0);

    void SetInitStruct(const SAllWindowsInit &set_struct);
    void AddWidget(QWidget *w, QString name);
    void AddWidget(QWidget *w, QString name, QPixmap &pix);
    void RePlaceWidget(unsigned n, QWidget *w, QString name, QPixmap &pix);
    void paintEvent(QPaintEvent *p);
    void resizeEvent(QResizeEvent *r);
protected:
    QMenu *menu;
private:

    QMenuBar menu_bar;
    QAction *action_menu;
    QBoxLayout *box_layout;
    QList<QWidget*> list_windows;
    QWidget *main_widget;
    CButtonsCheck *buttons;
    SAllWindowsInit init_struct;
    unsigned tek, new_tek;
    int mouse_press_x, mouse_press_y;
    bool mouse_press;

    int timer_id, timer_st;

    void SetWidget(const unsigned &n);
    void timerEvent(QTimerEvent *event);

    void ChoiceStart();
    void ChoiceEnd();

protected:
    virtual void mousePressEvent(QMouseEvent *pe);
    virtual void mouseMoveEvent(QMouseEvent *pe);
    virtual void mouseReleaseEvent(QMouseEvent *pe);

signals:
    void NewWindow(unsigned n);
    void IAmReSize();
    void DragImageTare(int s);
    void CompressXImageTare(int s);
    void CompressYImageTare(int s);

private slots:
    void OnButtonsClick(unsigned n, bool s = true);
    void OnChangeCalculate();
    void OnChangeNotepad();
    void OnChangeAbout();
    void OnChangeExit();

public slots:
    virtual void OnPressButton(unsigned n){}
//    virtual void IAmReSizeFromTare(){}
//    virtual void DragImageFromTare(int s){}
//    virtual void CompressXImageFromTare(int s){}
//    virtual void CompressYImageFromTare(int s){}
};

#endif // CAllWindows_H
