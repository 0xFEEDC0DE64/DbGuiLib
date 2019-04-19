#pragma once

#include <QWidget>
#include "dbguilib_global.h"

#include <QUrl>

class QLineEdit;

class DBGUILIB_EXPORT UrlWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QUrl value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    UrlWidget(QWidget *parent = Q_NULLPTR);

    QUrl value() const;
    void setValue(const QUrl &value);

Q_SIGNALS:
    void valueChanged(const QUrl &value);

private Q_SLOTS:
    void pressed();

private:
    QLineEdit *m_lineEdit;
};
