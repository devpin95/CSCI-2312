cmake_minimum_required(VERSION 3.7)
project(final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Asset.cpp Asset.h Book.cpp Book.h Video.cpp Video.h Store.cpp Store.h Search.cpp Search.h Factory.cpp Factory.h Sort.cpp Sort.h FileException.h)
add_executable(final ${SOURCE_FILES})