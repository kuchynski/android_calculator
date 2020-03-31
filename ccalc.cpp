#include "ccalc.h"

CCalc::CCalc(QWidget *parent) : QWidget(parent), label_data(this), ss(1),
    buttons_ss(this), buttons_03(this), buttons_47(this), buttons_8B(this), buttons_CF(this), buttons_operates(this), znach(0)
{
    box_layout = new QBoxLayout(QBoxLayout::TopToBottom);
    //box_layout->setMargin(0);
    //box_layout->setSpacing(0);

    buttons_ss.AddButton(CButtons::SButton("bin"));
    buttons_ss.AddButton(CButtons::SButton("dec"));
    buttons_ss.AddButton(CButtons::SButton("hex"));
    buttons_ss.AddButton(CButtons::SButton("<"));
    QObject::connect(&buttons_ss, SIGNAL(PressButton(unsigned, bool)), this, SLOT(SetSS(unsigned, bool)));
    QObject::connect(&buttons_ss, SIGNAL(IAmReSize()), this, SLOT(ReSizeButtonSS()));
    QObject::connect(&buttons_03, SIGNAL(PressButton(unsigned, bool)), this, SLOT(Buttons03Click(unsigned, bool)));
    QObject::connect(&buttons_03, SIGNAL(IAmReSize()), this, SLOT(ReSizeButton03()));
    QObject::connect(&buttons_47, SIGNAL(PressButton(unsigned, bool)), this, SLOT(Buttons47Click(unsigned, bool)));
    QObject::connect(&buttons_47, SIGNAL(IAmReSize()), this, SLOT(ReSizeButton47()));
    QObject::connect(&buttons_8B, SIGNAL(PressButton(unsigned, bool)), this, SLOT(Buttons8BClick(unsigned, bool)));
    QObject::connect(&buttons_8B, SIGNAL(IAmReSize()), this, SLOT(ReSizeButton8B()));
    QObject::connect(&buttons_CF, SIGNAL(PressButton(unsigned, bool)), this, SLOT(ButtonsCFClick(unsigned, bool)));
    QObject::connect(&buttons_CF, SIGNAL(IAmReSize()), this, SLOT(ReSizeButtonCF()));
    buttons_operates.AddButton(CButtons::SButton("-"));
    buttons_operates.AddButton(CButtons::SButton("+"));
    buttons_operates.AddButton(CButtons::SButton("/"));
    buttons_operates.AddButton(CButtons::SButton("*"));
    buttons_operates.AddButton(CButtons::SButton("="));
    QObject::connect(&buttons_operates, SIGNAL(PressButton(unsigned, bool)), this, SLOT(ButtonsOperatesClick(unsigned, bool)));
    QObject::connect(&buttons_operates, SIGNAL(IAmReSize()), this, SLOT(ReSizeButtonOperates()));

    CInputCalculateData::SLabelInit struct_label;
    struct_label.color_backgraund = QColor(100, 100, 255, 255);
    struct_label.color_text = QColor(255, 255, 255, 255);
    struct_label.color_line = QColor(255, 255, 255, 155);
    QFont font2;
    font2.setPointSize(height() / 1);
    font2.setBold(true);
    font2.setWeight(75);
    struct_label.font = font2;
    label_data.SetInitStruct(struct_label);

    box_layout->addWidget(&label_data);
    box_layout->addWidget(&buttons_ss);
    box_layout->addWidget(&buttons_operates);
    box_layout->addWidget(&buttons_03);
    box_layout->addWidget(&buttons_47);
    box_layout->addWidget(&buttons_8B);
    box_layout->addWidget(&buttons_CF);

    QWidget::setLayout(box_layout);
    ButtonsOperatesClick(1);
    buttons_operates.SetChecked(1);
}
void CCalc::SetSize()
{
    QPalette palette7;
    QBrush brush7(QColor(200, 200, 200, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette7.setBrush(QPalette::Active, QPalette::WindowText, brush7);
    palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
    palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
    QFont font2;
    font2.setPointSize(height()/10);
    font2.setBold(true);


    //label_result.setPalette(palette7);
    //label_result.setFont(font2);
    //label_result.setText(QString::number(znach));
    label_data.setMaximumHeight(height()/8);
    label_data.setMinimumHeight(height()/8);
    //buttons_ss.setMaximumHeight(height()/10);
    //buttons_ss.setMinimumHeight(height()/10);
    //buttons_operates.setMaximumHeight(height()/10);
    //buttons_operates.setMinimumHeight(height()/10);

    CButtons::SButtonsInit but_init;// = buttons_ss.GetInitStruct();
    but_init.direction = CButtons::SButtonsInit::edHorizontal;
    but_init.font = this->font();
    but_init.font.setPixelSize(height()/10);
    but_init.color_backgraund = QColor(0, 30, 185, 255);
    but_init.color_backgraund_checked = QColor(100, 100, 255, 255);
    but_init.color_text = QColor(255, 255, 255, 155);
    but_init.color_text_checked = Qt::white;
    buttons_ss.SetInitStruct(but_init);
    buttons_operates.SetInitStruct(but_init);

    but_init.color_text_checked = Qt::yellow;
    buttons_03.SetInitStruct(but_init);
    buttons_47.SetInitStruct(but_init);
    buttons_8B.SetInitStruct(but_init);
    buttons_CF.SetInitStruct(but_init);
   // buttons->setMaximumHeight(init_struct.frame_height);
}
void CCalc::SetSS(unsigned n, bool state)
{
    if(n == 3)
    {
        label_data.OnPressKey(-104);
        buttons_ss.SetChecked(ss);
    }
    if(n > 2)
        return;
    buttons_ss.SetChecked(ss = n);
    buttons_47.setVisible(ss > 0);
    buttons_8B.setVisible(ss > 0);
    buttons_CF.setVisible(ss > 1);
    buttons_03.SetImageBack(image_my, buttons_03.geometry()); buttons_03.Paint();
    buttons_47.SetImageBack(image_my, buttons_47.geometry()); buttons_47.Paint();
    buttons_8B.SetImageBack(image_my, buttons_8B.geometry()); buttons_8B.Paint();
    buttons_CF.SetImageBack(image_my, buttons_CF.geometry()); buttons_CF.Paint();
    buttons_operates.SetImageBack(image_my, buttons_operates.geometry()); buttons_operates.Paint();

    buttons_03.SubButton();
    buttons_03.AddButton(CButtons::SButton("0"));
    buttons_03.AddButton(CButtons::SButton("1"));
    if(ss > 0)
    {
        buttons_03.AddButton(CButtons::SButton("2"));
        buttons_03.AddButton(CButtons::SButton("3"));
    }
    buttons_47.SubButton();
    if(ss > 0)
    {
        buttons_47.AddButton(CButtons::SButton("4"));
        buttons_47.AddButton(CButtons::SButton("5"));
        buttons_47.AddButton(CButtons::SButton("6"));
        buttons_47.AddButton(CButtons::SButton("7"));
    }
    buttons_8B.SubButton();
    if(ss > 0)
    {
        buttons_8B.AddButton(CButtons::SButton("8"));
        buttons_8B.AddButton(CButtons::SButton("9"));
    }
    if(ss > 1)
    {
        buttons_8B.AddButton(CButtons::SButton("A"));
        buttons_8B.AddButton(CButtons::SButton("B"));
    }
    else
        buttons_8B.AddButton(CButtons::SButton("-/+"));
    buttons_CF.SubButton();
    if(ss > 1)
    {
        buttons_CF.AddButton(CButtons::SButton("C"));
        buttons_CF.AddButton(CButtons::SButton("D"));
        buttons_CF.AddButton(CButtons::SButton("E"));
        buttons_CF.AddButton(CButtons::SButton("F"));
    }
    label_data.SetSS(ss);
}
void CCalc::Buttons03Click(unsigned n, bool state)
{
   label_data.OnPressKey(n);
}
void CCalc::Buttons47Click(unsigned n, bool state)
{
    label_data.OnPressKey(n + 4);
}
void CCalc::Buttons8BClick(unsigned n, bool state)
{
    if( (buttons_8B.GetSize() == 3) && (n == 2) )
        label_data.OnPressKey(-102);
    else
        label_data.OnPressKey(n + 8);
}
void CCalc::ButtonsCFClick(unsigned n, bool state)
{
    label_data.OnPressKey(n + 12);
}
void CCalc::ButtonsOperatesClick(unsigned n, bool state)
{
    if(n == 4)
        buttons_operates.SetChecked(label_data.GetOperation()-1);
    label_data.OnPressKey(-(n+1));
}
//------------------------------------------------------------------------------------------------------------
void CCalc::ReSizeButtonSS()
{
    buttons_ss.SetImageBack(image_my, buttons_ss.geometry());
}
void CCalc::ReSizeButton03()
{
    buttons_03.SetImageBack(image_my, buttons_03.geometry());
}
void CCalc::ReSizeButton47()
{
    buttons_47.SetImageBack(image_my, buttons_47.geometry());
 }
void CCalc::ReSizeButton8B()
{
    buttons_8B.SetImageBack(image_my, buttons_8B.geometry());
}
void CCalc::ReSizeButtonCF()
{
    buttons_CF.SetImageBack(image_my, buttons_CF.geometry());
}
void CCalc::ReSizeButtonOperates()
{
    buttons_operates.SetImageBack(image_my, buttons_operates.geometry());
}
//---------------------------------------------
void CCalc::paintEvent(QPaintEvent *p)
{
    if(!QWidget::isVisible())
        return;
    painter.begin(this);
    painter.drawImage(p->rect(), image_my, p->rect());
    painter.end();
}
void CCalc::resizeEvent(QResizeEvent *r)
{
    SetSize();
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

    //label_about.setGeometry(QRect(0, height() - 40, width(), 20));

    SetSS(ss);
    buttons_ss.SetImageBack(image_my, buttons_ss.geometry());
    buttons_03.SetImageBack(image_my, buttons_03.geometry());
    buttons_47.SetImageBack(image_my, buttons_47.geometry());
    buttons_8B.SetImageBack(image_my, buttons_8B.geometry());
    buttons_CF.SetImageBack(image_my, buttons_CF.geometry());
    buttons_operates.SetImageBack(image_my, buttons_operates.geometry());
    label_data.SetImageBack(image_my, label_data.geometry());
}
