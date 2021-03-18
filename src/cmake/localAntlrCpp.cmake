cmake_minimum_required(VERSION 3.7)

message(STATUS "Running localAntlrCpp")

set(ANTLR4_SOURCE ${ANTLR4_HOME})
set(ANTLR4_INCLUDE_DIRS ${ANTLR4_SOURCE}/antlr4-runtime)

message(${ANTLR4_LIB_DIR})

if(MSVC)
  set(ANTLR4_STATIC_LIBRARIES
      ${ANTLR4_LIB_DIR}/antlr4-runtime-static.lib)
  set(ANTLR4_SHARED_LIBRARIES
      ${ANTLR4_LIB_DIR}/antlr4-runtime.lib)
  set(ANTLR4_RUNTIME_LIBRARIES
      ${ANTLR4_LIB_DIR}/antlr4-runtime.dll)
else()
  set(ANTLR4_STATIC_LIBRARIES
      ${ANTLR4_LIB_DIR}/libantlr4-runtime.a)
  if(MINGW)
    set(ANTLR4_SHARED_LIBRARIES
        ${ANTLR4_LIB_DIR}/libantlr4-runtime.dll.a)
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_LIB_DIR}/libantlr4-runtime.dll)
  elseif(CYGWIN)
    set(ANTLR4_SHARED_LIBRARIES
        ${ANTLR4_LIB_DIR}/libantlr4-runtime.dll.a)
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_LIB_DIR}/cygantlr4-runtime-4.9.1.dll)
  elseif(APPLE)
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_LIB_DIR}/libantlr4-runtime.dylib)
  else()
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_LIB_DIR}/libantlr4-runtime.so)
  endif()
endif()

if(NOT DEFINED ANTLR4_WITH_STATIC_CRT)
  set(ANTLR4_WITH_STATIC_CRT ON)
endif()


message(STATUS "Running localAntlrCpp - done")
