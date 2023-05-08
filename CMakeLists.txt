set(CMAKE_PREFIX_PATH "C:\\Qt\\6.5.0\\mingw_64\\")
set(QT_INSTALL_DIR "C:/Qt/6.5.0/mingw_64")

file(COPY ${QT_INSTALL_DIR}/bin/Qt6Core.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${QT_INSTALL_DIR}/bin/Qt6Gui.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${QT_INSTALL_DIR}/bin/Qt6Widgets.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(QT_INSTALL_DIR "C:/Qt/6.5.0/mingw_64/")

set(QT_QPA_PLATFORM_PLUGIN_PATH "${QT_INSTALL_DIR}/plugins/platforms")

set(PATH "$ENV{PATH};${QT_INSTALL_DIR}/bin")

file(COPY ${QT_QPA_PLATFORM_PLUGIN_PATH}/qwindows.dll
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/plugins/platforms)

set(CMAKE_INSTALL_RPATH "${QT_INSTALL_DIR}/bin")

if (WIN32)
    set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)
    include(InstallRequiredSystemLibraries)
endif()

cmake_minimum_required(VERSION 3.5)

project(Chess VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        Chess/main.cpp
        Chess/Qt/MainWindow.cpp
        Chess/Qt/MainWindow.h
        Chess/Qt/MainWindow.ui
        Chess/res.qrc
        Chess/Pieces/Bishop.h
        Chess/Pieces/Piece.h
        Chess/Pieces/Rook.h
        Chess/Pieces/Pawn.h
        Chess/Pieces/Queen.h
        Chess/Pieces/Knight.h
        Chess/Pieces/King.h
        Chess/Util.h
        Chess/Board.h
        Chess/Move.h
        Chess/Player.h
        Chess/Tile.h
        Chess/Pieces/Bishop.cpp
        Chess/Pieces/Pawn.cpp
        Chess/Pieces/Knight.cpp
        Chess/Pieces/Rook.cpp
        Chess/Pieces/Queen.cpp
        Chess/Pieces/King.cpp
        Chess/Board.cpp
        Chess/Move.cpp
        Chess/Tile.cpp
        Chess/Player.cpp
        Chess/Pieces/Piece.cpp
        Chess/Position.h
        Chess/Position.cpp
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Chess
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Chess APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Chess SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Chess
                ${PROJECT_SOURCES}
                )
    endif()
endif()

target_link_libraries(Chess PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Chess PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS Chess
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Chess)
endif()


