//
// Created by Johan Ericsson on 2024-04-08.
//

#include "user_input_handler.hpp"
#include <iostream>
#include <sstream>

std::string direction_string(Direction direction) {
    switch (direction) {
        case Direction::north:
            return "NORTH";
        case Direction::south:
            return "SOUTH";
        case Direction::east:
            return "EAST";
        case Direction::west:
            return "WEST";
    }
}

Direction UserInputHandler::direction(const std::string &direction_string) {
    if (direction_string == "NORTH") return Direction::north;
    if (direction_string == "SOUTH") return Direction::south;
    if (direction_string == "WEST") return Direction::west;
    if (direction_string == "EAST") return Direction::east;

    throw InvalidInputException("Invalid direction input: " + direction_string);
}



void UserInputHandler::process_input() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream input_stream(input);
        std::string command;
        input_stream >> command;
        try {
            handle_input_command(command, input_stream);
        } catch (InvalidInputException &e) {
            std::cerr << e.what() << std::endl;
            std::exit(1);
        }
    }
}

void UserInputHandler::handle_input_command(const std::string &command, std::istringstream &input_stream) {
    if (input_stream.eof()) {
        handle_single_token_command(command);
    } else if (command == "PLACE") {
        handle_place_command(input_stream);
    } else {
        throw InvalidInputException("Invalid input: " + command);
    }

}

void UserInputHandler::handle_place_command(std::istringstream &input_stream) {
    char c1, c2;
    int x, y;
    std::string dir_str;
    if ((input_stream >> x >> c1 >> y >> c2 >> dir_str) && c1 == ',' && c2 == ',') {
        Direction dir = direction(dir_str);
        toy_bot.place({x, y}, dir);
    } else {
        throw InvalidInputException("Invalid place command");
    }
}

void UserInputHandler::handle_single_token_command(const std::string &command) {
    if (!toy_bot.initialized()) return;

    if (command == "MOVE") {
        toy_bot.move();
    } else if (command == "LEFT") {
        toy_bot.rotate(RotationDirection::left);
    } else if (command == "RIGHT") {
        toy_bot.rotate(RotationDirection::right);
    } else if (command == "REPORT") {
        GridPoint pos = toy_bot.position();
        std::cout << pos.x << "," << pos.y << "," << direction_string(toy_bot.direction());
        std::exit(0);
    } else if (command == "EXIT") {
        std::exit(0);
    } else {
        throw InvalidInputException("Invalid input: " + command);
    }

}

