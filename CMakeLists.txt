cmake_minimum_required(VERSION 3.18)

project(cpp_statemachine_generator)

include(ExternalProject)
include(GNUInstallDirs REQUIRED)

add_executable(${CMAKE_PROJECT_NAME}
    "test/IoArHandler.cxx"
    "test/main.cxx"
)

ExternalProject_Add(cpp_event_framework
  GIT_REPOSITORY https://github.com/dziegel/cpp_event_framework.git
  GIT_TAG        main
  STEP_TARGETS   build
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}
)

add_dependencies(${CMAKE_PROJECT_NAME}
    cpp_event_framework
)

target_link_options(${CMAKE_PROJECT_NAME}
    PRIVATE
    -Xlinker -Map=map.txt
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC
    ${CMAKE_BINARY_DIR}/include
)

target_compile_options(${CMAKE_PROJECT_NAME}
    PRIVATE
    -std=c++20

    -Werror
    -pedantic
    -Wall
    -Wextra

    -Wcast-qual
    -Wwrite-strings
    -Wtrampolines
    -Wvla
    -Wshadow
    -Wmissing-include-dirs
    -Wfloat-equal
    -Wundef
    -Wcast-align

# Gnu specific warnings
#   for all versions of GCC
    $<$<CXX_COMPILER_ID:GNU>:-Wlogical-op>
    $<$<CXX_COMPILER_ID:GNU>:-Wduplicated-cond>

#   for GCC version >= 7
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,7>>:-Walloc-zero>
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,7>>:-Wduplicated-branches>

#   for GCC version >= 8
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,8>>:-Wcast-align=strict>

    # for GCC version >= 10
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wextra-semi>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wcatch-value>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wzero-as-null-pointer-constant>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wstrict-null-sentinel>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wvirtual-inheritance>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wmismatched-tags>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wctor-dtor-privacy>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wsuggest-override>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wold-style-cast>
    $<$<AND:$<COMPILE_LANG_AND_ID:CXX,GNU>,$<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,10>>:-Wmultiple-inheritance>
)
