#include "vector4dwidget.h"

#include <QHBoxLayout>
#include <QDoubleSpinBox>

Vector4DWidget::Vector4DWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins({});
    layout->addWidget(m_doubleSpinBoxX = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxY = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxZ = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxW = new QDoubleSpinBox(this));
    setLayout(layout);
}

QVector4D Vector4DWidget::value() const
{
    return QVector4D(m_doubleSpinBoxX->value(), m_doubleSpinBoxY->value(), m_doubleSpinBoxZ->value(), m_doubleSpinBoxW->value());
}

void Vector4DWidget::setValue(const QVector4D &value)
{
    m_doubleSpinBoxX->setValue(value.x());
    m_doubleSpinBoxY->setValue(value.y());
    m_doubleSpinBoxZ->setValue(value.z());
    m_doubleSpinBoxW->setValue(value.w());
}
