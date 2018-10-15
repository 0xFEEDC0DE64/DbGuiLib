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

set(TRANSLATIONS
    translations/dbguilib_en.ts
    translations/dbguilib_de.ts
)

set_source_files_properties(${TRANSLATIONS} PROPERTIES OUTPUT_LOCATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/translations)
QT5_CREATE_TRANSLATION(TRANSLATIONS_C ${TRANSLATIONS} ${HEADERS} ${SOURCES} ${FORMS} OPTIONS -no-obsolete)
#QT5_ADD_TRANSLATION(TRANSLATIONS_C ${TRANSLATIONS})

add_library(dbguilib SHARED ${HEADERS} ${SOURCES} ${FORMS} ${TRANSLATIONS_C})

target_compile_definitions(dbguilib PRIVATE DBGUILIB_LIBRARY)

target_link_libraries(dbguilib Qt5::Core Qt5::Gui Qt5::Widgets)

target_include_directories(dbguilib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_dependencies(libs dbguilib)
