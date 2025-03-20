cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE "ps2toolchain.cmake")
project(TMHC)
enable_language(ASM)

# Directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(ASM_DIR "${CMAKE_SOURCE_DIR}/asm")
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
set(CONFIG_DIR "${CMAKE_SOURCE_DIR}/config")

# Compiler
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ASM_COMPILE_OBJECT "${CMAKE_ASM_COMPILER} ${CMAKE_ASM_FLAGS} -o <OBJECT> <SOURCE>")

# Source files
file(GLOB_RECURSE CPP_SRC "${SRC_DIR}/tmhc/*.cpp")
file(GLOB_RECURSE INCLUDE_SRC "${INCLUDE_DIR}/*.h")
file(GLOB ASM_SRC "${ASM_DIR}/*.s")
file(GLOB ASM_SRC_DATA "${ASM_DIR}/data/*.s")
file(GLOB ASM_SRC_SDK "${ASM_DIR}/sdk/*.s")
file(GLOB ASM_SRC_TMHC "${ASM_DIR}/tmhc/*.s")
file(GLOB ASM_SRC_NONMATCHINGS "${ASM_DIR}/nonmatchings/tmhc/*.s")
list(APPEND ASM_SRC ${ASM_SRC_DATA} ${ASM_SRC_SDK} ${ASM_SRC_TMHC})

set_source_files_properties(${ASM_SRC} PROPERTIES LANGUAGE ASM)

# Targets
add_custom_target(splat
    COMMAND rm -rf ${ASM_DIR}
    COMMAND python3 -m splat split ${CONFIG_DIR}/tmhc.yaml
)

add_executable(TMHC ${ASM_SRC} ${CPP_SRC} ${INCLUDE_SRC})
target_include_directories(TMHC PRIVATE 
    "${INCLUDE_DIR}" 
    "${INCLUDE_DIR}/sdk" 
    "${INCLUDE_DIR}/tmhc"
)

# Strip the binary
#add_custom_command(
#    TARGET TMHC
#    POST_BUILD
#    COMMAND ${CMAKE_OBJCOPY} -O binary TMHC.elf ${BUILD_DIR}/TMHC-Rebuilt.elf
#)

# Strip the pre-linked object files
# add_custom_command(
#    TARGET TMHC
#    PRE_LINK
#    COMMAND find ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir -name "*.o" -exec mipsel-linux-gnu-strip {} -N dummy_symbol_name \;
#)