#pragma once

#include <QWidget>
#include "dbguilib_global.h"

#include <QVector3D>

class QDoubleSpinBox;

class DBGUILIB_EXPORT Vector3DWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QVector3D value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    Vector3DWidget(QWidget *parent = Q_NULLPTR);

    QVector3D value() const;
    void setValue(const QVector3D &value);

Q_SIGNALS:
    void valueChanged(const QVector3D &value);

private:
    QDoubleSpinBox *m_doubleSpinBoxX;
    QDoubleSpinBox *m_doubleSpinBoxY;
    QDoubleSpinBox *m_doubleSpinBoxZ;
};
