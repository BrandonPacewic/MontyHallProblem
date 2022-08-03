// Copyright (c) Brandon Pacewic
// SPDX-License-Identifier: MIT

#include <iostream>

#include "monty_hall.hpp"

int main() {
    std::uint64_t number_of_games = 0;
    std::cout << "How many games would you like to play? ";
    std::cin >> number_of_games;

    std::uint64_t same_choice_wins = 0, change_choice_wins = 0;

    for (std::uint64_t i = 0; i < number_of_games; ++i) {
        const auto keep_outcome = monty_hall::keep_choice();
        const auto change_outcome = monty_hall::change_choice();

        if (keep_outcome) {
            ++same_choice_wins;
        }

        if (change_outcome) {
            ++change_choice_wins;
        }
    }

    std::cout << "The probability of winning if you change your choice is "
              << static_cast<double>(change_choice_wins) / number_of_games
              << std::endl;
    std::cout << "The probability of winning if you keep your choice is "
              << static_cast<double>(same_choice_wins) / number_of_games
              << std::endl;

    std::cout << "There where " << same_choice_wins
              << " wins if you keep your choice and " << change_choice_wins
              << " wins if you change your choice." << std::endl;

    return 0;
}