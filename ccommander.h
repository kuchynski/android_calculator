#ifndef CCOMMANDER_H
#define CCOMMANDER_H

#include <QtGui>
#include <QIcon>
#include "CAllWindows.h"
#include "ccalc.h"
#include "cmemory.h"
#include "cnotebook.h"

class CCommander : public CAllWindows
{
public:
    explicit CCommander(QWidget *parent = 0);
private:
    CCalc calc;
    CMemory memory;
    CNotebook notebook;
    QWidget tmp_widget;

private slots:
    void OnPressButton(unsigned n);
};

#endif // CCOMMANDER_H
