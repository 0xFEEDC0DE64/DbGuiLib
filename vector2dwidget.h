#pragma once

#include <QWidget>
#include "dbguilib_global.h"

#include <QVector2D>

class QDoubleSpinBox;

class DBGUILIB_EXPORT Vector2DWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QVector2D value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    Vector2DWidget(QWidget *parent = Q_NULLPTR);

    QVector2D value() const;
    void setValue(const QVector2D &value);

Q_SIGNALS:
    void valueChanged(const QVector2D &value);

private:
    QDoubleSpinBox *m_doubleSpinBoxX;
    QDoubleSpinBox *m_doubleSpinBoxY;
};
