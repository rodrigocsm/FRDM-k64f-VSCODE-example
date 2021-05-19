cmake_minimum_required(VERSION 3.15.3)

# Optional: print out extra messages to see what is going on. Comment it to have less verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

# Path to toolchain file. This one has to be before 'project()' below
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake)

# Setup project, output and linker file
project(Tutorial)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${SDK_PATH}/devices/${SDK_MCU}/gcc/MK64FN1M0xxx12_flash.ld)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Optional: issue a message to be sure it uses the correct toolchain file.
message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

# List of source files
set(SRC_FILES
        src/main.c
        src/leds.c
        src/buttons.c
        ${SDK_PATH}/devices/${SDK_MCU}/gcc/startup_MK64F12.S
        ${SDK_PATH}/devices/${SDK_MCU}/system_MK64F12.c
        ${BOARD_PATH}/board.c
        ${BOARD_PATH}/pin_mux.c
        ${BOARD_PATH}/clock_config.c
        ${BOARD_PATH}/peripherals.c
        ${SDK_PATH}/devices/${SDK_MCU}/drivers/fsl_clock.c 
        ${SDK_PATH}/components/serial_manager/fsl_component_serial_manager.c
        ${SDK_PATH}/components/serial_manager/fsl_component_serial_port_uart.c
        ${SDK_PATH}/components/uart/fsl_adapter_uart.c
        ${SDK_PATH}/utilities/debug_console/debug_console/fsl_debug_console.c
        ${SDK_PATH}/utilities/debug_console/str/fsl_str.c
        ${SDK_PATH}/drivers/uart/fsl_uart.c
        ${SDK_PATH}/drivers/gpio/fsl_gpio.c
        )

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES})

# List of compiler defines, prefix with -D compiler option
target_compile_definitions(${EXECUTABLE} PRIVATE
        -DCPU_MK64FN1M0VLL12
        -DCPU_MK64FN1M0VLL12_cm4
        -DNDEBUG
        -DSERIAL_PORT_TYPE_UART=1
        -DSDK_DEBUGCONSOLE=1
        )

# List of includ directories
target_include_directories(${EXECUTABLE} PRIVATE
        src
        ${BOARD_PATH}
        ${SDK_PATH}/devices/${SDK_MCU}
        ${SDK_PATH}/devices/${SDK_MCU}/drivers        
        ${SDK_PATH}/CMSIS/Include
        ${SDK_PATH}/utilities/debug_console/debug_console
        ${SDK_PATH}/utilities/debug_console/str
        ${SDK_PATH}/components/serial_manager
        ${SDK_PATH}/components/uart
        ${SDK_PATH}/drivers/common
        ${SDK_PATH}/drivers/port
        ${SDK_PATH}/drivers/gpio
        ${SDK_PATH}/drivers/smc
        ${SDK_PATH}/drivers/uart
        )

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard

        -fdata-sections
        -ffunction-sections

        -Wall
        -O0
        -g3
        )

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
        -T${LINKER_FILE}
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -specs=nano.specs
        -lc
        -lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        -Xlinker -print-memory-usage -Xlinker
        )

# Optional: Print executable size as part of the post build process
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE})

# Optional: Create hex, bin and S-Record files after the build
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O srec --srec-len=64 ${EXECUTABLE} ${PROJECT_NAME}.s19
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)
