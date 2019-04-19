#pragma once

#include <QWidget>
#include "dbguilib_global.h"

#include <QColor>

class DBGUILIB_EXPORT LedIndicator : public QWidget
{
    Q_OBJECT

public:
    LedIndicator(QWidget *parent = Q_NULLPTR);

    void setColor(const QColor &color);

protected:
    // QWidget interface
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QColor m_color;
};
