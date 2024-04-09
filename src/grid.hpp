//
// Created by Johan Ericsson on 2024-04-08.
//

#ifndef TOYBOT_GRID_HPP
#define TOYBOT_GRID_HPP

#include <string>

enum class Direction {
    north,
    south,
    east,
    west,
};

enum class RotationDirection {
    left,
    right
};

struct GridPoint {
    int x;
    int y;

    bool operator==(const GridPoint &other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const GridPoint &other) const {
        return !(*this==other);
    }
};

#endif //TOYBOT_GRID_HPP
