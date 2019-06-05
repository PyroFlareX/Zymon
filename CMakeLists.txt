cmake_minimum_required(VERSION 3.0.2)
project(Zymon CXX)

find_package(SFML COMPONENTS graphics REQUIRED)

add_executable(zymon ./src/Application.cpp
./src/Util/FileUtil.cpp
./src/Util/Input.cpp
./src/Zymon/Zymon.cpp
./src/Zymon/Move.cpp
./src/Zymon/Battle.cpp
./src/World/World.cpp
./src/Renderers/Renderer.cpp
./src/Player.cpp
./src/main.cpp
./src/States/Basestate.cpp
./src/States/BattleState.cpp
./src/States/Gamestate.cpp
./src/Camera.cpp
./src/Context.cpp)

target_link_libraries(zymon PRIVATE sfml-graphics)

file(COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/res/)
