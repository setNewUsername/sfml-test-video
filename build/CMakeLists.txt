cmake_minimum_required(VERSION 3.8)

project(app_bin.bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(SFML COMPONENTS graphics window system)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(SCREEN_MANAGER ${SRC_DIR}/ScreenManager/ScreenManager.cpp ${SRC_DIR}/ScreenManager/ScreenManager.cpp)

set(THREAD_MANAGER ${SRC_DIR}/ThreadManager/ThreadManager.cpp ${SRC_DIR}/ThreadManager/ThreadManager.h)

set(OBJECT_MANAGER ${SRC_DIR}/ObjectManager/ObjectManager.cpp ${SRC_DIR}/ObjectManager/ObjectManager.h)

set(THREAD_CLIENT ${SRC_DIR}/ThreadClient/ThreadClient.cpp ${SRC_DIR}/ThreadClient/ThreadClient.h)

set(THREAD_CLIENT ${SRC_DIR}/ThreadClient/ThreadClient.cpp ${SRC_DIR}/ThreadClient/ThreadClient.h)

set(WINDOW_CONTAINER ${SRC_DIR}/ScreenManager/Window/WindowContainer.cpp ${SRC_DIR}/ScreenManager/Window/WindowContainer.h ${SRC_DIR}/ScreenManager/Window/WindowContainerEnum.h)

set(TEST_CLASS ${SRC_DIR}/test/test.cpp ${SRC_DIR}/test/test.h)

#set(DIRECTIONS ${SRC_DIR}/Snake/Direction.h)

#set(APPLE ${SRC_DIR}/Apple/Apple.cpp ${SRC_DIR}/Apple/Apple.h)

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp)

target_sources(${PROJECT_NAME} PUBLIC ${SCREEN_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${THREAD_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${OBJECT_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${THREAD_CLIENT})

target_sources(${PROJECT_NAME} PUBLIC ${TEST_CLASS})

target_sources(${PROJECT_NAME} PUBLIC ${WINDOW_CONTAINER})

target_link_libraries(${PROJECT_NAME}  sfml-graphics sfml-window sfml-system)