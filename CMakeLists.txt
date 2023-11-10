cmake_minimum_required(VERSION 3.26)
project(TakeAway)

set(CMAKE_CXX_STANDARD 17)

add_executable(TakeAway main.cpp
        Menu.cpp
        Menu.h
        Order.cpp
        Order.h
        Item.cpp
        Item.h
        ItemList.cpp
        ItemList.h
        Appetiser.cpp
        Appetiser.h
        MainCourse.cpp
        MainCourse.h
        Beverage.cpp
        Beverage.h
)
