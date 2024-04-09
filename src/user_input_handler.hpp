//
// Created by Johan Ericsson on 2024-04-08.
//

#ifndef TOYBOT_USER_INPUT_HANDLER_HPP
#define TOYBOT_USER_INPUT_HANDLER_HPP

#include <stdexcept>
#include <string>
#include "grid.hpp"
#include "toy_bot.hpp"

std::string direction_string(Direction direction);

class UserInputHandler {
public:
    explicit UserInputHandler(ToyBot& toy_bot) : toy_bot(toy_bot) {}
    void process_input();
private:
    ToyBot& toy_bot;
    Direction direction(const std::string& direction_string);
    void handle_input_command(const std::string& command, std::istringstream& input_stream);
    void handle_place_command(std::istringstream& input_stream);
    void handle_single_token_command(const std::string& command);

};


class InvalidInputException : public std::invalid_argument {
public:
    InvalidInputException(const std::string& message) :std::invalid_argument(message) {}
};



#endif //TOYBOT_USER_INPUT_HANDLER_HPP
