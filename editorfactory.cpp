#include "editorfactory.h"

#include <QStandardItemEditorCreator>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QKeySequenceEdit>

#include <limits>

#include "limitedspinbox.h"
#include "stringlistwidget.h"
#include "urlwidget.h"
#include "matrix4x4widget.h"
#include "vector2dwidget.h"
#include "vector3dwidget.h"
#include "vector4dwidget.h"
#include "quaternionwidget.h"

EditorFactory::EditorFactory() :
    QItemEditorFactory()
{
    registerEditor(QVariant::Bool, new QStandardItemEditorCreator<QCheckBox>());
    registerEditor(QVariant::Int, new QStandardItemEditorCreator<LimitedSpinBox<std::numeric_limits<qint32>::min(), std::numeric_limits<qint32>::max()> >());
    //registerEditor(QVariant::UInt, new QStandardItemEditorCreator<LimitedSpinBox<std::numeric_limits<quint32>::min(), std::numeric_limits<quint32>::max()> >());
    //registerEditor(QVariant::LongLong, new QStandardItemEditorCreator<LimitedSpinBox<std::numeric_limits<qint64>::min(), std::numeric_limits<qint64>::max()> >()); //TODO: implement 64 bit
    //registerEditor(QVariant::ULongLong, new QStandardItemEditorCreator<LimitedSpinBox<std::numeric_limits<quint64>::min(), std::numeric_limits<quint64>::max()> >()); //TODO: implement 64 bit
    registerEditor(QVariant::Double, new QStandardItemEditorCreator<QDoubleSpinBox>());
    registerEditor(QMetaType::Float, new QStandardItemEditorCreator<QDoubleSpinBox>()); //TODO: Make this a real QFloatSpinBox
    registerEditor(QVariant::ULongLong, new QStandardItemEditorCreator<LimitedSpinBox<std::numeric_limits<char>::min(), std::numeric_limits<char>::max()> >());
    //registerEditor(QVariant::Map, Q_NULLPTR); //TODO
    //registerEditor(QVariant::List, Q_NULLPTR); //TODO
    registerEditor(QVariant::String, new QStandardItemEditorCreator<QLineEdit>());
    registerEditor(QVariant::StringList, new QStandardItemEditorCreator<StringListWidget>());
    //registerEditor(QVariant::ByteArray, Q_NULLPTR); //TODO
    //registerEditor(QVariant::BitArray, Q_NULLPTR); //TODO
    registerEditor(QVariant::Date, new QStandardItemEditorCreator<QDateEdit>());
    registerEditor(QVariant::Time, new QStandardItemEditorCreator<QTimeEdit>());
    registerEditor(QVariant::DateTime, new QStandardItemEditorCreator<QDateTimeEdit>());
    registerEditor(QVariant::Url, new QStandardItemEditorCreator<UrlWidget>()); //TODO
    //registerEditor(QVariant::Locale, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Rect, Q_NULLPTR); //TODO
    //registerEditor(QVariant::RectF, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Size, Q_NULLPTR); //TODO
    //registerEditor(QVariant::SizeF, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Line, Q_NULLPTR); //TODO
    //registerEditor(QVariant::LineF, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Point, Q_NULLPTR); //TODO
    //registerEditor(QVariant::PointF, Q_NULLPTR); //TODO
    //registerEditor(QVariant::RegExp, Q_NULLPTR); //TODO
    //registerEditor(QVariant::RegularExpression, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Hash, Q_NULLPTR); //TODO
    //registerEditor(QVariant::EasingCurve, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Uuid, Q_NULLPTR); //TODO
    //registerEditor(QVariant::ModelIndex, Q_NULLPTR); //TODO
    //registerEditor(QVariant::PersistentModelIndex, Q_NULLPTR); //TODO

    //registerEditor(QVariant::Font, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Pixmap, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Brush, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Color, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Palette, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Image, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Polygon, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Region, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Bitmap, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Cursor, Q_NULLPTR); //TODO
    registerEditor(QVariant::KeySequence, new QStandardItemEditorCreator<QKeySequenceEdit>()); //TODO
    //registerEditor(QVariant::Pen, Q_NULLPTR); //TODO
    //registerEditor(QVariant::TextLength, Q_NULLPTR); //TODO
    //registerEditor(QVariant::TextFormat, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Matrix, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Transform, Q_NULLPTR); //TODO
    registerEditor(QVariant::Matrix4x4, new QStandardItemEditorCreator<Matrix4x4Widget>());
    registerEditor(QVariant::Vector2D, new QStandardItemEditorCreator<Vector2DWidget>());
    registerEditor(QVariant::Vector3D, new QStandardItemEditorCreator<Vector3DWidget>());
    registerEditor(QVariant::Vector4D, new QStandardItemEditorCreator<Vector4DWidget>());
    registerEditor(QVariant::Quaternion, new QStandardItemEditorCreator<QuaternionWidget>());
    //registerEditor(QVariant::PolygonF, Q_NULLPTR); //TODO
    //registerEditor(QVariant::Icon, Q_NULLPTR); //TODO

    //registerEditor(QVariant::SizePolicy, Q_NULLPTR); //TODO
}
