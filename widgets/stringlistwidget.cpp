#include "stringlistwidget.h"
#include "ui_qstringlistwidget.h"

#include <QStringListModel>

StringListWidget::StringListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QStringListWidget),
    m_model(new QStringListModel(this))
{
    setup();
}

StringListWidget::StringListWidget(const QStringList &stringList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QStringListWidget),
    m_model(new QStringListModel(stringList, this))
{
    setup();
}

StringListWidget::~StringListWidget()
{
    delete ui;
}

QStringList StringListWidget::value() const
{
    return m_model->stringList();
}

void StringListWidget::setValue(const QStringList &stringList)
{
    m_model->setStringList(stringList);
}

void StringListWidget::addPressed()
{
    auto index = ui->listView->currentIndex();

    m_model->insertRow(index.isValid() ? index.row() + 1: m_model->rowCount());
}

void StringListWidget::deletePressed()
{
    auto index = ui->listView->currentIndex();

    if(!index.isValid())
        return;

    m_model->removeRow(index.row());
}

void StringListWidget::selectionChanged()
{
    ui->pushButtonDelete->setEnabled(ui->listView->currentIndex().isValid());
}

void StringListWidget::setup()
{
    ui->setupUi(this);

    ui->listView->setModel(m_model);

    connect(ui->pushButtonAdd, &QAbstractButton::pressed, this, &StringListWidget::addPressed);
    connect(ui->pushButtonDelete, &QAbstractButton::pressed, this, &StringListWidget::deletePressed);
    connect(ui->listView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &StringListWidget::selectionChanged);

    selectionChanged();
}
