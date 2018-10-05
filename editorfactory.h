#pragma once

#include <QItemEditorFactory>
#include "dbguilib_global.h"

// Example usage:
// QItemEditorFactory::setDefaultFactory(new EditorFactory());

class DBGUILIB_EXPORT EditorFactory : public QItemEditorFactory
{
public:
    EditorFactory();
};
