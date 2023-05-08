cmake_minimum_required(VERSION 3.5)

project(Chess VERSION 0.1 LANGUAGES CXX)

set(BUILD_DIRECTORY "${CMAKE_BINARY_DIR}")
set(BUILD_BIN_DIRECTORY "${BUILD_DIRECTORY}/bin")
set(BUILD_LIB_DIRECTORY "${BUILD_DIRECTORY}/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_LIB_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_LIB_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_BIN_DIRECTORY}")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    cmake_path(GET CMAKE_CXX_COMPILER PARENT_PATH COMPILER_DIRECTORY)

    file(COPY "${COMPILER_DIRECTORY}/libgcc_s_seh-1.dll" DESTINATION "${BUILD_BIN_DIRECTORY}")
    file(COPY "${COMPILER_DIRECTORY}/libstdc++-6.dll" DESTINATION "${BUILD_BIN_DIRECTORY}")
    file(COPY "${COMPILER_DIRECTORY}/libwinpthread-1.dll" DESTINATION "${BUILD_BIN_DIRECTORY}")
endif ()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    get_target_property(QT_CORE_LIBRARY Qt6::Core IMPORTED_LOCATION)
    get_target_property(QT_GUI_LIBRARY Qt6::Gui IMPORTED_LOCATION)
    get_target_property(QT_WIDGETS_LIBRARY Qt6::Widgets IMPORTED_LOCATION)

    file(COPY "${QT_CORE_LIBRARY}" DESTINATION "${BUILD_BIN_DIRECTORY}")

    file(COPY "${QT_GUI_LIBRARY}" DESTINATION "${BUILD_BIN_DIRECTORY}")

    file(COPY "${QT_WIDGETS_LIBRARY}" DESTINATION "${BUILD_BIN_DIRECTORY}")
    cmake_path(GET QT_GUI_LIBRARY PARENT_PATH QT_BIN_DIRECTORY)
    cmake_path(GET QT_BIN_DIRECTORY PARENT_PATH QT_DIRECTORY)
    cmake_path(APPEND QT_PLUGINS_DIRECTORY "${QT_DIRECTORY}" "plugins")
    cmake_path(APPEND QT_PLUGINS_PLATFORMS_DIRECTORY "${QT_PLUGINS_DIRECTORY}" "platforms")
    cmake_path(APPEND QT_PLATFORM_LIBRARY "${QT_PLUGINS_PLATFORMS_DIRECTORY}" "qwindows.dll")
    cmake_path(APPEND BUILD_BIN_PLUGINS_DIRECTORY "${BUILD_BIN_DIRECTORY}" "plugins")
    cmake_path(APPEND BUILD_BIN_PLUGINS_PLATFORMS_DIRECTORY "${BUILD_BIN_PLUGINS_DIRECTORY}" "platforms")
    file(COPY "${QT_PLATFORM_LIBRARY}" DESTINATION "${BUILD_BIN_PLUGINS_PLATFORMS_DIRECTORY}")
endif ()

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

qt_add_executable(Chess
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        )

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options("Chess" PRIVATE "/Zc:__cplusplus")
endif ()

target_link_libraries(Chess PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

qt_finalize_executable(Chess)
