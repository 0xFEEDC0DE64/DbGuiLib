project(DbGuiLib)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5LinguistTools CONFIG REQUIRED)

set(HEADERS
    dbguilib_global.h
    editorfactory.h
    models/checklistmodel.h
    models/progressmodel.h
    widgets/canvaswidget.h
    widgets/databasewidget.h
    widgets/fileselectionwidget.h
    widgets/ledindicator.h
    widgets/limitedspinbox.h
    widgets/matrix4x4widget.h
    widgets/quaternionwidget.h
    widgets/stringlistwidget.h
    widgets/urlwidget.h
    widgets/vector2dwidget.h
    widgets/vector3dwidget.h
    widgets/vector4dwidget.h
)

set(SOURCES
    editorfactory.cpp
    models/checklistmodel.cpp
    models/progressmodel.cpp
    widgets/canvaswidget.cpp
    widgets/databasewidget.cpp
    widgets/fileselectionwidget.cpp
    widgets/ledindicator.cpp
    widgets/matrix4x4widget.cpp
    widgets/quaternionwidget.cpp
    widgets/stringlistwidget.cpp
    widgets/urlwidget.cpp
    widgets/vector2dwidget.cpp
    widgets/vector3dwidget.cpp
    widgets/vector4dwidget.cpp
)

set(FORMS
    widgets/databasewidget.ui
    widgets/fileselectionwidget.ui
    widgets/qstringlistwidget.ui
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
