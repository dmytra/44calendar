#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(0000, 1, 1));
    calendar->setMaximumDate(QDate(5000, 1, 1));
    calendar->setGridVisible(true);
    calendar->verticalHeaderFormat();

    QLocale ukr(QLocale::Ukrainian, QLocale::Ukraine);
    calendar->setLocale(ukr);

    QDate dateNew44 ( QDate::currentDate());
    int corrDay = dateNew44.day();

    dateNew44.setDate(calendar->yearShown()-1979, calendar->monthShown(), corrDay);
    calendar->setSelectedDate(dateNew44);

///////////////////// from   reformatCalendarPage
    QTextCharFormat mayFirstFormat;
    const QDate mayFirst(calendar->yearShown(), 5, 1);

    QTextCharFormat firstFridayFormat;
    QDate firstFriday(calendar->yearShown(), calendar->monthShown(), 1);

    calendar->setFirstDayOfWeek(Qt::Friday);
        // or corrent first day of week
        // Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(firstFriday.dayOfWeek()));
        // firstFridayFormat.setForeground(calendar->weekdayTextFormat(dayOfWeek).foreground());

    calendar->setDateTextFormat(firstFriday, firstFridayFormat);

//////////////


    QGridLayout *layout = new QGridLayout;
//
    QLabel *labelYaer = new QLabel();
    labelYaer->setText(QString::number(calendar->yearShown()));
    labelYaer->setAlignment(  Qt::AlignCenter | Qt::AlignTop);
      QFont serifFont("Time", 108, QFont::Bold);
    //  QFont serifFont("Helvetica [Cronyx]", 222, QFont::Black);
    //QFont serifFont("Helvetica [Cronyx]", 188, QFont::Thin);
        labelYaer->setFont(serifFont);
        labelYaer->setStyleSheet("QLabel { color : blue; }"); //labelYaer->setStyleSheet("QLabel { background-color : #a5cdff; color : white; }");

        QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
        effect->setColor(Qt::white);
        effect->setBlurRadius(18);
        effect->setXOffset(8);
        effect->setYOffset(8);
        labelYaer->setGraphicsEffect(effect);
//
    QLabel *labelYaerDown = new QLabel("рік");
    labelYaerDown->setAlignment(  Qt::AlignCenter | Qt::AlignTop);
    QFont serifFontDown("Helvetica [Cronyx]", 44, QFont::Thin);
    labelYaerDown->setFont(serifFontDown);
//
    QLabel *labelYaerDown2 = new QLabel("нового літочислення \n");
    labelYaerDown2->setAlignment(  Qt::AlignCenter | Qt::AlignTop);
    QFont serifFontDown2("Helvetica [Cronyx]", 24, QFont::Thin);
    labelYaerDown->setFont(serifFontDown2);

    layout->addWidget(labelYaer, 0, 0);
    layout->addWidget(labelYaerDown, 1, 0);
    layout->addWidget(labelYaerDown2, 2, 0);
    layout->addWidget(calendar, 3, 0);
    //layout->setSizeConstraint(QLayout::SetMaximumSize); //  layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

Widget::~Widget()
{
}

