cmake_minimum_required(VERSION 3.10)
project(08_nasm_and_gas)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_ASM_COMPILER gcc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SOURCES "*.c" "*.s")

foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    if(${SOURCE} MATCHES "\\.c$")
        add_executable(${TARGET_NAME} ${SOURCE})
    elseif(${SOURCE} MATCHES "\\.s$")
        add_executable(${TARGET_NAME} ${SOURCE})
        set_target_properties(${TARGET_NAME} PROPERTIES
        LINKER_LANGUAGE C
        COMPILE_FLAGS "-x assembler-with-cpp"
        )
    endif()
endforeach()