cmake_minimum_required(VERSION 3.10)
project(ezn-file-dialog)

set(BIN_NAME ezn_file_dialog)

set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(src_files "${INC_DIR}/ezn_file_dialog.h" "${INC_DIR}/ezn_fd_common.h")

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("building for linux machine")
    find_program(p zenity)
    message(${p})
    if(EXISTS ${p})
        message("machine using zenity")
        set(src_files ${src_files} "${SRC_DIR}/ezn_fd_zenity.cpp")
    endif()
endif()

message(${src_files})

set(EZN_FILE_DIALOG_LIB_TYPE SHARED CACHE STRING "Library type of ezn file dialog (e.g. SHARED, STATIC, etc.)")
add_library(${BIN_NAME} ${EZN_FILE_DIALOG_LIB_TYPE} ${src_files})
target_include_directories(${BIN_NAME} PUBLIC ${INC_DIR})