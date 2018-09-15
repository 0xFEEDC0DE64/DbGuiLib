#ifndef VECTOR4DWIDGET_H
#define VECTOR4DWIDGET_H

#include <QWidget>
#include "dbguilib_global.h"

#include <QVector4D>

class QDoubleSpinBox;

class DBGUILIB_EXPORT Vector4DWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QVector4D value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    Vector4DWidget(QWidget *parent = Q_NULLPTR);

    QVector4D value() const;
    void setValue(const QVector4D &value);

Q_SIGNALS:
    void valueChanged(const QVector4D &value);

private:
    QDoubleSpinBox *m_doubleSpinBoxX;
    QDoubleSpinBox *m_doubleSpinBoxY;
    QDoubleSpinBox *m_doubleSpinBoxZ;
    QDoubleSpinBox *m_doubleSpinBoxW;
};

#endif // VECTOR4DWIDGET_H
