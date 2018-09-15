#pragma once

#include <QSpinBox>

template<int Tmin, int Tmax>
class LimitedSpinBox : public QSpinBox
{
    //No Q_OBJECT because template (not needed anyways)

public:
    LimitedSpinBox(QWidget *parent = Q_NULLPTR);
};

template<int Tmin, int Tmax>
LimitedSpinBox<Tmin, Tmax>::LimitedSpinBox(QWidget *parent) : QSpinBox(parent)
{
    setRange(Tmin, Tmax);
}
