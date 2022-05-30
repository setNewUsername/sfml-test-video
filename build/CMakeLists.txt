cmake_minimum_required(VERSION 3.8)

project(app_bin.bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(SFML COMPONENTS graphics window system)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SCREEN_MANAGER_DIR ${SRC_DIR}/ScreenManager)
set(SORTER_DIR ${SRC_DIR}/Sorter)
set(MESSAGE_DISTR_DIR ${SRC_DIR}/MessageModule)


#visualisation module

set(SCREEN_MANAGER ${SRC_DIR}/ScreenManager/ScreenManager.cpp ${SRC_DIR}/ScreenManager/ScreenManager.cpp)

set(THREAD_MANAGER ${SRC_DIR}/ThreadManager/ThreadManager.cpp ${SRC_DIR}/ThreadManager/ThreadManager.h)

set(OBJECT_MANAGER ${SRC_DIR}/ObjectManager/ObjectManager.cpp ${SRC_DIR}/ObjectManager/ObjectManager.h)

set(THREAD_CLIENT ${SRC_DIR}/ThreadClient/ThreadClient.cpp ${SRC_DIR}/ThreadClient/ThreadClient.h)

set(THREAD_CLIENT ${SRC_DIR}/ThreadClient/ThreadClient.cpp ${SRC_DIR}/ThreadClient/ThreadClient.h)

set(WINDOW_CONTAINER ${SCREEN_MANAGER_DIR}/Window/WindowContainer.cpp 
                     ${SCREEN_MANAGER_DIR}/Window/WindowContainer.h
                     ${SCREEN_MANAGER_DIR}/Window/WindowContainerEnum.h
                     ${SCREEN_MANAGER_DIR}/Window/WindowContainerInterface.h)

set(WINDOW_CONTAINER_FACTORY ${SCREEN_MANAGER_DIR}/WindowFactory/WindowFactory.cpp
                             ${SCREEN_MANAGER_DIR}/WindowFactory/WindowFactory.h 
                             ${SCREEN_MANAGER_DIR}/WindowFactory/WindowFactoryInterface.h)

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

#messaging module

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp)

#visualisation module

target_sources(${PROJECT_NAME} PUBLIC ${SCREEN_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${THREAD_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${OBJECT_MANAGER})

target_sources(${PROJECT_NAME} PUBLIC ${THREAD_CLIENT})

target_sources(${PROJECT_NAME} PUBLIC ${WINDOW_CONTAINER})

target_sources(${PROJECT_NAME} PUBLIC ${WINDOW_CONTAINER_FACTORY})

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

#messaging module


target_link_libraries(${PROJECT_NAME}  sfml-graphics sfml-window sfml-system)