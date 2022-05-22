cmake_minimum_required(VERSION 3.21)
project(JumpJump)

set(CMAKE_CXX_STANDARD 14)

add_executable(JumpJump main.cpp include/CONST.h src/GameEngine.cpp include/GameEngine.h include/BaseState.h src/IntroState.cpp include/IntroState.h src/MenuState.cpp include/MenuState.h src/PlayState.cpp include/PlayState.h src/Paddle.cpp include/Paddle.h src/PaddleCreate.cpp include/PaddleCreate.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Program Files/SFML-2.5.1)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

INCLUDE_DIRECTORIES(C:/Program Files/SFML-2.5.1/include)

target_link_libraries(JumpJump sfml-system sfml-window sfml-graphics sfml-network sfml-audio )