cmake_minimum_required(VERSION 2.8)
set(BACKTRACE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)

add_subdirectory(${BACKTRACE_ROOT}/libunwind/cmake libunwind)

include_directories(${BACKTRACE_ROOT} ${BACKTRACE_ROOT}/include ${BACKTRACE_ROOT}/libunwind/include)

file(GLOB BACKTRACE_SOURCES
    ${BACKTRACE_ROOT}/Backtrace.cpp
    ${BACKTRACE_ROOT}/BacktraceCurrent.cpp
    ${BACKTRACE_ROOT}/BacktracePtrace.cpp
    ${BACKTRACE_ROOT}/thread_utils.c
    ${BACKTRACE_ROOT}/ThreadEntry.cpp
    ${BACKTRACE_ROOT}/UnwindCurrent.cpp
    ${BACKTRACE_ROOT}/UnwindMap.cpp
    ${BACKTRACE_ROOT}/UnwindPtrace.cpp
    ${BACKTRACE_ROOT}/BacktraceMap.cpp
    ${BACKTRACE_ROOT}/android-base/stringprintf.cpp
    ${BACKTRACE_ROOT}/android-base/logging.cpp
    ${BACKTRACE_ROOT}/demangle.cpp
    ${BACKTRACE_ROOT}/getline.c
)

add_library(backtrace STATIC ${BACKTRACE_SOURCES})
target_link_libraries(backtrace unwind)
