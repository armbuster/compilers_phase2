#append macro path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## ANTLR
# setup local antlr cpp source
include(findANTLR)
include(localAntlrCpp)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# generate lexer
#antlr_target(TigerLexer ${GRAMMAR_SOURCE}/${LEXER_NAME}.g4 LEXER
#             PACKAGE tiger)

# generate parser
if (${CREATE_ANTLR_VISITOR} AND ${CREATE_ANTLR_LISTENER})
	antlr_target(TigerIrParser ${GRAMMAR_SOURCE}/${PARSER_NAME}.g4
	             PACKAGE tiger
	             VISITOR
	             LISTENER)
elseif(${CREATE_ANTLR_VISITOR})
	antlr_target(TigerIrParser ${GRAMMAR_SOURCE}/${PARSER_NAME}.g4
	             PACKAGE tiger
	             VISITOR)
elseif(${CREATE_ANTLR_LISTENER})
	antlr_target(TigerIrParser ${GRAMMAR_SOURCE}/${PARSER_NAME}.g4
	             PACKAGE tiger
	             LISTENER)
else()
	antlr_target(TigerIrParser ${GRAMMAR_SOURCE}/${PARSER_NAME}.g4
	             PACKAGE tiger)
endif()


# include generated files in project environment
include_directories(${ANTLR_TigerIrLexer_OUTPUT_DIR})
include_directories(${ANTLR_TigerIrParser_OUTPUT_DIR})


file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})

# add generated grammar to binary target
add_executable(${BIN_NAME} main.cpp
               ${ANTLR_TigerIrLexer_CXX_OUTPUTS}
               ${ANTLR_TigerIrParser_CXX_OUTPUTS}
               ${SOURCES})

target_link_libraries(${BIN_NAME} ${ANTLR4_STATIC_LIBRARIES})

#create static lib from src/ and generated CXX files
#this is used to link to the test executable
add_library(${LIB_NAME} STATIC ${SOURCES}
			# ${ANTLR_TigerLexer_CXX_OUTPUTS}
			${ANTLR_TigerParser_CXX_OUTPUTS}
			)
