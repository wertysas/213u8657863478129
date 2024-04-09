
add_executable(toybot main.cpp
        toy_bot.cpp
        grid.cpp
        user_input_handler.cpp
)

# executable path to be used for python tests
set(toybot_EXECUTABLE_PATH "${CMAKE_CURRENT_BINARY_DIR}/toybot")
