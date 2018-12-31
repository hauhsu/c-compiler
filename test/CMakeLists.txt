add_executable(lexer_test lexer_test.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(lexer_test ccompiler gtest_main)

# Now simply link against gtest or gtest_main as needed. Eg
add_test(NAME lexer_test COMMAND lexer_test)

file(COPY test.c
	 DESTINATION ".")


