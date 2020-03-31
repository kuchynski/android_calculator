#include "ccommander.h"

CCommander::CCommander(QWidget *parent): CAllWindows(parent), calc(this), memory(this), tmp_widget(this), notebook(this)
{
    QObject::connect(this, SIGNAL(NewWindow(unsigned)), this, SLOT(OnPressButton(unsigned)));
    SAllWindowsInit init_struct;
    init_struct.direction_frame = SAllWindowsInit::edHorizontal;
    init_struct.direction_widget = SAllWindowsInit::edHorizontal;
    init_struct.rewindow_time_all = 500;
    init_struct.rewindow_kol_step = 12;
    init_struct.frame_height = 50;
    init_struct.frame_width = 0;
    SetInitStruct(init_struct);

    //    QObject::connect(&input, SIGNAL(NewSostav()), this, SLOT(OnNewSostav()));
    //QPixmap pix0("0.bmp");
    AddWidget(&calc, QString::fromLocal8Bit("calculator"));
    AddWidget(&notebook, QString::fromLocal8Bit("notepad"));
    AddWidget(&memory, QString::fromLocal8Bit("about"));
    AddWidget(&tmp_widget, QString::fromLocal8Bit("exit"));



    CAllWindows::menu->addAction(QIcon("/Android/data/1.jpg"), "calculator", this, SLOT(OnChangeCalculate()));
    CAllWindows::menu->addAction(QIcon("/Android/data/2.jpg"), "notepad", this, SLOT(OnChangeNotepad()));
    CAllWindows::menu->addAction(QIcon(), "about", this, SLOT(OnChangeAbout()));
    CAllWindows::menu->addAction(QIcon("/Android/data/4.jpg"), "exit", this, SLOT(OnChangeExit()));


}

void CCommander::OnPressButton(const unsigned n)
{
    if(n == 3)
        exit(0);
}
