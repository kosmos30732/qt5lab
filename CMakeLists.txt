CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(qt_os_lab)

SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)
LINK_LIBRARIES(Qt5::Widgets)

ADD_LIBRARY(static STATIC ${PROJECT_SOURCE_DIR}/src/static.cpp ${PROJECT_SOURCE_DIR}/include/static.h)
ADD_LIBRARY(dynamic SHARED ${PROJECT_SOURCE_DIR}/src/dynamic.cpp ${PROJECT_SOURCE_DIR}/include/dynamic.h)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

ADD_CUSTOM_COMMAND(OUTPUT ${PROJECT_SOURCE_DIR}/include/Buttons_MainWindow.h
		   COMMAND python3 ${PROJECT_SOURCE_DIR}/scripts/gen_button.py ${PROJECT_SOURCE_DIR}/gui/form.csv ${PROJECT_SOURCE_DIR}/include/Buttons_MainWindow.h
		   DEPENDS ${PROJECT_SOURCE_DIR}/gui/form.csv
		   WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

ADD_EXECUTABLE(b.out
	       ${PROJECT_SOURCE_DIR}/src/main.cpp
	       ${PROJECT_SOURCE_DIR}/src/MainWindow.cpp
	       ${PROJECT_SOURCE_DIR}/include/MainWindow.h
	       ${PROJECT_SOURCE_DIR}/include/Buttons_MainWindow.h)

TARGET_LINK_LIBRARIES(b.out dynamic static)
