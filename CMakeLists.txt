cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Pieces/Piece.cpp
        Pieces/Piece.h
        Pieces/Pawn/Pawn.cpp
        Pieces/Pawn/Pawn.h
        Pieces/Knight/Knight.cpp
        Pieces/Knight/Knight.h
        Pieces/Bishop/Bishop.cpp
        Pieces/Bishop/Bishop.h
        Pieces/Rook/Rook.cpp
        Pieces/Rook/Rook.h
        Pieces/Queen/Queen.cpp
        Pieces/Queen/Queen.h
        Pieces/King/King.cpp
        Pieces/King/King.h
        Player/Player.cpp
        Player/Player.h
        Board/Board.cpp
        Board/Board.h
        Game/Game.cpp
        Game/Game.h)
