#pragma once

#include <QWidget>
#include "dbguilib_global.h"

#include <QQuaternion>

class QDoubleSpinBox;

class DBGUILIB_EXPORT QuaternionWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QQuaternion value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    QuaternionWidget(QWidget *parent = Q_NULLPTR);

    QQuaternion value() const;
    void setValue(const QQuaternion &value);

Q_SIGNALS:
    void valueChanged(const QQuaternion &value);

private:
    QDoubleSpinBox *m_doubleSpinBoxX;
    QDoubleSpinBox *m_doubleSpinBoxY;
    QDoubleSpinBox *m_doubleSpinBoxZ;
    QDoubleSpinBox *m_doubleSpinBoxScalar;
};
