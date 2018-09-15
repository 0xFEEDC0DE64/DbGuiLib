#include "urlwidget.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QFileDialog>

UrlWidget::UrlWidget(QWidget *parent) :
    QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_lineEdit = new QLineEdit(this));
    {
        auto toolButton = new QToolButton(this);
        connect(toolButton, &QAbstractButton::pressed, this, &UrlWidget::pressed);
        layout->addWidget(toolButton);
    }
    setLayout(layout);
}

QUrl UrlWidget::value() const
{
    return QUrl(m_lineEdit->text());
}

void UrlWidget::setValue(const QUrl &value)
{
    m_lineEdit->setText(value.toString());
}

void UrlWidget::pressed()
{
    auto path = QFileDialog::getOpenFileName(this);
    if(!path.isEmpty())
        m_lineEdit->setText(path);
}
