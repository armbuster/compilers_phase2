# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

#set project name
project(tiger_ir)

# set ANTLR visitor/listener
set(CREATE_ANTLR_LISTENER FALSE)
set(CREATE_ANTLR_VISITOR FALSE)

# set lexer and parser names to be used in src/CMakeLists.txt
set(LEXER_NAME irLexer)
set(PARSER_NAME irParser)

# TODO: find a way to use the variables from one subdirectory in another
set(LEXER_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/src/${LEXER_NAME})
set(PARSER_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/src/${PARSER_NAME})

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 11)

# set home paths
set(ANTLR4_HOME ${CMAKE_SOURCE_DIR}/antlr)
# set(TIGER_HOME ${CMAKE_SOURCE_DIR}/tiger)

#set the grammar source folder
set(GRAMMAR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/grammar)

# set bin names
set(BIN_NAME ${CMAKE_PROJECT_NAME}_run)
set(TEST_BIN_NAME ${CMAKE_PROJECT_NAME}_test)

# set lib names
set(LIB_NAME ${CMAKE_PROJECT_NAME})

# set source paths
set(ANTLR_SRC ${ANTLR4_HOME}/antlr4_runtime)
set(IR_SRC src)


add_compile_options(-g)
# #append macro path
# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# include(localAntlrCpp)
set(ANTLR4_LIB_NAME antlr4-runtime)
set(ANTLR4_LIB_DIR ${ANTLR4_HOME}/lib)

# source include directories
include_directories(${ANTLR_SRC})
include_directories(${IR_SRC})

# add cmake sub directories
add_subdirectory(${IR_SRC})
add_subdirectory(test)
add_subdirectory(lib/googletest)