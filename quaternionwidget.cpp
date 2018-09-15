#include "quaternionwidget.h"

#include <QHBoxLayout>
#include <QDoubleSpinBox>

QuaternionWidget::QuaternionWidget(QWidget *parent) :
    QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_doubleSpinBoxX = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxY = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxZ = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxScalar = new QDoubleSpinBox(this));
    setLayout(layout);
}

QQuaternion QuaternionWidget::value() const
{
    return QQuaternion(m_doubleSpinBoxX->value(), m_doubleSpinBoxY->value(), m_doubleSpinBoxZ->value(), m_doubleSpinBoxScalar->value());
}

void QuaternionWidget::setValue(const QQuaternion &value)
{
    m_doubleSpinBoxX->setValue(value.x());
    m_doubleSpinBoxY->setValue(value.y());
    m_doubleSpinBoxZ->setValue(value.z());
    m_doubleSpinBoxScalar->setValue(value.scalar());
}
