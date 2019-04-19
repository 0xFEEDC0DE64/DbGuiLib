#include "vector2dwidget.h"

#include <QHBoxLayout>
#include <QDoubleSpinBox>

Vector2DWidget::Vector2DWidget(QWidget *parent) :
    QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_doubleSpinBoxX = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxY = new QDoubleSpinBox(this));
    setLayout(layout);
}

QVector2D Vector2DWidget::value() const
{
    return QVector2D(m_doubleSpinBoxX->value(), m_doubleSpinBoxY->value());
}

void Vector2DWidget::setValue(const QVector2D &value)
{
    m_doubleSpinBoxX->setValue(value.x());
    m_doubleSpinBoxY->setValue(value.y());
}
