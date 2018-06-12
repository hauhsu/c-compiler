set(srcs Lexer.cpp Token.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(hcc-lib ${srcs})


