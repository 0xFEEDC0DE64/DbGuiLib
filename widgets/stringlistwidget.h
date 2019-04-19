#pragma once

#include <QWidget>
#include "dbguilib_global.h"

class QStringListModel;

namespace Ui { class QStringListWidget; }

class DBGUILIB_EXPORT StringListWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QStringList value READ value WRITE setValue NOTIFY valueChanged USER true)

public:
    explicit StringListWidget(QWidget *parent = Q_NULLPTR);
    explicit StringListWidget(const QStringList &value, QWidget *parent = Q_NULLPTR);
    ~StringListWidget();

    QStringList value() const;
    void setValue(const QStringList &value);

Q_SIGNALS:
    void valueChanged(const QStringList &value);

private Q_SLOTS:
    void addPressed();
    void deletePressed();
    void selectionChanged();

private:
    void setup();

    Ui::QStringListWidget *ui;
    QStringListModel *m_model;
};
