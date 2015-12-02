#ifndef BARGRAPH_H
#define BARGRAPH_H

#include <QWidget>
#include <QPaintEngine>
#include <QQuickItem>

typedef struct Bar
{
    qreal value;
    bool clipped;
    Bar() : value(0.0), clipped(false) {}
}Bar;

#if 1
#define BarGraphParent QWidget
#else
#define BarGraphParent QQuickItem
#endif

class BarGraph : public BarGraphParent
{
    Q_OBJECT
public:
    explicit BarGraph(BarGraphParent *parent = 0)
        : BarGraphParent(parent)
    {
    }
    void setNumBars(const int numBars);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void reset();
    void updateBars(const QVector<Bar> &Bars);
private:
    QVector<Bar> m_bars;
};

#endif // BARGRAPH_H
