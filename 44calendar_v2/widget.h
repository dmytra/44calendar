#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QTextCharFormat>
#include <QLabel>
#include <QGraphicsDropShadowEffect>




QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QGridLayout;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QGridLayout *previewLayout;
    QCalendarWidget *calendar;
};
#endif // WIDGET_H
