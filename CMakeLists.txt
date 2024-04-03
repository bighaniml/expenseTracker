cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_projects)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp EventHandler.h EventHandler.cpp States.h ObjectState.h States.cpp SnapshotInterface.h SnapshotInterface.cpp Snapshot.h Snapshot.cpp GuiComponent.h GuiComponent.cpp KeyShortcuts.h KeyShortcuts.cpp MouseEvents.h MouseEvents.cpp HistoryNode.h History.h History.cpp TextInput.h TextInput.cpp helper.h helper.cpp Font.cpp MultiText.cpp Letter.cpp Item.h Item.cpp ItemList.h ItemList.cpp InputBox.h InputBox.cpp DropDownMenu.h DropDownMenu.cpp MenuBar.cpp RoundedRectangleShape.cpp InputWidget.h InputWidget.cpp Position.h Button.cpp Transaction.h Transaction.cpp TransactionsWidget.h TransactionsWidget.cpp HomePage.h HomePage.cpp BarGraph.h BarGraph.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()