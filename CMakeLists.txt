cmake_minimum_required(VERSION 3.19.1)

project("v_1")

add_executable("v_1" "v1_0.cpp" "strategija1.h" "strategija1.cpp" "strategija2.h" "strategija2.cpp")

install (TARGETS "v_1" DESTINATION bin)
install (FILES "v1_0.cpp" "strategija1.h" "strategija1.cpp" "strategija2.h" "strategija2.cpp" DESTINATION src)
