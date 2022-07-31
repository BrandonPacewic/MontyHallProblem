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

constexpr uint8_t doors = 3;

auto random_door =
    std::bind(std::uniform_int_distribution<uint8_t>{0, doors - 1},
              std::default_random_engine{});

class MontyHall {
   public:
    [[nodiscard]] const bool is_win() const;

   protected:
    bool win;
};

[[nodiscard]] std::array<bool, doors> get_doors() {
    std::array<bool, doors> doors;
    doors.fill(false);
    srand(time(nullptr));
    doors[std::rand() % doors.size()] = true;

    return doors;
}

}  // namespace

class ChangeChoice : public MontyHall {
   public:
    ChangeChoice();
};

class KeepChoice : public MontyHall {
   public:
    KeepChoice();
};

[[nodiscard]] const bool MontyHall::is_win() const { return win; }

ChangeChoice::ChangeChoice() {
    const auto doors = get_doors();
    const auto choice = random_door();
    std::size_t revealed;

    std::for_each(doors.begin(), doors.end(),
                  [&](const auto& door, const auto& i) {
                      if (i == choice || door) {
                          return;
                      }

                      revealed = i;
                  });

    std::for_each(doors.begin(), doors.end(),
                  [&](const auto& door, const auto& i) {
                      if (i == revealed || i == choice) {
                          return;
                      }

                      win = door;
                  });
}

KeepChoice::KeepChoice() {
    const auto doors = get_doors();
    const auto choice = random_door();
    std::size_t revealed;

    // The solution to this problem becomes obvious when you realize that the
    // following code block does nothing in influencing the outcome.
    std::for_each(doors.begin(), doors.end(),
                  [&](const auto& door, const auto& i) {
                      if (i == choice || door) {
                          return;
                      }

                      revealed = i;
                  });

    win = doors[choice];
}

}  // namespace monty_hall

#endif  // MONTY_HALL_HPP_