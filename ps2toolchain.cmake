set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR mipsel)

set(TOOLS_DIR "${CMAKE_SOURCE_DIR}/tools")
set(INCLUDE_DIR "../include")
set(INCLUDE_DIRS "-I${INCLUDE_DIR} -I${INCLUDE_DIR}/sdk -I${INCLUDE_DIR}/tmhc")

if (LINUX OR APPLE)
    set(ENV{WINEARCH} "win32")

    set(CMAKE_C_COMPILER_LAUNCHER "wine")
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CMAKE_C_COMPILER_LAUNCHER})
endif()

set(CMAKE_C_COMPILER "${TOOLS_DIR}/ee-gcc2.95.3-136/bin/ee-gcc.exe")
set(CMAKE_CXX_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_ASM_COMPILER "mipsel-linux-gnu-as")
set(CMAKE_OBJCOPY "mipsel-linux-gnu-objcopy")
set(CMAKE_LINKER "mipsel-linux-gnu-ld")

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_ASM_FLAGS "-march=r5900 -mabi=eabi -no-pad-sections -v ${INCLUDE_DIRS}")
set(CMAKE_EXE_LINKER_FLAGS "-Map ${CONFIG_DIR}/tmhc.map -T ${BUILD_DIR}/tmhc.ld -T ${CONFIG_DIR}/undefined_funcs_auto.txt -T ${CONFIG_DIR}/undefined_syms_auto.txt")
set(CMAKE_C_FLAGS "-nostdinc -Wall -fno-exceptions -ffreestanding -O2 -G8 -v ${INCLUDE_DIRS}")

set(CMAKE_CXX_FLAGS_INIT "-x c++")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})