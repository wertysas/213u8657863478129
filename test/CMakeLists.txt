# Test Cmake

add_executable(unit_tests toybot_unit.cpp
                ${TOYBOT_SRC_DIR}/toy_bot.cpp
                # ${TOYBOT_SRC_DIR}/user_inpu_handler.cpp
)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

# Python tests
add_custom_target(system_tests
        COMMAND pytest system_test.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Running "
)
add_dependencies(system_tests toybot)
configure_file(toybot_test.py system_test.py @ONLY)