//
// Created by Johan Ericsson on 2024-04-08.
//

#ifndef INC_213U8657863478129_TOY_BOT_HPP
#define INC_213U8657863478129_TOY_BOT_HPP

#include "grid.hpp"


class ToyBot {
public:
    ToyBot(int xmax, int ymax) : position_{-1, -1}, xmax(xmax), ymax(ymax) {}

    GridPoint position() const { return position_; }
    Direction direction() const { return direction_; };
    bool initialized() const { return initialized_; }

    void place(GridPoint position, Direction direction);
    void move();
    void rotate(RotationDirection rot_direction);
private:
    GridPoint position_;
    int xmax;
    int ymax;
    Direction direction_;
    bool initialized_ = false;
    bool valid_position(GridPoint pos) const;
};


#endif //INC_213U8657863478129_TOY_BOT_HPP
