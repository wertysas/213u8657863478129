//
// Created by Johan Ericsson on 2024-04-08.
//

#define CATCH_CONFIG_WITH_MAIN

#include <catch2/catch_template_test_macros.hpp>
#include <string>
#include "toy_bot.hpp"


TEST_CASE("Initalize at valid positions", "[ToyBot]") {
    int N = 5;
    ToyBot toy_bot(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            GridPoint point = {i, j};
            toy_bot.place(point, Direction::north);
            REQUIRE(toy_bot.position() == point);
        }
    }
}

TEST_CASE("Don't initalize at invalid positions", "[ToyBot]") {
    int N = 5;
    ToyBot toy_bot(N, N);
    for (int i = -1*N; i <0; i++) {
        for (int j = -5; j < N; j++) {
            GridPoint point = {i, j};
            toy_bot.place(point, Direction::north);
            REQUIRE(toy_bot.initialized() == false);
        }
    }
    for (int i = N; i<2*N; i++) {
        for (int j = -1*N; j < N; j++) {
            GridPoint point = {i, j};
            toy_bot.place(point, Direction::north);
            REQUIRE(toy_bot.initialized() == false);
        }
    }
}


TEST_CASE("Rotation doesn't change position", "[ToyBot]") {
    int N = 5;
    ToyBot toy_bot(N, N);
    GridPoint point = {2,2};
    std::vector<Direction> directions = {Direction::north, Direction::south, Direction::west, Direction::east};
    for (auto dir: directions) {
        toy_bot.place(point, dir);
        toy_bot.rotate(RotationDirection::left);
        REQUIRE(toy_bot.position() == point);
        toy_bot.place(point, dir);
        toy_bot.rotate(RotationDirection::right);
    }
}

TEST_CASE("Rotation symmetries", "[ToyBot]") {
    int N = 5;
    ToyBot toy_bot(N, N);
    GridPoint point = {2,2};
    std::vector<Direction> directions = {Direction::north, Direction::south, Direction::west, Direction::east};
    for (auto dir: directions) {
        toy_bot.place(point, dir);
        for (int i=1; i<=4; i++) {
            for (int k=1; k<=i;k++) {
                toy_bot.rotate(RotationDirection::left);
            }
            for (int k=1; k<=i;k++) {
                toy_bot.rotate(RotationDirection::right);
            }
            REQUIRE(toy_bot.direction() == dir);
        }
    }
}


