cmake_minimum_required(VERSION 3.8)

project(app_bin.bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(SFML COMPONENTS graphics window system)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SCREEN_MANAGER_DIR ${SRC_DIR}/ScreenManager)
set(SORTER_DIR ${SRC_DIR}/Sorter)
set(MESSAGE_DISTR_DIR ${SRC_DIR}/MessageModule)
set(VISUAL_MODULE_DIR ${SRC_DIR}/VisualModule)

set(WINDOW_TYPES_DIR ${VISUAL_MODULE_DIR}/Window)

#thread module

set(THREAD_MANAGER ${SRC_DIR}/ThreadModule/ThreadManager/ThreadManager.cpp ${SRC_DIR}/ThreadModule/ThreadManager/ThreadManager.h)

set(OBJECT_MANAGER ${SRC_DIR}/ObjectManager/ObjectManager.cpp ${SRC_DIR}/ObjectManager/ObjectManager.h)

set(THREAD_CLIENT ${SRC_DIR}/ThreadModule/ThreadClient/ThreadClient.cpp ${SRC_DIR}/ThreadModule/ThreadClient/ThreadClient.h)

#thread module


#visualisation module

set(WINDOW ${VISUAL_MODULE_DIR}/Window/BaseWindow.h
           ${VISUAL_MODULE_DIR}/Window/BaseWindow.cpp
           ${VISUAL_MODULE_DIR}/Window/WindowInterface.h
           ${VISUAL_MODULE_DIR}/Window/WindowType.h)

set(WINDOW_FACTORY ${VISUAL_MODULE_DIR}/WindowFactory/WindowFactory.h
                   ${VISUAL_MODULE_DIR}/WindowFactory/WindowFactory.cpp)

set(WINDOW_MANAGER  ${VISUAL_MODULE_DIR}/WindowManager/WindowManager.h
                    ${VISUAL_MODULE_DIR}/WindowManager/WindowManager.cpp)

    #window types

    set(MAIN_WINDOW ${WINDOW_TYPES_DIR}/MainWindow/MainWindow.h
                    ${WINDOW_TYPES_DIR}/MainWindow/MainWindow.cpp)

    #window types

#visualisation module



#array module

set(ARRAY_CONTAINER ${SRC_DIR}/ArrayContainer/ArrayContainer.cpp ${SRC_DIR}/ArrayContainer/ArrayContainer.h)

#array module



#sortiration module

set(SORTER ${SRC_DIR}/Sorter/Sorter.cpp ${SRC_DIR}/Sorter/Sorter.h ${SRC_DIR}/Sorter/SortirationTypesEnum.h)

set(BUBBLE_SORTER ${SORTER_DIR}/BubbleSorter/BubbleSorter.cpp ${SORTER_DIR}/BubbleSorter/BubbleSorter.h)

set(SORTER_FACTORY ${SORTER_DIR}/SorterFactory/SorterFactory.cpp ${SORTER_DIR}/SorterFactory/SorterFactory.h)

#sortiration module


#messaging module

set(MSG_DISTR ${MESSAGE_DISTR_DIR}/MsgDistr/MsgDistr.cpp ${MESSAGE_DISTR_DIR}/MsgDistr/MsgDistr.h)

set(MSG_CLIENT ${MESSAGE_DISTR_DIR}/MsgClient/MsgClient.cpp
               ${MESSAGE_DISTR_DIR}/MsgClient/MsgClient.h
               ${MESSAGE_DISTR_DIR}/MsgClient/MsgClientName.h
               ${MESSAGE_DISTR_DIR}/MsgClient/MsgClientInterface.h)

set(MESSAGE ${MESSAGE_DISTR_DIR}/Msg/BaseMessage.cpp
            ${MESSAGE_DISTR_DIR}/Msg/BaseMessage.h
            ${MESSAGE_DISTR_DIR}/Msg/MsgRequestBody.h)

set(MSG_SHARED_QUEUE ${MESSAGE_DISTR_DIR}/MsgQueue/MsgQueue.cpp
                     ${MESSAGE_DISTR_DIR}/MsgQueue/MsgQueue.h)

#messaging module

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp)


#visualisation module

target_sources(${PROJECT_NAME} PUBLIC ${THREAD_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${OBJECT_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${THREAD_CLIENT})

target_sources(${PROJECT_NAME} PUBLIC ${WINDOW})

target_sources(${PROJECT_NAME} PUBLIC ${WINDOW_FACTORY})

target_sources(${PROJECT_NAME} PUBLIC ${WINDOW_MANAGER})

    #window types

    target_sources(${PROJECT_NAME} PUBLIC ${MAIN_WINDOW})

    #window types

#visualisation module


#array module

target_sources(${PROJECT_NAME} PUBLIC ${ARRAY_CONTAINER})

#array module


#sortiration module

target_sources(${PROJECT_NAME} PUBLIC ${SORTER})

target_sources(${PROJECT_NAME} PUBLIC ${BUBBLE_SORTER})

target_sources(${PROJECT_NAME} PUBLIC ${SORTER_FACTORY})

#sortiration module


#messaging module

target_sources(${PROJECT_NAME} PUBLIC ${MSG_DISTR})

target_sources(${PROJECT_NAME} PUBLIC ${MSG_CLIENT})

target_sources(${PROJECT_NAME} PUBLIC ${MESSAGE})

target_sources(${PROJECT_NAME} PUBLIC ${MSG_SHARED_QUEUE})

#messaging module


target_link_libraries(${PROJECT_NAME}  sfml-graphics sfml-window sfml-system)