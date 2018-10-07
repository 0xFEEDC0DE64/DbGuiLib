project(DbGuiLib)

set(HEADERS
    dbguilib_global.h
    editorfactory.h
    ledindicator.h
    limitedspinbox.h
    matrix4x4widget.h
    quaternionwidget.h
    stringlistwidget.h
    urlwidget.h
    vector2dwidget.h
    vector3dwidget.h
    vector4dwidget.h
)

set(SOURCES
    editorfactory.cpp
    ledindicator.cpp
    matrix4x4widget.cpp
    quaternionwidget.cpp
    stringlistwidget.cpp
    urlwidget.cpp
    vector2dwidget.cpp
    vector3dwidget.cpp
    vector4dwidget.cpp
)

set(FORMS
    qstringlistwidget.ui
)

add_library(dbguilib SHARED ${HEADERS} ${SOURCES} ${FORMS})

target_compile_definitions(dbguilib PRIVATE DBGUILIB_LIBRARY)

target_link_libraries(dbguilib Qt5::Core Qt5::Gui Qt5::Widgets)

target_include_directories(dbguilib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
