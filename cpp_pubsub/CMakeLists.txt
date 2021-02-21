
cmake_minimum_required(VERSION 3.10)
project(cpp_pubsub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON)

#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH $ENV{Qt5minwg64_DIR})

#find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt5 REQUIRED Core Gui Widgets )
set(QT_LIBRARIES Qt5::Widgets)

#file(GLOB QT_FORMS       RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
#file(GLOB QT_RESOURCES   RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
#file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/cpp_pubsub/*.hpp *.h)
#file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

#QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
#QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
#QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
  
add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui
    src/ui_mainwindow.h
  )
ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs)
target_link_libraries(${PROJECT_NAME}  Qt5::Widgets)

#add_executable(${PROJECT_NAME} ${QT_FORMS} ${QT_RESOURCES} ${QT_MOC} ${QT_SOURCES} ${QT_RESOURCES_CPP})
#add_executable(${PROJECT_NAME} ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
#target_sources(${PROJECT_NAME} PUBLIC src/mainwindow.cpp mainwindow.h mainwindow.ui)

install(TARGETS
  talker
  listener
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})


#add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${RESOURCES} ${QMLS})
#target_link_libraries(${PROJECT_NAME}  Qt5::Core Qt5::Widgets Qt5::Gui rclcpp std_msgs) 
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
#target_link_libraries(${PROJECT_NAME} pthread)

ament_package()
