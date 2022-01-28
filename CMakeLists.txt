cmake_minimum_required(VERSION 3.18)

project(ioarhandler)

include(GNUInstallDirs REQUIRED)

add_executable(ioarhandler
    "Statemachine Test/generated/main.cxx"
)

target_link_options(ioarhandler
    PRIVATE
    -Xlinker -Map=map.txt
)

target_include_directories(ioarhandler
    PUBLIC
    ../cpp_event_framework/include
)

target_compile_options(ioarhandler
    PRIVATE
    -std=c++17

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