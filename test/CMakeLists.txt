message(STATUS "Running test/ CMakeLists.txt")

# set sources
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${TEST_SOURCES})

# include generated files in project environment
include_directories(${LEXER_OUTPUT_DIR})
include_directories(${PARSER_OUTPUT_DIR})

find_library(ANTLR_LIB 
	NAMES libantlr4-runtime.a antlr4-runtime
	PATHS ${ANTLR4_LIB_DIR}
	)
message(${ANTLR_LIB})

# add bin
add_executable(${TEST_BIN_NAME} ${TEST_SOURCES})

# add tests
add_test(NAME ${TEST_BIN_NAME} COMMAND ${TEST_BIN_NAME})

# link src library
target_link_libraries(${TEST_BIN_NAME} PUBLIC ${LIB_NAME} gtest ${ANTLR_LIB})

message(STATUS "test/ CMakeLists.txt - done")