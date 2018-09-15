#pragma once

#include <QWidget>
#include "dbguilib_global.h"

#include <QMatrix4x4>

class QDoubleSpinBox;

class DBGUILIB_EXPORT Matrix4x4Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QMatrix4x4 value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    Matrix4x4Widget(QWidget *parent = Q_NULLPTR);

    QMatrix4x4 value() const;
    void setValue(const QMatrix4x4 &value);

Q_SIGNALS:
    void valueChanged(const QMatrix4x4 &value);

private:
    QDoubleSpinBox *m_doubleSpinBox11, *m_doubleSpinBox12, *m_doubleSpinBox13, *m_doubleSpinBox14;
    QDoubleSpinBox *m_doubleSpinBox21, *m_doubleSpinBox22, *m_doubleSpinBox23, *m_doubleSpinBox24;
    QDoubleSpinBox *m_doubleSpinBox31, *m_doubleSpinBox32, *m_doubleSpinBox33, *m_doubleSpinBox34;
    QDoubleSpinBox *m_doubleSpinBox41, *m_doubleSpinBox42, *m_doubleSpinBox43, *m_doubleSpinBox44;
};
