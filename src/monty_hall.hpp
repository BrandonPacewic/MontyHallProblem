// Copyright (c) Brandon Pacewic
// SPDX-License-Identifier: MIT

#pragma once
#ifndef MONTY_HALL_HPP_
#define MONTY_HALL_HPP_

#include <algorithm>
#include <array>
#include <functional>
#include <random>

namespace monty_hall {
namespace {

constexpr uint8_t door_count = 3;

class Random_door {
   public:
    Random_door(int low, int high) : distribution{low, high} {}
    int operator()() { return distribution(engine); }

   private:
    std::uniform_int_distribution<> distribution;
    std::default_random_engine engine;
};

std::array<bool, door_count> get_doors() {
    std::array<bool, door_count> doors;
    std::fill(doors.begin(), doors.end(), false);

    Random_door random_door(0, doors.size());
    doors[random_door()] = true;

    return doors;
}

} // namespace

bool change_choice() {
    const auto doors = get_doors();

    Random_door random_door(0, doors.size());
    const auto choice = random_door();
    uint8_t revealed_door;

    // Reveal a losing door.
    for (std::size_t i = 0; i < doors.size(); ++i) {
        if (i == choice || doors[i]) {
            continue;
        }

        revealed_door = i;
    }
    
    // Change choice.
    bool win = false;

    for (std::size_t i = 0; i < doors.size(); ++i) {
        if (i == choice || i == revealed_door) {
            continue;
        }

        win = doors[i];
    }

    return win;
}

bool keep_choice() {
    const auto doors = get_doors();

    Random_door random_door(0, doors.size());
    const auto choice = random_door();
    uint8_t revealed_door;

    // Reveal a losing door.
    // The solution to this problem becomes clearer when you consider that
    // this step never changes the outcome.
    for (std::size_t i = 0; i < doors.size(); ++i) {
        if (i == choice || doors[i]) {
            continue;
        }

        revealed_door = i;
    }

    // Return our original choice.
    return doors[choice];
}

}  // namespace monty_hall

#endif  // MONTY_HALL_HPP_