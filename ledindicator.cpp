#include "ledindicator.h"

#include <QPainter>

LedIndicator::LedIndicator(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(16, 16);
}

void LedIndicator::setColor(const QColor &color)
{
    m_color = color;
    repaint();
}

void LedIndicator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QRect ellipseRect;

    if(width() < height())
        ellipseRect = QRect(0, height() / 2 - width() / 2, width(), width());
    else if(width() > height())
        ellipseRect = QRect(width() / 2 - height() / 2, 0, height(), height());
    else
        ellipseRect = rect();

    ellipseRect.setWidth(ellipseRect.width() - 1);
    ellipseRect.setHeight(ellipseRect.height() - 1);

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(m_color);
    painter.drawEllipse(ellipseRect);
}
