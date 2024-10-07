# CMakeList.txt : CMake project for cmake, include source and define
# project specific logic here.
#

# Add source to this project's executable. 
# New files (.cpp & .hpp) created need to be added here
cmake_minimum_required(VERSION 3.24)
project(commandLine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable (COMMANDLINE 
"main.cpp"
"inputListener.cpp"
"inputListener.hpp"
"optionsBox.cpp"
"optionsBox.hpp"
"introRoom.cpp"
"introRoom.hpp"
"pauseMenu.cpp"
"pauseMenu.hpp"
"oscarRoom.cpp"
"oscarRoom.hpp"
"callumRoom.cpp"
"callumRoom.hpp"
"anthonyRoom.cpp"
"anthonyRoom.hpp"
"lachlanRoom.cpp"
"lachlanRoom.hpp"
"readArt.cpp"
"readArt.hpp"
"timer.cpp"
"timer.hpp"
"renderArt.cpp"
"renderArt.hpp"
"startScreen.cpp"
"startScreen.hpp"
"saveOrLoadGame.cpp"
"saveOrLoadGame.hpp"
"terminalHelpers.cpp"
"terminalHelpers.hpp"
"textBox.cpp"
"textBox.hpp"
)

add_executable(TEST_COMMANDLINE
"tests/test.cpp"
"inputListener.cpp"
"inputListener.hpp"
"optionsBox.cpp"
"optionsBox.hpp"
"introRoom.cpp"
"introRoom.hpp"
"pauseMenu.cpp"
"pauseMenu.hpp"
"oscarRoom.cpp"
"oscarRoom.hpp"
"callumRoom.cpp"
"callumRoom.hpp"
"anthonyRoom.cpp"
"anthonyRoom.hpp"
"lachlanRoom.cpp"
"lachlanRoom.hpp"
"readArt.cpp"
"readArt.hpp"
"timer.cpp"
"timer.hpp"
"renderArt.cpp"
"renderArt.hpp"
"startScreen.cpp"
"startScreen.hpp"
"saveOrLoadGame.cpp"
"saveOrLoadGame.hpp"
"terminalHelpers.cpp"
"terminalHelpers.hpp"
"textBox.cpp"
"textBox.hpp"
)

# New .cpp files should be included here
add_library(src STATIC 
inputListener.cpp
optionsBox.cpp
introRoom.cpp
oscarRoom.cpp
anthonyRoom.cpp
lachlanRoom.cpp
timer.cpp
callumRoom.cpp
readArt.cpp
renderArt.cpp
startScreen.cpp
tests/test.cpp
saveOrLoadGame.cpp
pauseMenu.cpp
terminalHelpers.cpp
textBox.cpp)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_LIST_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/art DESTINATION ${CMAKE_BINARY_DIR})
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/art ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# TODO: Add tests and install targets if needed.