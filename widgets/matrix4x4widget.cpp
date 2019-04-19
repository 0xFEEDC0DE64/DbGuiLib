#include "matrix4x4widget.h"

#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QVector4D>

Matrix4x4Widget::Matrix4x4Widget(QWidget *parent) :
    QWidget(parent)
{
    auto layout = new QGridLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_doubleSpinBox11 = new QDoubleSpinBox(this), 0, 0);
    layout->addWidget(m_doubleSpinBox12 = new QDoubleSpinBox(this), 0, 1);
    layout->addWidget(m_doubleSpinBox13 = new QDoubleSpinBox(this), 0, 2);
    layout->addWidget(m_doubleSpinBox14 = new QDoubleSpinBox(this), 0, 3);
    layout->addWidget(m_doubleSpinBox21 = new QDoubleSpinBox(this), 1, 0);
    layout->addWidget(m_doubleSpinBox22 = new QDoubleSpinBox(this), 1, 1);
    layout->addWidget(m_doubleSpinBox23 = new QDoubleSpinBox(this), 1, 2);
    layout->addWidget(m_doubleSpinBox24 = new QDoubleSpinBox(this), 1, 3);
    layout->addWidget(m_doubleSpinBox31 = new QDoubleSpinBox(this), 2, 0);
    layout->addWidget(m_doubleSpinBox32 = new QDoubleSpinBox(this), 2, 1);
    layout->addWidget(m_doubleSpinBox33 = new QDoubleSpinBox(this), 2, 2);
    layout->addWidget(m_doubleSpinBox34 = new QDoubleSpinBox(this), 2, 3);
    layout->addWidget(m_doubleSpinBox41 = new QDoubleSpinBox(this), 3, 0);
    layout->addWidget(m_doubleSpinBox42 = new QDoubleSpinBox(this), 3, 1);
    layout->addWidget(m_doubleSpinBox43 = new QDoubleSpinBox(this), 3, 2);
    layout->addWidget(m_doubleSpinBox44 = new QDoubleSpinBox(this), 3, 3);
    setLayout(layout);
}

QMatrix4x4 Matrix4x4Widget::value() const
{
    return QMatrix4x4(m_doubleSpinBox11->value(), m_doubleSpinBox12->value(), m_doubleSpinBox13->value(), m_doubleSpinBox14->value(),
                      m_doubleSpinBox21->value(), m_doubleSpinBox22->value(), m_doubleSpinBox23->value(), m_doubleSpinBox24->value(),
                      m_doubleSpinBox31->value(), m_doubleSpinBox32->value(), m_doubleSpinBox33->value(), m_doubleSpinBox34->value(),
                      m_doubleSpinBox41->value(), m_doubleSpinBox42->value(), m_doubleSpinBox43->value(), m_doubleSpinBox44->value());
}

void Matrix4x4Widget::setValue(const QMatrix4x4 &value)
{
    {
        auto row = value.row(0);
        m_doubleSpinBox11->setValue(row.x());
        m_doubleSpinBox12->setValue(row.y());
        m_doubleSpinBox13->setValue(row.z());
        m_doubleSpinBox14->setValue(row.w());
    }
    {
        auto row = value.row(1);
        m_doubleSpinBox21->setValue(row.x());
        m_doubleSpinBox22->setValue(row.y());
        m_doubleSpinBox23->setValue(row.z());
        m_doubleSpinBox24->setValue(row.w());
    }
    {
        auto row = value.row(2);
        m_doubleSpinBox31->setValue(row.x());
        m_doubleSpinBox32->setValue(row.y());
        m_doubleSpinBox33->setValue(row.z());
        m_doubleSpinBox34->setValue(row.w());
    }
    {
        auto row = value.row(3);
        m_doubleSpinBox41->setValue(row.x());
        m_doubleSpinBox42->setValue(row.y());
        m_doubleSpinBox43->setValue(row.z());
        m_doubleSpinBox44->setValue(row.w());
    }
}
