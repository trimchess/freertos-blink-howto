add_executable(${OUTPUT_NAME}
        main.cpp
        )

target_link_libraries(${OUTPUT_NAME} PUBLIC
        pico_stdlib
        FreeRTOS-Kernel-Heap4
        )

#pico_enable_stdio_usb(${OUTPUT_NAME} 1)
#pico_enable_stdio_uart(${OUTPUT_NAME} 1)

pico_add_extra_outputs(${OUTPUT_NAME})
