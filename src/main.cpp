#include "toy_bot.hpp"
#include "user_input_handler.hpp"



int main() {
    ToyBot toy_bot(5, 5);
    UserInputHandler user_input_handler(toy_bot);
    user_input_handler.process_input();
    return 0;
}


