cmake_minimum_required(VERSION 3.15)
project(GOFISH)

set(CMAKE_CXX_STANDARD 11)

add_executable(GOFISH go_fish.cpp card.cpp card.h deck.cpp deck.h player.cpp player.h PlayerLog.txt)