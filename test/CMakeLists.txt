add_executable(hcc main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(hcc hcc-lib)

file(COPY test.c
	 DESTINATION ".")


