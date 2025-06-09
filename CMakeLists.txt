cmake_minimum_required(VERSION 3.31)
project(BonsaiTeamProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(BonsaiTeamProject
        main.cpp
        admin/adminmenu.cpp
        admin/stockmanagement.cpp
        ui.cpp
        signup/signup.cpp
)

