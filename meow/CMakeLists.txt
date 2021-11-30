add_library(meow STATIC src/meow.h src/meow.cpp)
target_include_directories(meow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)