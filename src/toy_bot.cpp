//
// Created by Johan Ericsson on 2024-04-08.
//

#include "toy_bot.hpp"


void ToyBot::place(GridPoint pos, Direction dir) {
    if (valid_position(pos)) {
        initialized_ = true;
        direction_ = dir;
        position_ = pos;
    }
}

void ToyBot::move() {
    if (!initialized_) return;

    GridPoint pos = position_;
    switch (direction_) {
        case Direction::north:
            pos.y += 1;
            break;
        case Direction::south:
            pos.y -= 1;
            break;
        case Direction::east:
            pos.x += 1;
            break;
        case Direction::west:
            pos.x -= 1;
            break;
    }
    if (valid_position(pos)) {
        position_ = pos;
    }
}

void ToyBot::rotate(RotationDirection rot_direction) {
    if (rot_direction == RotationDirection::left) {
        switch (direction_) {
            case Direction::north:
                direction_ = Direction::west;
                break;
            case Direction::south:
                direction_ = Direction::east;
                break;
            case Direction::east:
                direction_ = Direction::north;
                break;
            case Direction::west:
                direction_ = Direction::south;
                break;
        }
    } else {
        switch (direction_) {
            case Direction::north:
                direction_ = Direction::east;
                break;
            case Direction::south:
                direction_ = Direction::west;
                break;
            case Direction::east:
                direction_ = Direction::south;
                break;
            case Direction::west:
                direction_ = Direction::north;
                break;
        }
    }
}

bool ToyBot::valid_position(GridPoint pos) const {
    return (0 <= pos.x && pos.x < xmax && 0 <= pos.y && pos.y < ymax);
}





