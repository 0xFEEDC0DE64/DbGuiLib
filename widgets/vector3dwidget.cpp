#include "vector3dwidget.h"

#include <QHBoxLayout>
#include <QDoubleSpinBox>

Vector3DWidget::Vector3DWidget(QWidget *parent) :
    QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_doubleSpinBoxX = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxY = new QDoubleSpinBox(this));
    layout->addWidget(m_doubleSpinBoxZ = new QDoubleSpinBox(this));
    setLayout(layout);
}

QVector3D Vector3DWidget::value() const
{
    return QVector3D(m_doubleSpinBoxX->value(),  m_doubleSpinBoxY->value(), m_doubleSpinBoxZ->value());
}

void Vector3DWidget::setValue(const QVector3D &value)
{
    m_doubleSpinBoxX->setValue(value.x());
    m_doubleSpinBoxY->setValue(value.y());
    m_doubleSpinBoxZ->setValue(value.z());
}
