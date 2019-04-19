#pragma once

#include "dbguilib_global.h"
#include <QWidget>

#include <QImage>

class DBGUILIB_EXPORT CanvasWidget : public QWidget
{
public:
    explicit CanvasWidget(QWidget *parent = Q_NULLPTR);

public Q_SLOTS:
    void setImage(const QImage &image);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QImage m_image;
};
