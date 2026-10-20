cmake_minimum_required(VERSION 3.10.0)
project(Capstone VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Capstone main.cpp
    Player.cpp
    Piece.cpp
    Board.cpp)

