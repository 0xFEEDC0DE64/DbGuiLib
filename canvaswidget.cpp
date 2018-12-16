#include "canvaswidget.h"

// Qt includes
#include <QPainter>

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent)
{
}

void CanvasWidget::setImage(const QImage &image)
{
    m_image = image;
    repaint();
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    const double scale = std::min(double(width()) / m_image.width(),
                                  double(height()) / m_image.height());

    const QRect imageRect(QPoint(), m_image.size() * scale);

    QPainter painter;
    painter.begin(this);
    painter.drawImage(imageRect, m_image);
    painter.end();
}
