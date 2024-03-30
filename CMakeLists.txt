cmake_minimum_required(VERSION 3.27)
project(chess)

set(CMAKE_CXX_STANDARD 23)

add_executable(chess main.cpp
        piece.h
        bishop.h
        king.h
        knight.h
        pawn.h
        player.h
        queen.h
        rook.h
        board.h
        Game.cpp
        Game.h)
